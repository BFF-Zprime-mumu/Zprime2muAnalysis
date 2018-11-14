#define mumu_cxx
#include "mumu.h"
#include <TStyle.h>
#include <TCanvas.h>
#include <vector>
#include <TLorentzVector.h>
#include <iostream>
#include <TVector2.h>

struct Lepton{
    TLorentzVector LV;
    float Iso;
};

void BinLogX(TH1*h) 
{

   TAxis *axis = h->GetXaxis(); 
   int bins = axis->GetNbins();

   Axis_t from = axis->GetXmin();
   Axis_t to = axis->GetXmax();
   Axis_t width = (to - from) / bins;
   Axis_t *new_bins = new Axis_t[bins + 1];

   for (int i = 0; i <= bins; i++) {
     new_bins[i] = TMath::Power(10, from + i * width);
   } 
   axis->Set(bins, new_bins); 
   delete new_bins; 
}

float calculateHTLT(vector<TLorentzVector> bJets, vector<TLorentzVector> non_bJets, vector<TLorentzVector> leptons)
{
    //(HT-LT) calculation
    float DHTLT = -999.;
    //check leptons collection size, throw a warning if it is less than 2
    if (leptons.size()<2) { std::cout << "HTLT computation: WARNING! Lepton collection size is less than 2!!!" << std::endl; return DHTLT;}
    //sort leptons collection
    std::sort(leptons.begin(), leptons.end(), [](TLorentzVector a, TLorentzVector b){return a.Pt() > b.Pt();});

    if(bJets.size() == 1){
        if (non_bJets.size() == 0){
            DHTLT = (bJets[0].Pt()) - (leptons[0].Pt()+leptons[1].Pt());
        } else {
            std::sort(non_bJets.begin(), non_bJets.end(), [](TLorentzVector a, TLorentzVector b){return a.Pt() > b.Pt();});
            DHTLT = (bJets[0].Pt()+non_bJets[0].Pt()) - (leptons[0].Pt()+leptons[1].Pt());
        }
    } else {
        if (bJets.size()>1){ 
            std::sort(bJets.begin(), bJets.end(), [](TLorentzVector a, TLorentzVector b){return a.Pt() > b.Pt();});
            DHTLT = (bJets[0].Pt()+bJets[1].Pt()) - (leptons[0].Pt()+leptons[1].Pt());
        } else {
            float HT = 0;
            const int n_non_b_jets = non_bJets.size();
            for (int i = 0; i < std::max(2,n_non_b_jets); ++i) HT+=non_bJets[i].Pt();//Sum hadronic activity of first N leading jets where N<=2
            DHTLT = HT - (leptons[0].Pt()+leptons[1].Pt());
        }
    }
    return DHTLT;
};

float * calculateSBM(float aSBM[], vector<TLorentzVector> allJets, vector<TLorentzVector> leptons)
{
    //lepton-jet pair mass and SBM definition
    float lep1_jet1_mass;
    float lep1_jet2_mass;
    float lep2_jet1_mass;
    float lep2_jet2_mass;
    
    float SBM1 = 0.;
    float SBM2 = 0.;
    float SBMMin =-1;
    float SBMMax =-1;
    float SBM = -1;
    float SBMsecond = -1;

    if(allJets.size()== 1){
        SBM1 = ((leptons[0])+(allJets[0])).M();
        SBM2 = ((leptons[1])+(allJets[0])).M();
    
        SBM=min(SBM1,SBM2);
        SBMMin=min(SBM1,SBM2);
        SBMMax=max(SBM1,SBM2);
    
    } else if (allJets.size() == 2){
        lep1_jet1_mass = ((leptons[0])+(allJets[0])).M();
        lep1_jet2_mass = ((leptons[0])+(allJets[1])).M();
        lep2_jet1_mass = ((leptons[1])+(allJets[0])).M();
        lep2_jet2_mass = ((leptons[1])+(allJets[1])).M();
        if(abs(lep1_jet1_mass - lep2_jet2_mass) < abs(lep2_jet1_mass - lep1_jet2_mass)){
            SBM=max(lep1_jet1_mass,lep2_jet2_mass);
            SBMMin=min(lep1_jet1_mass,lep2_jet2_mass);
            SBMMax=max(lep1_jet1_mass,lep2_jet2_mass);
        }
        else{
            SBM=max(lep2_jet1_mass,lep1_jet2_mass);
            SBMMin=min(lep2_jet1_mass,lep1_jet2_mass);
            SBMMax=max(lep2_jet1_mass,lep1_jet2_mass);
        }
    }
    aSBM[0] =  SBM;
    aSBM[1] =  SBMMin;
    aSBM[2] =  SBMMax;
    return aSBM;
}

