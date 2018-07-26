#define mumu_cxx
#include "mumu.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TVector2.h>
#include <vector>
#include <TH1.h>

struct Lepton{
    TLorentzVector LV;
    float Iso;
};

void mumu::Loop()
{
//   In a ROOT session, you can do:
//      root> .L mumu.C
//      root> mumu t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   //Create root file with histograms
   TFile *output = new TFile("TT_DiMu_Histograms.root","recreate");

   //histograms
   TH1F *run_TT = new TH1F("run_TT","run; Total number of events passed through the pre-selection cut",3,0,3); run_TT->Sumw2();
   TH1F *leppT_TT = new TH1F("leppT_TT","lepton pt",100,0,500); leppT_TT->Sumw2();
   TH1F *lepeta_TT = new TH1F("lepeta_TT","lepton eta",20,-3,3); lepeta_TT->Sumw2();
   TH1F *lepphi_TT = new TH1F("lepphi_TT","lepton phi",20,-3.5,3.5); lepphi_TT->Sumw2();
   TH1F *lepIso_TT = new TH1F("lepIso_TT","lepton isolation",100,0,400); lepIso_TT->Sumw2();

   TH1F *dPhi_TT = new TH1F("dPhi_TT","delta phi_{e,#mu}",50,-4,4); dPhi_TT->Sumw2();
   TH1F *dR_TT = new TH1F("dR_TT","delta R_{e,#mu}",50,0,5); dR_TT->Sumw2();
   TH1F *mass_TT = new TH1F("mass_TT","Mass_{lep,lep}",50,0,500); mass_TT->Sumw2();

   TH1F *jetpT_TT = new TH1F("jetpT_TT","jet pT",100,0,500); jetpT_TT->Sumw2();
   TH1F *jeteta_TT = new TH1F("jeteta_TT","jet eta",20,-5,5); jeteta_TT->Sumw2();

   TH1F *bjetpT_TT = new TH1F("bjetpT_TT","b-jet pT",100,0,500); bjetpT_TT->Sumw2();
   TH1F *bjeteta_TT = new TH1F("bjeteta_TT","b-jet eta",20,-5,5); bjeteta_TT->Sumw2();

   TH1F *njet_TT = new TH1F("njet_TT","Number of jet",11,0,11); njet_TT->Sumw2();
   TH1F *nbjet_TT = new TH1F("nbjet_TT","Number of b-jet",11,0,11); nbjet_TT->Sumw2();
   TH1F *id_TT = new TH1F("id_TT","particle id",30,-15,15); id_TT->Sumw2();

   TH1F *MET_TT = new TH1F("MET_TT","Missing ET",100,0,1000); MET_TT->Sumw2();
   TH1F *dilep_mass_TT = new TH1F("dilep_mass_TT","dilepton mass",100,0,1000); dilep_mass_TT->Sumw2();

   TH1F *SBM_TT = new TH1F("SBM_TT","max(SBM)",100,0,300); SBM_TT->Sumw2();
   TH1F *METvsMmm_TT = new TH1F("METvsMmm_TT","E^{miss}_{T}/M(#mu^{+}#mu^{-})",100,0,1); METvsMmm_TT->Sumw2();
   TH1F *HTLT_TT = new TH1F("HTLT_TT","HT-LT",100,-500,500); HTLT_TT->Sumw2();

   TH1F *Mass_TT = new TH1F("Mass_TT","Lepton mass(M_{e})",100,0,500); Mass_TT->Sumw2();

   Long64_t nentries = fChain->GetEntriesFast();

   //totalN, Lumi -> Refer to see header file (.h)
   float cs = 76.7 * 1000;
   float weight = Lumi * cs/TT_totalN;

   Long64_t nbytes = 0, nb = 0;
   //Loop over all events
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
       Long64_t ientry = LoadTree(jentry);
       if (ientry < 0) break;
       nb = fChain->GetEntry(jentry);   nbytes += nb;
       // if (Cut(ientry) < 0) continue;

       run_TT->Fill(run);

       if(lep_pt[0] > 53 &&lep_pt[1] > 53){ //lep pT > 53GeV
           if(dil_dR > 0.1){ // dR(lep,lep) > 0.1
               if(fabs(lep_dz[0])<0.5 && fabs(lep_dz[1])<0.5){

                   //Opposite sign dilepton
                   if(lep_id[0] * lep_id[1] < 0){

                       //if(dil_chosen != 0) continue;
                       //particle id
                       int id1 = lep_id[0];
                       int id2 = lep_id[1];

                       id_TT->Fill(id1);
                       id_TT->Fill(id2);

                       const double muon_mass = 0.1056583715;

                       //Save leptons information
                       vector<TLorentzVector> leptons;
                       vector<Lepton> leptons_;
                       for(unsigned lep_N=0; lep_N<2; ++lep_N){
                           TLorentzVector lepton;
                           TLorentzVector lepton_;
                           lepton.SetPtEtaPhiM(lep_pt[lep_N],lep_eta[lep_N],lep_phi[lep_N],muon_mass);
                           lepton_.SetPtEtaPhiM(lep_pt[lep_N],lep_eta[lep_N],lep_phi[lep_N],muon_mass);
                           leptons.push_back(lepton);
                           Lepton dummy = {lepton_, lep_pfIso[lep_N]};
                           leptons_.push_back(dummy);
                       }  // example(1): float FirstLeptonMass = leptons[0].M();
                       ///// example(2): float FirstLeptonIso = leptons_[0].Iso;

                       float Dil_dPhi[1] = {-999};
                       float Dil_dR[1] = {-999};
                       float Dil_mass[1] = {-999};

                       float MET[1] = {-999};

                       int Njet = 0;
                       int Nbjet = 0;

                       vector<TLorentzVector> Jets;
                       vector<TLorentzVector> bJets;

                       for(int NJ=0; NJ<nJets; NJ++){
                           if(jet_pt[NJ] > 30){ //jet pT > 30GeV
                               if(fabs(jet_eta[NJ]) < 5.0){ // jet |eta| <5.0

                                   //di-lepton information (delta-Phi, delta-R, dilepton mass)
                                   Dil_dPhi[0] = dil_dPhi;
                                   Dil_dR[0] = dil_dR;
                                   Dil_mass[0] = dil_mass;

                                   //Missing ET
                                   MET[0] = met_pt;

                                   //Save jet information 
                                   TLorentzVector Jet;
                                   Jet.SetPtEtaPhiE(jet_pt[NJ],jet_eta[NJ],jet_phi[NJ],jet_E[NJ]);
                                   Jets.push_back(Jet);

                                   //Number of jet
                                   Njet ++;

                                   if(jet_btag[NJ] >= 0.8484) { //b-tagging(WP=0.8484)
                                       //Save b-jet information
                                       TLorentzVector bJet;
                                       bJet.SetPtEtaPhiE(jet_pt[NJ],jet_eta[NJ],jet_phi[NJ],jet_E[NJ]);
                                       bJets.push_back(bJet);

                                       //Number of b-jet
                                       Nbjet ++;
                                   }
                               }
                           }
                       }

                       njet_TT->Fill(Njet);
                       if(Njet < 2) continue;//Number of jet >=2
                       
                       nbjet_TT->Fill(Nbjet);
                       if(Nbjet < 1) continue;// >= 1 b-jet

                       //pT
                       leppT_TT->Fill(leptons[0].Pt());
                       leppT_TT->Fill(leptons[1].Pt());

                       //eta
                       lepeta_TT->Fill(leptons[0].Eta());
                       lepeta_TT->Fill(leptons[1].Eta());

                       //phi
                       lepphi_TT->Fill(leptons[0].Phi());
                       lepphi_TT->Fill(leptons[1].Phi());

                       //Iso
                       lepIso_TT->Fill(leptons_[0].Iso);
                       lepIso_TT->Fill(leptons_[1].Iso);

                       //lep-lep dPhi and dR, dilep mass
                       dPhi_TT->Fill(Dil_dPhi[0]);
                       dR_TT->Fill(Dil_dR[0]);
                       mass_TT->Fill(Dil_mass[0]);

                       //Jet1_nonB: Non-bjet with the largest pT
                       //Jet2_nonB: Non-bjet with the second largest pT
                       int Jet1_nonB=-1;
                       int Jet2_nonB=-1;
                       float Jet1_nonB_PT=0.;
                       float Jet2_nonB_PT=0.;

                       //Jet1_B: b-jet with the largest pT
                       //Jet2_B: b-jet with the second largest pT
                       int Jet1_B=-1;
                       int Jet2_B=-1;
                       float Jet1_B_PT=0.;
                       float Jet2_B_PT=0.;

                       if(Nbjet == 0){
                           for(unsigned Nj=0; Nj<Jets.size(); ++Nj){
                               if(Jet1_nonB_PT<Jets[Nj].Pt()){
                                   Jet1_nonB=Nj;
                                   Jet1_nonB_PT=Jets[Nj].Pt();
                               }
                               if(Jet2_nonB_PT < Jets[Nj].Pt() && Jet1_nonB_PT > Jets[Nj].Pt()){
                                   Jet2_nonB = Nj;
                                   Jet2_nonB_PT=Jets[Nj].Pt();
                               }
                           }
                       }

                       else if(Nbjet == 1){
                           for(unsigned Nj=0; Nj<Jets.size(); ++Nj){
                               if(Jet2_nonB_PT<Jets[Nj].Pt()){
                                   if(Jet2_nonB_PT != bJets[0].Pt()){
                                       Jet2_nonB=Nj;
                                       Jet2_nonB_PT=jet_pt[Nj];
                                   }
                               }
                           }
                       }
                       else if(Nbjet > 1){
                           for(unsigned Nbj=0; Nbj<bJets.size(); ++Nbj){
                               if(Jet1_B_PT < bJets[Nbj].Pt()){
                                   Jet1_B=Nbj;
                                   Jet1_B_PT=bJets[Nbj].Pt();
                               }
                               if(Jet2_B_PT < bJets[Nbj].Pt() && Jet1_B_PT > bJets[Nbj].Pt()){
                                   Jet2_B = Nbj;
                                   Jet2_B_PT = bJets[Nbj].Pt();
                               }
                           }
                       }

                       TLorentzVector met_p4;

                       float lep1_jet1_mass;
                       float lep1_jet2_mass;
                       float lep2_jet1_mass;
                       float lep2_jet2_mass;

                       if(Nbjet == 0){
                           lep1_jet1_mass = ((leptons[1])+(Jets[Jet1_nonB])).M();
                           lep1_jet2_mass = ((leptons[1])+(Jets[Jet2_nonB])).M();
                           lep2_jet1_mass = ((leptons[2])+(Jets[Jet1_nonB])).M();
                           lep2_jet2_mass = ((leptons[2])+(Jets[Jet2_nonB])).M();
                       }

                       else if(Nbjet == 1){
                           lep1_jet1_mass = ((leptons[1])+(bJets[0])).M();
                           lep1_jet2_mass = ((leptons[1])+(Jets[Jet2_nonB])).M();
                           lep2_jet1_mass = ((leptons[2])+(bJets[0])).M();
                           lep2_jet2_mass = ((leptons[2])+(Jets[Jet2_nonB])).M();
                       }

                       else if(Nbjet > 1){
                           lep1_jet1_mass = ((leptons[1])+(bJets[Jet1_B])).M();
                           lep1_jet2_mass = ((leptons[1])+(bJets[Jet2_B])).M();
                           lep2_jet1_mass = ((leptons[2])+(bJets[Jet1_B])).M();
                           lep2_jet2_mass = ((leptons[2])+(bJets[Jet2_B])).M();
                       }

                       //SBM calculation
                       float SBM1 = 0.;
                       float SBM2 = 0.;
                       if(abs(lep1_jet1_mass - lep2_jet2_mass) < abs(lep2_jet1_mass - lep1_jet2_mass)){
                           SBM1 = lep1_jet1_mass;
                           SBM2 = lep2_jet2_mass;
                       }
                       else{
                           SBM1 = lep2_jet1_mass;
                           SBM2 = lep1_jet2_mass;
                       }

                       //Fill max SBM (Top mass bound)
                       //if(SBM1>170. || SBM2>170.){//>170 cut
                       if(SBM1<SBM2)SBM_TT->Fill(SBM2,weight);
                       else SBM_TT->Fill(SBM1,weight);

                       //METvsMmm (Normalized MET)
                       float Mmm = ((leptons[0])+(leptons[1])).M();
                       float MET_t = MET[0];
                       float METvsMmm = MET_t/Mmm ;
                       //if(METvsMmm<0.2){ // <0.2 cut
                       METvsMmm_TT->Fill(METvsMmm,weight);
                       MET_TT->Fill(MET_t);
                       dilep_mass_TT->Fill(Mmm);

                       //(HT-LT) calculation
                       float DHTLT = -999.;
                       if(Nbjet > 1){
                           DHTLT = (Jet1_B_PT+Jet2_B_PT) - (leptons[0].Pt()+leptons[1].Pt());
                       }
                       else if(Nbjet == 1){
                           DHTLT = (bJets[0].Pt()+Jet2_nonB_PT) - (leptons[0].Pt()+leptons[1].Pt());
                       }
                       else if(Nbjet == 0){
                           DHTLT = (Jet1_nonB_PT+Jet2_nonB_PT) - (leptons[0].Pt()+leptons[1].Pt());
                       }

                       //if(DHTLT<0){//<0 cut
                       HTLT_TT->Fill(DHTLT,weight);
                       //}
                       //}
                       //}
                       float Mm_1 = (leptons[0]).M();
                       float Mm_2 = (leptons[1]).M();
                       Mass_TT->Fill(Mm_1);
                       Mass_TT->Fill(Mm_2);
                       //          }
                   }
                   }
               }
           }
       }

       //(*) I tried to apply the code you gave me, but I got the following error:
       //error: no matching constructor for initialization of 'vector<TH1F *>'
       /*
          vector<TH1F *> hists = {run_TT, leppT_TT, elepT_TT, mupT_TT, lepeta_TT, eleEta_TT, muEta_TT, lepphi_TT, elePhi_TT, muPhi_TT, dPhi_TT, dR_TT, mass_TT, eleIso_TT, muIso_TT, jetpT_TT, jeteta_TT, bjetpT_TT, bjeteta_TT, njet_TT, nbjet_TT, id_TT, MET_TT, dilep_mass_TT, SBM_TT, METvsMmm_TT, HTLT_TT, Mass_TT};

          for(unsigned Nh=0; Nh<hists.size(); ++Nh) hists[Nh]->Write();
          */

       run_TT->Write();

       leppT_TT->Write();
       elepT_TT->Write();
       mupT_TT->Write();

       lepeta_TT->Write();
       eleEta_TT->Write();
       muEta_TT->Write();

       lepphi_TT->Write();
       elePhi_TT->Write();
       muPhi_TT->Write();

       dPhi_TT->Write();
       dR_TT->Write();
       mass_TT->Write();

       eleIso_TT->Write();
       muIso_TT->Write();

       jetpT_TT->Write();
       jeteta_TT->Write();

       bjetpT_TT->Write();
       bjeteta_TT->Write();

       njet_TT->Write();
       nbjet_TT->Write();
       id_TT->Write();

       MET_TT->Write();
       dilep_mass_TT->Write();

       SBM_TT->Write();
       METvsMmm_TT->Write();
       HTLT_TT->Write();

       Mass_TT->Write();

       output->Close();
   }
