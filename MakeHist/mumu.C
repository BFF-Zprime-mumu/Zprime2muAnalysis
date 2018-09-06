#define mumu_cxx
#include "mumu.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TVector2.h>
#include <vector>
#include <TH1.h>
#include <TLorentzVector.h>

struct Lepton{
    TLorentzVector LV;
    float Iso;
};


void mumu::Loop(TString sample_name)
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
   TFile *output = new TFile(sample_name+"_DiMu_Nobjet_Histograms.root","recreate");

   
   //histograms
   TH1F *run_hist = new TH1F("run_hist","Total number of events passed through the pre-selection cut; run; Number of events;",3,0,3); run_hist->Sumw2();
   TH1F *leppT_hist = new TH1F("leppT_hist","lepton pt; p_{T} [GeV]; Number of events",100,0,500); leppT_hist->Sumw2();
   TH1F *lepeta_hist = new TH1F("lepeta_hist","lepton eta; #eta; Number of events",20,-3,3); lepeta_hist->Sumw2();
   TH1F *lepphi_hist = new TH1F("lepphi_hist","lepton phi; #phi; Number of events",20,-3.5,3.5); lepphi_hist->Sumw2();
   TH1F *lepIso_hist = new TH1F("lepIso_hist","lepton isolation; Isolation; Number of events;",100,0,400); lepIso_hist->Sumw2();

   TH1F *dPhi_hist = new TH1F("dPhi_hist","delta phi_{#mu,#mu}; #Delta#phi_{#mu,#mu}; Number of events",50,-4,4); dPhi_hist->Sumw2();
   TH1F *dR_hist = new TH1F("dR_hist","delta R_{#mu,#mu}; #DeltaR_{#mu,#mu}; Number of events",50,0,5); dR_hist->Sumw2();
   TH1F *mass_hist = new TH1F("mass_hist","Dilepton mass tree; Dilepton mass; Number of events",50,0,500); mass_hist->Sumw2();

   TH1F *jetpT_hist = new TH1F("jetpT_hist","jet pT; p_{T} [GeV]; Number of events",100,0,500); jetpT_hist->Sumw2();
   TH1F *jeteta_hist = new TH1F("jeteta_hist","jet eta; #eta; Number of events",20,-5,5); jeteta_hist->Sumw2();

   TH1F *bjetpT_hist = new TH1F("bjetpT_hist","b-jet pT; p_{T} [GeV]; Number of Evets",100,0,500); bjetpT_hist->Sumw2();
   TH1F *bjeteta_hist = new TH1F("bjeteta_hist","b-jet eta; #eta; Number of events",20,-5,5); bjeteta_hist->Sumw2();

   TH1F *njet_hist = new TH1F("njet_hist","Number of jet; Number of jets; Number of events",11,0,11); njet_hist->Sumw2();
   TH1F *nbjet_hist = new TH1F("nbjet_hist","Number of b-jet; Number of b-jets; Number of events",11,0,11); nbjet_hist->Sumw2();
   TH1F *id_hist = new TH1F("id_hist","particle id; id number; Number of events",30,-15,15); id_hist->Sumw2();

   TH1F *MET_hist = new TH1F("MET_hist","Missing ET; E^{miss}_{T} [GeV]; Number ofe events",100,0,1000); MET_hist->Sumw2();
   TH1F *dilep_mass_hist = new TH1F("dilep_mass_hist","dilepton mass; Mass_{#mu,#mu} [GeV]; Number of events",100,0,1000); dilep_mass_hist->Sumw2();

   TH1F *SBM_hist = new TH1F("SBM_hist","max(SBM); max(SBM); a.u.",100,0,300); SBM_hist->Sumw2();
   TH1F *METvsMmm_hist = new TH1F("METvsMmm_hist","E^{miss}_{T}/M(#mu^{+}#mu^{-}); E^{miss}_{T}/M(#mu^{+}#mu^{-}) [GeV]; a.u.",100,0,1); METvsMmm_hist->Sumw2();
   TH1F *HTLT_hist = new TH1F("HTLT_hist","HT-LT; HT-LT [GeV]; a.u.",100,-500,500); HTLT_hist->Sumw2();

   TH1F *Mass_hist = new TH1F("Mass_hist","Lepton mass(M_{#mu}); M_{#mu} [GeV]; Number of events",100,0,500); Mass_hist->Sumw2();

   
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

       run_hist->Fill(run);


       if(lep_pt[0] > 53 &&lep_pt[1] > 53){ //lep pT > 53GeV
           if(dil_dR > 0.1){ // dR(lep,lep) > 0.1
               if(fabs(lep_dz[0])<0.5 && fabs(lep_dz[1])<0.5){

                   //Opposite sign dilepton
                   if(lep_id[0] * lep_id[1] < 0){

                       //if(dil_chosen != 0) continue;
                       //particle id
                       int id1 = lep_id[0];
                       int id2 = lep_id[1];

                       id_hist->Fill(id1);
                       id_hist->Fill(id2);

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
                           if(jet_pt[NJ] > 30){ //jet pT > 20GeV
                               if(fabs(jet_eta[NJ]) < 5.0){ // jet |eta| <5.0

                                   //di-lepton information (delta-Phi, delta-R, dilepton mass)
                                   Dil_dPhi[0] = dil_dPhi;
                                   Dil_dR[0] = dil_dR;
                                   Dil_mass[0] = dil_mass;

                                   //Missing ET
                                   MET[0] = met_pt;

                                   //Save all jet information 

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
                       }// b jet pT > 20 GeV , non-b jet pT > 30 GeV

                       njet_hist->Fill(Njet);
                       if(Njet < 2) continue;//Number of jet >=2
                       
                       nbjet_hist->Fill(Nbjet);
                       if(Nbjet < 1) continue;// >= 1 b-jet

                       //pT
                       leppT_hist->Fill(leptons[0].Pt());
                       leppT_hist->Fill(leptons[1].Pt());

                       //eta
                       lepeta_hist->Fill(leptons[0].Eta());
                       lepeta_hist->Fill(leptons[1].Eta());

                       //phi
                       lepphi_hist->Fill(leptons[0].Phi());
                       lepphi_hist->Fill(leptons[1].Phi());

                       //Iso
                       lepIso_hist->Fill(leptons_[0].Iso);
                       lepIso_hist->Fill(leptons_[1].Iso);

                       //lep-lep dPhi and dR, dilep mass
                       dPhi_hist->Fill(Dil_dPhi[0]);
                       dR_hist->Fill(Dil_dR[0]);
                       mass_hist->Fill(Dil_mass[0]);

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
                       float All_bjet_PT=0.;

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
                               All_bjet_PT += bJets[Nbj].Pt();
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
                       if(SBM1<SBM2)SBM_hist->Fill(SBM2,weight);
                       else SBM_hist->Fill(SBM1,weight);

                       //METvsMmm (Normalized MET)
                       float Mmm = ((leptons[0])+(leptons[1])).M();
                       float MET_t = MET[0];
                       float METvsMmm = MET_t/Mmm ;
                       //if(METvsMmm<0.2){ // <0.2 cut
                       METvsMmm_hist->Fill(METvsMmm,weight);
                       MET_hist->Fill(MET_t);
                       dilep_mass_hist->Fill(Mmm);

                       //(HT-LT) calculation
                       float DHTLT = -999.;
                       if(Nbjet > 1){
                           DHTLT = (Jet1_B_PT+Jet2_B_PT) - (leptons[0].Pt()+leptons[1].Pt());
                           //DHTLT = (All_bjet_PT) - (leptons[0].Pt()+leptons[1].Pt());
                       }
                       else if(Nbjet == 1){
                           DHTLT = (bJets[0].Pt()+Jet2_nonB_PT) - (leptons[0].Pt()+leptons[1].Pt());
                       }
                       else if(Nbjet == 0){
                           DHTLT = (Jet1_nonB_PT+Jet2_nonB_PT) - (leptons[0].Pt()+leptons[1].Pt());
                       }

                       //if(DHTLT<0){//<0 cut
                       HTLT_hist->Fill(DHTLT,weight);
                       //}
                       //}
                       //}
                       float Mm_1 = (leptons[0]).M();
                       float Mm_2 = (leptons[1]).M();
                       Mass_hist->Fill(Mm_1);
                       Mass_hist->Fill(Mm_2);
                       //          }
                   }
                   }
               }
           }
       }


std::vector<TH1F *> hists = {run_hist, leppT_hist, lepeta_hist, lepphi_hist, dPhi_hist, dR_hist, mass_hist, jetpT_hist, jeteta_hist, bjetpT_hist, bjeteta_hist, njet_hist, nbjet_hist, id_hist, MET_hist, dilep_mass_hist, SBM_hist, METvsMmm_hist, HTLT_hist, Mass_hist};

    for(unsigned Nh=0; Nh<hists.size(); ++Nh) hists[Nh]->Write();

    output->Close();
   }