std::vector<float> mumu::Loop(TString sample_name, Float_t xsection, Float_t targetLumi, Float_t numberOfEvents, TString caseText)
{

//   In a ROOT session, you can do:
//      root> .L mumu.C
//      root> mumu t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop("sample name");       // Loop on all entries
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

    std::vector<float> cutFlow = {0,0,0,0,0,0,0};
    
    if (fChain == 0) return cutFlow;
    
    //Create root file with histograms
    TFile *output = new TFile(sample_name,"recreate");

    histogramClass histClass("");
    
    Long64_t nentries = fChain->GetEntriesFast();
    //cs, totalN, Lumi -> Refer to see header file (.h)
    float weight = targetLumi * xsection/numberOfEvents;
    std::cout << "sample_name "<< sample_name << std::endl;
    int count=0;
    Long64_t nbytes = 0, nb = 0;
    //Loop over all events
    for (Long64_t jentry=0; jentry<nentries;jentry++) {
       Long64_t ientry = LoadTree(jentry);
       if (ientry < 0) break;
       nb = fChain->GetEntry(jentry);   nbytes += nb;
       // if (Cut(ientry) < 0) continue;

       histClass.run_hist->Fill(run);

       cutFlow.at(0) += weight;

       if(lep_pt[0] > 53 &&lep_pt[1] > 53){ //lep pT > 53GeV
           if(dil_dR > 0.1){ // dR(lep,lep) > 0.1
               if(fabs(lep_dz[0])<0.5 && fabs(lep_dz[1])<0.5){

                    cutFlow.at(1) = cutFlow.at(1) + weight;
                   //Opposite sign dilepton
                   if(lep_id[0] * lep_id[1] < 0){

                    cutFlow.at(2) += weight;

                       //if(dil_chosen != 0) continue;
                       //particle id
                       int id1 = lep_id[0];
                       int id2 = lep_id[1];

                       histClass.id_hist->Fill(id1);
                       histClass.id_hist->Fill(id2);

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
                       
                       vector<TLorentzVector> bJets;
                       vector<TLorentzVector> non_bJets;

                       vector<TLorentzVector> allJets;

                       for(int NJ=0; NJ<nJets; NJ++){
                           if(jet_pt[NJ] > 20){ //jet pT > 20GeV
                               if(fabs(jet_eta[NJ]) < 5.0){ // jet |eta| <5.0
                                   //All jet pT and eta
                                   histClass.jetpT_hist->Fill(jet_pt[NJ]);
                                   histClass.jeteta_hist->Fill(jet_eta[NJ]);

                                   if(jet_btag[NJ] >= 0.8484) { //b-tagging(WP=0.8484)
                                       //b-jet pT and eta
                                       histClass.bjetpT_hist->Fill(jet_pt[NJ]);
                                       histClass.bjeteta_hist->Fill(jet_eta[NJ]);
                                       //Save b-jet information
                                       TLorentzVector bJet;
                                       bJet.SetPtEtaPhiE(jet_pt[NJ],jet_eta[NJ],jet_phi[NJ],jet_E[NJ]);
                                       bJets.push_back(bJet);
                                       allJets.push_back(bJet);
                                   }

                                   else if(jet_pt[NJ] > 30){//non_bjet pT > 30
                                       //non b-jet pT and eta
                                       histClass.NonbjetpT_hist->Fill(jet_pt[NJ]);
                                       histClass.Nonbjeteta_hist->Fill(jet_eta[NJ]);
                                       //Save non b-jet information
                                       TLorentzVector non_bJet;
                                       non_bJet.SetPtEtaPhiE(jet_pt[NJ],jet_eta[NJ],jet_phi[NJ],jet_E[NJ]);
                                       non_bJets.push_back(non_bJet);
                                       allJets.push_back(non_bJet);

                                   }
                               }
                           }
                       }// b jet pT > 20 GeV , non-b jet pT > 30 GeV

                       histClass.nNonbjet_hist->Fill(non_bJets.size());
                       histClass.njvsnbj_hist->Fill(non_bJets.size(),bJets.size());
                       histClass.nbjet_hist->Fill(bJets.size());

                       int nBjets = bJets.size();
                       int nNonBjets = non_bJets.size();
                       int njets = bJets.size()+ non_bJets.size();

                       //Case 1 = Case 3 + Case 4 + Case 5
                       if(caseText == "1" and (nBjets < 1 || njets < 2) )continue;//N_jet >= 2, N_bjets >= 1 (Case 1)
                       //if(caseText == "na" and (nBjets < 1 || non_bJets < 2) )continue;//N_bjet >= 1, N_jet >= 2
                       if(caseText == "2" and (nBjets != 1 || nNonBjets != 0) )continue;//N_jet = 1, N_bjet = 1 (Case 2)
                       //if(caseText == "3" and (nBjets < 1 || njets == 2) )continue;//N_jet = 2, N_bjet >=1(1or2) (Case 3)
                       if(caseText == "3" and not (nBjets >= 1 && njets == 2) )continue;//N_jet = 2, N_bjet >=1(1or2) (Case 3)
                       if(caseText == "4" and (nBjets < 1 || nBjets > 2 || njets < 3) )continue;//N_jet >= 3, N_bjets = 1or2 (Case 4)
                       if(caseText == "5" and (nBjets < 3) )continue;//N_jet >=3, N_bjet >= 3 (Case 5)

                       //SR 1j
                       if(caseText == "b1j0" and not (nBjets == 1 && nNonBjets == 0) )continue;
                       //CR 1j
                       if(caseText == "b0j1" and not (nBjets == 0 && nNonBjets == 1) )continue;

                       //SR 2 j
                       if(caseText == "b12bj2" and not ( nBjets >=1 && njets == 2) )continue;
                       //CR 1 j
                       if(caseText == "b0bj2" and not ( nBjets == 0  && njets == 2) )continue;

                       //1j
                       if(caseText == "1j" and not (njets == 1) )continue;

                       cutFlow.at(3) = cutFlow.at(3) + weight;

                       float DHTLT = calculateHTLT(bJets, non_bJets, leptons);

                       //METvsMmm (Normalized MET)
                       float Mmm = ((leptons[0])+(leptons[1])).M();
                       float MET_t = met_pt;
                       float METvsMmm = MET_t/Mmm ;

                       float aSBM[3]= {-1, -1, -1};
                       calculateSBM(aSBM, allJets, leptons);
                       float SBMMin =aSBM[1];
                       float SBMMax =aSBM[2];
                       float SBM = aSBM[0];

                       histClass.METvsMmm_hist->Fill(METvsMmm,weight);
                       histClass.mini_SBM_hist->Fill(SBMMin,weight);
                       histClass.SBM_hist->Fill(SBMMax,weight);
                       histClass.HTLT_hist->Fill(DHTLT,weight);

                       if(caseText == "b1j0" || caseText ==  "2" || caseText ==  "b0j1")
                       {
                           //(HT-LT) cut
                           if(DHTLT > -120)continue;
                           cutFlow.at(4) += weight;
                           //METvsMmm (Normalized MET) cut
                           if(METvsMmm > .25)continue;
                           cutFlow.at(5) += weight;
                           //TMB cut
                           if (SBM < 160) continue;
                           cutFlow.at(6) += weight;
                       } else if (caseText == "b12bj2" || caseText ==  "b0bj2")
                       {
                           //(HT-LT) cut
                           if(DHTLT > -80)continue;
                           cutFlow.at(4) += weight;
                           //METvsMmm (Normalized MET) cut
                           if(METvsMmm > .3)continue;
                           cutFlow.at(5) += weight;
                           //TMB cut
                           if (SBM < 150) continue;
                           cutFlow.at(6) += weight;
                       } else{
                           std::cout << "WARNING: Selection not recognized, continuing"<< std::endl;
                           continue;
                       }
                       count++;
                       //pT
                       histClass.leppT_hist->Fill(leptons[0].Pt());
                       histClass.leppT_hist->Fill(leptons[1].Pt());
                       //eta
                       histClass.lepeta_hist->Fill(leptons[0].Eta());
                       histClass.lepeta_hist->Fill(leptons[1].Eta());
                       //phi
                       histClass.lepphi_hist->Fill(leptons[0].Phi());
                       histClass.lepphi_hist->Fill(leptons[1].Phi());
                       //Iso
                       histClass.lepIso_hist->Fill(leptons_[0].Iso);
                       histClass.lepIso_hist->Fill(leptons_[1].Iso);
                       //lep-lep dPhi and dR, dilep mass
                       histClass.dPhi_dimuon_hist->Fill(dil_dPhi);
                       histClass.dR_hist->Fill(dil_dR);
                       histClass.mass_hist->Fill(dil_mass);
                       //dPhi(dimuon,b) calculation
                       if(bJets.size()==1){
                           float Phi_dimuon = (leptons[0] + leptons[1]).Phi();
                           float Phi_b = bJets[0].Phi();
                           float dPhi_dimu_b = Phi_dimuon - Phi_b;
                           if(dPhi_dimu_b >= TMath::Pi()) dPhi_dimu_b -= 2.*TMath::Pi();
                           if(dPhi_dimu_b < -TMath::Pi()) dPhi_dimu_b += 2.*TMath::Pi();
                           histClass.dPhi_hist->Fill(dPhi_dimu_b,weight);
                       }

                       histClass.MET_hist->Fill(MET_t);
                       histClass.dilep_mass_hist->Fill(Mmm, weight);

                       float Mm_1 = (leptons[0]).M();
                       float Mm_2 = (leptons[1]).M();
                       histClass.Mass_hist->Fill(Mm_1);
                       histClass.Mass_hist->Fill(Mm_2);
                   }
               }
           }
       }
    } 
    std::cout << "count*weigth " << count*weight << std::endl;

    std::vector<TH1F *> hists = {histClass.run_hist, histClass.mini_SBM_hist, histClass.mini_SBM_minus173_hist, histClass.leppT_hist, histClass.lepeta_hist, histClass.lepphi_hist, histClass.dPhi_dimuon_hist, histClass.dPhi_hist, histClass.dR_hist, histClass.mass_hist, histClass.jetpT_hist, histClass.jeteta_hist, histClass.bjetpT_hist, histClass.bjeteta_hist, histClass.NonbjetpT_hist, histClass.Nonbjeteta_hist, histClass.nbjet_hist, histClass.nNonbjet_hist, histClass.id_hist, histClass.MET_hist, histClass.dilep_mass_hist, histClass.SBM_hist, histClass.METvsMmm_hist, histClass.HTLT_hist, histClass.Mass_hist};

    for(unsigned Nh=0; Nh<hists.size(); ++Nh) hists[Nh]->Write();
    histClass.njvsnbj_hist->Write();

    output->Close();
    return cutFlow;
}
