#define mumu_cxx
#include "mumu.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TVector2.h>
#include <vector>
#include <TH1.h>
#include <TLorentzVector.h>
#include <iostream>

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

/*Float_t * returnLogArray(Float_t minEdge, Float_t maxEdge, Int_t nBins) 
{

  Float_t width = (maxEdge - minEdge) / nBins;
  static Float_t bins[nBins + 1];

  for (int i = 0; i <= bins; i++) {
    bins[i] = TMath::Power(10, from + i * width);
    std::cout << TMath::Power(10, from + i * width) <<std::endl;
  } 
 
  return bins;
}*/



float calculateHTLT(vector<TLorentzVector> bJets, vector<TLorentzVector> non_bJets, vector<TLorentzVector> leptons)
{
   int nBjets = bJets.size();
   int nNonBjets = non_bJets.size();
   int njets = bJets.size()+ non_bJets.size();
    //(HT-LT) calculation
    float DHTLT = -999.;
    //check leptons collection size, throw a warning if it is less than 2
    if (leptons.size()<2) { std::cout << "HTLT computation: WARNING! Lepton collection size is less than 2!!!" << std::endl; return DHTLT;}
    //if (non_bJets.size() + bJets.size() <1) { std::cout << "HTLT computation: WARNING! Jet collection size is less than 1!!!" << std::endl;}
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
            for (int i = 0; i < std::min(2,n_non_b_jets); ++i) HT+=non_bJets[i].Pt();//Sum hadronic activity of first N leading jets where N<=2
            DHTLT = HT - (leptons[0].Pt()+leptons[1].Pt());
        }
    }

   /*//(HT-LT) calculation
   if(bJets.size() == 1 && non_bJets.size() == 0){
       DHTLT = (bJets[0].Pt()) - (leptons[0].Pt()+leptons[1].Pt());
   }
   else {
       DHTLT = (Jet1_PT+Jet2_PT) - (leptons[0].Pt()+leptons[1].Pt());
   }

   float HT = 0;

   float LT = 0;

   for(unsigned Nbj=0; Nbj<bJets.size(); ++Nbj){
    HT = HT + bJets[Nbj].Pt();
   }
   for(unsigned Nj=0; Nj<non_bJets.size(); ++Nj){
    HT = HT + non_bJets[Nj].Pt();
   }
   for(unsigned Nl=0; Nl<leptons.size(); ++Nl){
    LT = LT + leptons[Nl].Pt();
   }

   DHTLT = HT - LT;*/
   return DHTLT;
};

/*float calculateHTLT(vector<TLorentzVector> bJets, vector<TLorentzVector> non_bJets, vector<TLorentzVector> leptons)
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
};*/




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


  //std::cout << lep1_jet1_mass << " " << lep1_jet2_mass << " " << lep2_jet1_mass << " " << lep2_jet2_mass << " " << std::endl;
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

      //std::cout << lep1_jet1_mass << " " << lep1_jet2_mass << " " << lep2_jet1_mass << " " << lep2_jet2_mass << " " << std::endl;
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


   //static int  r[4];

   std::vector<float> cutFlow = {0,0,0,0,0,0,0,0};

  
   if (fChain == 0) return cutFlow;

   
   //Create root file with histograms
   TFile *output = new TFile(sample_name,"recreate");

   

  struct histogramClass
  {

  float pi =  3.14159265359;
   //histograms
   TH1F *run_hist;
   TH1F *leppT_hist;

   TH1F *lepeta_hist;
   TH1F *lepphi_hist;
   TH1F *lepIso_hist;


   TH1F *leppT_p_hist;
   TH1F *lepeta_p_hist;
   TH1F *lepphi_p_hist;
   TH1F *lepIso_p_hist;

   TH1F *leppT_n_hist;
   TH1F *lepeta_n_hist;
   TH1F *lepphi_n_hist;
   TH1F *lepIso_n_hist;

   TH1F * nLeptons;
   TH1F * nElectrons;
   TH1F * nMuons;

   TH1F *jet1eta_n_hist;
   TH1F *jet1phi_n_hist;
   TH1F *jet1pT_n_hist;

   TH1F *jet2eta_n_hist;
   TH1F *jet2phi_n_hist;
   TH1F *jet2pT_n_hist;



   TH1F *jeteta_noB_hist;

   TH1F *jetpT_noB_hist;

   TH1F *nJet_hist;

   TH1F *jet1NonB_atleast2_eta_n_hist;
   TH1F *jet1NonB_atleast2_phi_n_hist;
   TH1F *jet1NonB_atleast2_pT_n_hist;

   TH1F *jet2NonB_atleast2_eta_n_hist;
   TH1F *jet2NonB_atleast2_phi_n_hist;
   TH1F *jet2NonB_atleast2_pT_n_hist;

   TH1F *jet1B_atleast2_eta_n_hist;
   TH1F *jet1B_atleast2_phi_n_hist;
   TH1F *jet1B_atleast2_pT_n_hist;

   TH1F *jet2B_atleast2_eta_n_hist;
   TH1F *jet2B_atleast2_phi_n_hist;
   TH1F *jet2B_atleast2_pT_n_hist;





   TH1F *dPhi_dimuon_hist;
   TH1F *dR_hist;
   TH1F *mass_hist;

   TH1F *jetpT_hist;
   TH1F *jeteta_hist;

   TH1F *bjetpT_hist;
   TH1F *bjeteta_hist;

   TH1F *NonbjetpT_hist;
   TH1F *Nonbjeteta_hist;
   
   TH1F *nbjet_hist;
   TH1F *nNonbjet_hist;
   TH1F *id_hist;

   TH2F *njvsnbj_hist;


   TH2F *leading_lep_pt_second_lep_pt;
   
   TH1F *MET_hist;
   TH1F *dilep_mass_hist;
   TH1F *dilep_mass_hist_before_cut;
   TH1F *dilep_mass_hist_z_cut;
   TH1F* dilep_mass_hist_z_cut_wide;
   TH1F *MET_hist_before_cut;
   TH1F *SBM_hist_before_cut;
   TH1F *METvsMmm_hist_before_cut;
   TH1F *HTLT_hist_before_cut;
   TH1F *dPhi_hist_before_cut;


   TH1F *SBM_hist;
   TH1F *METvsMmm_hist;
   TH1F *HTLT_hist;
   TH1F *dPhi_hist;


   TH1F *Mass_hist;
   
   TH1F *mini_SBM_hist;
   TH1F *mini_SBM_minus173_hist;

   TH1F *lep_jet_min_deltaR;


   TH1F *lep1pT_p_hist;
   TH1F *lep1eta_p_hist;
   TH1F *lep1phi_p_hist;
   TH1F *lep1Iso_p_hist;

   TH1F *lep2pT_p_hist;
   TH1F *lep2eta_p_hist;
   TH1F *lep2phi_p_hist;
   TH1F *lep2Iso_p_hist;

   TH1F *lepDphi;
   TH1F *lepDphi_z_cut;
   TH1F *lepDphi_anti_z_cut;
   TH1F *lepDphi_iso_cut;

   TH1F *lepDpt;
   TH1F *lepDeta;
   TH1F *lepDr;
   TH1F *lepSumPt;


   TH1F *jetDphi;
   TH1F *jetDphi_z_cut;
   TH1F *jetDphi_anti_z_cut;
   TH1F *jetDphi_iso_cut;

   TH1F *jetDpt;
   TH1F *jetDeta;
   TH1F *jetDr;
   TH1F *jetSumPt;

   TH1F *lepjetDphi;
   TH1F *lepjetDphi_z_cut;
   TH1F *lepjetDphi_anti_z_cut;
   TH1F *lepjetDphi_iso_cut;

   TH1F *lepjetDpt;
   TH1F *lepjetDeta;
   TH1F *lepjetDr;
   TH1F *lepjetSumPt;


   TH1F *MET_hist_z_cut;
   TH1F *SBM_hist_z_cut;
   TH1F *METvsMmm_hist_z_cut;
   TH1F *HTLT_hist_z_cut;
   TH1F *dPhi_hist_z_cut;


   histogramClass(TString name)
   {
    run_hist = new TH1F(name+"run_hist","Total number of events passed through the pre-selection cut; run; Number of events;",3,0,3); run_hist->Sumw2();
    leppT_hist = new TH1F(name+"leppT_hist","lepton pt; p_{T} [GeV]; Number of events",100,0,500); leppT_hist->Sumw2();
    lepeta_hist = new TH1F(name+"lepeta_hist","lepton eta; #eta; Number of events",20,-5,5); lepeta_hist->Sumw2();
    lepphi_hist = new TH1F(name+"lepphi_hist","lepton phi; #phi; Number of events",20,-pi,pi); lepphi_hist->Sumw2();
    lepIso_hist = new TH1F(name+"lepIso_hist","lepton isolation; Isolation; Number of events;",100,0,400); lepIso_hist->Sumw2();


    lep1pT_p_hist = new TH1F(name+"lep1pT_p_hist","lepton 1 pt; p_{T} [GeV]; Number of events",100,0,500); leppT_hist->Sumw2();
    lep1eta_p_hist = new TH1F(name+"lep1eta_p_hist","lepton 1 eta; #eta; Number of events",20,-5,5); lepeta_hist->Sumw2();
    lep1phi_p_hist = new TH1F(name+"lep1phi_p_hist","lepton 1 phi; #phi; Number of events",20,-pi,pi); lepphi_hist->Sumw2();
    lep1Iso_p_hist = new TH1F(name+"lep1Iso_p_hist","lepton 1 isolation; Isolation; Number of events;",100,0,1); lepIso_hist->Sumw2();

    lep2pT_p_hist = new TH1F(name+"lep2pT_p_hist","lepton 2 pt; p_{T} [GeV]; Number of events",100,0,500); leppT_hist->Sumw2();
    lep2eta_p_hist = new TH1F(name+"lep2eta_p_hist","lepton 2 eta; #eta; Number of events",20,-5,5); lepeta_hist->Sumw2();
    lep2phi_p_hist = new TH1F(name+"lep2phi_p_hist","lepton 2 phi; #phi; Number of events",20,-pi,pi); lepphi_hist->Sumw2();
    lep2Iso_p_hist = new TH1F(name+"lep2Iso_p_hist","lepton 2 isolation; Isolation; Number of events;",100,0,1); lepIso_hist->Sumw2();

    lepDphi = new TH1F(name+"lepDphi", "lepton #Delta_{#phi} - #pi", 100, 0, pi); lepDphi->Sumw2();
    lepDphi_anti_z_cut = new TH1F(name+"lepDphi_anti_z_cut", "anti z cut lepton #Delta_{#phi} - #pi", 100, 0, pi); lepDphi->Sumw2();
    lepDphi_z_cut = new TH1F(name+"lepDphi_z_cut", "z cut lepton #Delta_{#phi} - #pi", 100, 0, pi); lepDphi->Sumw2();
    lepDphi_iso_cut = new TH1F(name+"lepDphi_iso_cut", "iso cut lepton #Delta_{#phi} - #pi", 100, 0, pi); lepDphi->Sumw2();
    lepDpt = new TH1F(name+"lepDpt", "lepton #Delta_{p_{T}}", 100, 0, 200); lepDpt->Sumw2();
    lepDeta = new TH1F(name+"lepDeta", "lepton #Delta_{#eta}", 100, -3, 3); lepDeta->Sumw2();
    lepDr = new TH1F(name+"lepDr", "lepton #Delta_{R}", 100, 0, 4); lepDr->Sumw2();
    lepSumPt = new TH1F(name+"lepSumPt", "lepton Sum Pt", 100, 0, 1000); lepSumPt->Sumw2();
  
    dPhi_dimuon_hist = new TH1F(name+"dPhi_dimuon_hist","delta phi_{#mu,#mu}; #Delta#phi_{#mu,#mu}; Number of events",50,-4,4); dPhi_dimuon_hist->Sumw2();
    dR_hist = new TH1F(name+"dR_hist","delta R_{#mu,#mu}; #DeltaR_{#mu,#mu}; Number of events",50,0,5); dR_hist->Sumw2();
    mass_hist = new TH1F(name+"mass_hist","Dilepton mass tree; Dilepton mass; Number of events",50,0,500); mass_hist->Sumw2();
  
    jetpT_hist = new TH1F(name+"jetpT_hist","jet pT; p_{T} [GeV]; Number of events",100,0,500); jetpT_hist->Sumw2();
    jeteta_hist = new TH1F(name+"jeteta_hist","jet eta; #eta; Number of events",20,-5,5); jeteta_hist->Sumw2();
  
    bjetpT_hist = new TH1F(name+"bjetpT_hist","b-jet pT; p_{T} [GeV]; Number of Evets",100,0,500); bjetpT_hist->Sumw2();
    bjeteta_hist = new TH1F(name+"bjeteta_hist","b-jet eta; #eta; Number of events",20,-5,5); bjeteta_hist->Sumw2();
  
    NonbjetpT_hist = new TH1F(name+"NonbjetpT_hist","non b-jet pT; p_{T} [GeV]; Number of events",100,0,500); NonbjetpT_hist->Sumw2();
    Nonbjeteta_hist = new TH1F(name+"Nonbjeteta_hist","non b-jet eta; #eta; Number of events",20,-5,5); Nonbjeteta_hist->Sumw2();
    
    nbjet_hist = new TH1F(name+"nbjet_hist","Number of b-jet; Number of b-jets; Number of events",11,0,11); nbjet_hist->Sumw2();
    nNonbjet_hist = new TH1F(name+"nNonbjet_hist","Number of non-bjet; Number of non-bjets; Number of events",11,0,11); nNonbjet_hist->Sumw2();
    id_hist = new TH1F(name+"id_hist","particle id; id number; Number of events",30,-15,15); id_hist->Sumw2();
  
    njvsnbj_hist = new TH2F(name+"njvsnbj_hist","Number of non_b-jets vs Number of b-jets; Number of non_bjets; Number of b-jets",10,0,10,5,0,5); njvsnbj_hist->Sumw2();

    leading_lep_pt_second_lep_pt = new TH2F(name+"leading_lep_pt_second_lep_pt","leading_lep_pt_second_lep_pt; leading \ell_{p_{T}};second leading \ell_{p_{T}}",100,0,500,100,0,500); leading_lep_pt_second_lep_pt->Sumw2();
    
    MET_hist = new TH1F(name+"MET_hist","Missing ET; E^{miss}_{T} [GeV]; Number ofe events",100,0,1000); MET_hist->Sumw2();


    Int_t nBins = 100;
    Float_t bins[nBins+1];
    Float_t maxEdge = 1000;
    Float_t minEdge = 1;
    Float_t width = TMath::Exp(TMath::Log(maxEdge - minEdge)/(nBins+1));
    //static Float_t bins[nBins + 1];
  
    for (int i = 0; i <= nBins+1; i++) {
      bins[i] = minEdge + TMath::Power(width,i );
      //std::cout << 1 + TMath::Power(width,i ) <<std::endl;
    } 

    dilep_mass_hist = new TH1F(name+"dilep_mass_hist","dilepton mass; Mass_{#mu,#mu} [GeV]; Number of events",200,1,1000);     dilep_mass_hist->Sumw2();
    //dilep_mass_hist = new TH1F(name+"dilep_mass_hist","dilepton mass; Mass_{#mu,#mu} [GeV]; Number of events",nBins, bins ); 
    //BinLogX(dilep_mass_hist);
    dilep_mass_hist_before_cut = new TH1F(name+"dilep_mass_hist_before_cut","dilepton mass before cuts; Mass_{#mu,#mu} [GeV]; Number of events",200,1,1000); dilep_mass_hist_before_cut->Sumw2();
    dilep_mass_hist_z_cut = new TH1F(name+"dilep_mass_hist_z_cut","dilepton mass z cuts; Mass_{#mu,#mu} [GeV]; Number of events",200,81,101); dilep_mass_hist_before_cut->Sumw2();
    dilep_mass_hist_z_cut_wide = new TH1F(name+"dilep_mass_hist_z_cut_wide","dilepton mass z cuts; Mass_{#mu,#mu} [GeV]; Number of events",200,50,150); dilep_mass_hist_before_cut->Sumw2();
    MET_hist_before_cut = new TH1F(name+"MET_hist_before_cut","Missing ET; E^{miss}_{T} [GeV]; Number ofe events",100,0,1000); MET_hist_before_cut->Sumw2();
    SBM_hist_before_cut = new TH1F(name+"SBM_hist_before_cut","max(SBM); max(SBM) [GeV]; a.u.",100,0,300); SBM_hist_before_cut->Sumw2();
    METvsMmm_hist_before_cut = new TH1F(name+"METvsMmm_hist_before_cut","E^{miss}_{T}/M(#mu^{+}#mu^{-}); E^{miss}_{T}/M(#mu^{+}#mu^{-}) [GeV]; a.u.",100,0,1); METvsMmm_hist_before_cut->Sumw2();
    HTLT_hist_before_cut = new TH1F(name+"HTLT_hist_before_cut","HT-LT; HT-LT [GeV]; a.u.",100,-500,500); HTLT_hist_before_cut->Sumw2();
    dPhi_hist_before_cut = new TH1F(name+"dPhi_hist_before_cut","delta phi_{dimuon,b}; #Delta#phi_{dimuon,b}; Number of events",50,-4,4); dPhi_hist_before_cut->Sumw2();
  



  
    SBM_hist = new TH1F(name+"SBM_hist","max(SBM); max(SBM) [GeV]; a.u.",100,0,300); SBM_hist->Sumw2();
    METvsMmm_hist = new TH1F(name+"METvsMmm_hist","E^{miss}_{T}/M(#mu^{+}#mu^{-}); E^{miss}_{T}/M(#mu^{+}#mu^{-}) [GeV]; a.u.",100,0,1); METvsMmm_hist->Sumw2();
    HTLT_hist = new TH1F(name+"HTLT_hist","HT-LT; HT-LT [GeV]; a.u.",100,-500,500); HTLT_hist->Sumw2();
    dPhi_hist = new TH1F(name+"dPhi_hist","delta phi_{dimuon,b}; #Delta#phi_{dimuon,b}; Number of events",50,-4,4); dPhi_hist->Sumw2();
  
    Mass_hist = new TH1F(name+"Mass_hist","Lepton mass(M_{#mu}); M_{#mu} [GeV]; Number of events",100,0,500); Mass_hist->Sumw2();
    
    mini_SBM_hist = new TH1F(name+"mini_SBM_hist","minimum mass of mu-b combinations; mini(SBM) [GeV]; a.u.",100,0,300); mini_SBM_hist->Sumw2();
    mini_SBM_minus173_hist = new TH1F(name+"mini_SBM_minus173_hist","minimum mass of |(mu-b combinations) - 173 |; mini(SBM)-173 [GeV]; a.u.",100,0,300); mini_SBM_minus173_hist->Sumw2();


   lepeta_p_hist = new TH1F(name+"lepeta_p_hist", "lepeta_p_hist", 20,-5,5); lepeta_p_hist->Sumw2();
   lepphi_p_hist = new TH1F(name+"lepphi_p_hist", "lepphi_p_hist", 20,-3.5,3.5); lepphi_p_hist->Sumw2();
   leppT_p_hist = new TH1F(name+"leppT_p_hist", "leppT_p_hist", 100,0,500); leppT_p_hist->Sumw2();

   lepeta_n_hist = new TH1F(name+"lepeta_n_hist", "lepeta_n_hist", 20,-5,5); lepeta_n_hist->Sumw2();
   lepphi_n_hist = new TH1F(name+"lepphi_n_hist", "lepphi_n_hist", 20,-3.5,3.5); lepphi_n_hist->Sumw2();
   leppT_n_hist = new TH1F(name+"leppT_n_hist", "leppT_n_hist", 100,0,500); leppT_n_hist->Sumw2();

    nLeptons = new TH1F(name+"nLeptons", "nLeptons", 11,0,11); nLeptons->Sumw2();
    nElectrons = new TH1F(name+"nElectrons", "nElectrons", 11,0,11); nElectrons->Sumw2();
    nMuons = new TH1F(name+"nMuons", "nMuons", 11,0,11); nMuons->Sumw2();

   jet1eta_n_hist = new TH1F(name+"jet1eta_n_hist", "jet1eta_n_hist",20,-5,5); jet1eta_n_hist->Sumw2();
   jet1phi_n_hist = new TH1F(name+"jet1phi_n_hist", "jet1phi_n_hist", 20,-3.5,3.5); jet1phi_n_hist->Sumw2();
   jet1pT_n_hist = new TH1F(name+"jet1pT_n_hist", "jet1pT_n_hist", 100,0,500); jet1pT_n_hist->Sumw2();

   jet2eta_n_hist = new TH1F(name+"jet2eta_n_hist", "jet2eta_n_hist", 20,-5,5); jet2eta_n_hist->Sumw2();
   jet2phi_n_hist = new TH1F(name+"jet2phi_n_hist", "jet2phi_n_hist", 20,-3.5,3.5); jet2phi_n_hist->Sumw2();
   jet2pT_n_hist = new TH1F(name+"jet2pT_n_hist", "jet2pT_n_hist", 100,0,500); jet2pT_n_hist->Sumw2();



    jeteta_noB_hist = new TH1F(name+"jeteta_noB_hist", "jeteta_noB_hist", 20, -3, 3); jeteta_noB_hist->Sumw2();
    jetpT_noB_hist = new TH1F(name+"jetpT_noB_hist", "jetpT_noB_hist", 100, 0, 500); jetpT_noB_hist->Sumw2();

   nJet_hist = new TH1F(name+"nJet_hist", "nJet_hist", 11,0,11); nJet_hist->Sumw2();

   jet1NonB_atleast2_eta_n_hist = new TH1F(name+"jet1NonB_atleast2_eta_n_hist", "jet1NonB_atleast2_eta_n_hist", 20,-5,5); jet1NonB_atleast2_eta_n_hist->Sumw2();
   jet1NonB_atleast2_phi_n_hist = new TH1F(name+"jet1NonB_atleast2_phi_n_hist", "jet1NonB_atleast2_phi_n_hist", 20,-3.5,3.5); jet1NonB_atleast2_phi_n_hist->Sumw2();
   jet1NonB_atleast2_pT_n_hist = new TH1F(name+"jet1NonB_atleast2_pT_n_hist", "jet1NonB_atleast2_pT_n_hist", 100,0,500); jet1NonB_atleast2_pT_n_hist->Sumw2();

   jet2NonB_atleast2_eta_n_hist = new TH1F(name+"jet2NonB_atleast2_eta_n_hist", "jet2NonB_atleast2_eta_n_hist", 20,-5,5); jet2NonB_atleast2_eta_n_hist->Sumw2();
   jet2NonB_atleast2_phi_n_hist = new TH1F(name+"jet2NonB_atleast2_phi_n_hist", "jet2NonB_atleast2_phi_n_hist", 20,-3.5,3.5); jet2NonB_atleast2_phi_n_hist->Sumw2();
   jet2NonB_atleast2_pT_n_hist = new TH1F(name+"jet2NonB_atleast2_pT_n_hist", "jet2NonB_atleast2_pT_n_hist", 100,0,500); jet2NonB_atleast2_pT_n_hist->Sumw2();

   jet1B_atleast2_eta_n_hist = new TH1F(name+"jet1B_atleast2_eta_n_hist", "jet1B_atleast2_eta_n_hist", 20,-5,5); jet1B_atleast2_eta_n_hist->Sumw2();
   jet1B_atleast2_phi_n_hist = new TH1F(name+"jet1B_atleast2_phi_n_hist", "jet1B_atleast2_phi_n_hist", 20,-3.5,3.5); jet1B_atleast2_phi_n_hist->Sumw2();
   jet1B_atleast2_pT_n_hist = new TH1F(name+"jet1B_atleast2_pT_n_hist", "jet1B_atleast2_pT_n_hist", 100,0,500); jet1B_atleast2_pT_n_hist->Sumw2();

   jet2B_atleast2_eta_n_hist = new TH1F(name+"jet2B_atleast2_eta_n_hist", "jet2B_atleast2_eta_n_hist", 20,-5,5); jet2B_atleast2_eta_n_hist->Sumw2();
   jet2B_atleast2_phi_n_hist = new TH1F(name+"jet2B_atleast2_phi_n_hist", "jet2B_atleast2_phi_n_hist", 20,-3.5,3.5); jet2B_atleast2_phi_n_hist->Sumw2();
   jet2B_atleast2_pT_n_hist = new TH1F(name+"jet2B_atleast2_pT_n_hist", "jet2B_atleast2_pT_n_hist", 100,0,500); jet2B_atleast2_pT_n_hist->Sumw2();


   lep_jet_min_deltaR = new TH1F(name+"lep_jet_min_deltaR", "lep_jet_min_deltaR", 100,0,3); lep_jet_min_deltaR->Sumw2();




    jetDphi = new TH1F(name+"jetDphi", "jetton #Delta_{#phi} - #pi", 100, 0, pi); jetDphi->Sumw2();
    jetDphi_anti_z_cut = new TH1F(name+"jetDphi_anti_z_cut", "anti z cut jetton #Delta_{#phi} - #pi", 100, 0, pi); jetDphi->Sumw2();
    jetDphi_z_cut = new TH1F(name+"jetDphi_z_cut", "z cut jetton #Delta_{#phi} - #pi", 100, 0, pi); jetDphi->Sumw2();
    jetDphi_iso_cut = new TH1F(name+"jetDphi_iso_cut", "iso cut jetton #Delta_{#phi} - #pi", 100, 0, pi); jetDphi->Sumw2();
    jetDpt = new TH1F(name+"jetDpt", "jetton #Delta_{p_{T}}", 100, 0, 200); jetDpt->Sumw2();
    jetDeta = new TH1F(name+"jetDeta", "jetton #Delta_{#eta}", 100, -3, 3); jetDeta->Sumw2();
    jetDr = new TH1F(name+"jetDr", "jetton #Delta_{R}", 100, 0, 4); jetDr->Sumw2();
    jetSumPt = new TH1F(name+"jetSumPt", "jetton Sum Pt", 100, 0, 1000); jetSumPt->Sumw2();


    lepjetDphi = new TH1F(name+"lepjetDphi", "lepjetton #Delta_{#phi} - #pi", 100, 0, pi); lepjetDphi->Sumw2();
    lepjetDphi_anti_z_cut = new TH1F(name+"lepjetDphi_anti_z_cut", "anti z cut lepjetton #Delta_{#phi} - #pi", 100, 0, pi); lepjetDphi->Sumw2();
    lepjetDphi_z_cut = new TH1F(name+"lepjetDphi_z_cut", "z cut lepjetton #Delta_{#phi} - #pi", 100, 0, pi); lepjetDphi->Sumw2();
    lepjetDphi_iso_cut = new TH1F(name+"lepjetDphi_iso_cut", "iso cut lepjetton #Delta_{#phi} - #pi", 100, 0, pi); lepjetDphi->Sumw2();
    lepjetDpt = new TH1F(name+"lepjetDpt", "lepjetton #Delta_{p_{T}}", 100, 0, 200); lepjetDpt->Sumw2();
    lepjetDeta = new TH1F(name+"lepjetDeta", "lepjetton #Delta_{#eta}", 100, -3, 3); lepjetDeta->Sumw2();
    lepjetDr = new TH1F(name+"lepjetDr", "lepjetton #Delta_{R}", 100, 0, 4); lepjetDr->Sumw2();
    lepjetSumPt = new TH1F(name+"lepjetSumPt", "lepjetton Sum Pt", 100, 0, 1000); lepjetSumPt->Sumw2();



    MET_hist_z_cut = new TH1F(name+"MET_hist_z_cut","Missing ET; E^{miss}_{T} [GeV]; Number ofe events",100,0,1000); MET_hist_z_cut->Sumw2();
    SBM_hist_z_cut = new TH1F(name+"SBM_hist_z_cut","max(SBM); max(SBM) [GeV]; a.u.",100,0,300); SBM_hist_z_cut->Sumw2();
    METvsMmm_hist_z_cut = new TH1F(name+"METvsMmm_hist_z_cut","E^{miss}_{T}/M(#mu^{+}#mu^{-}); E^{miss}_{T}/M(#mu^{+}#mu^{-}) [GeV]; a.u.",100,0,1); METvsMmm_hist_z_cut->Sumw2();
    HTLT_hist_z_cut = new TH1F(name+"HTLT_hist_z_cut","HT-LT; HT-LT [GeV]; a.u.",100,-500,500); HTLT_hist_z_cut->Sumw2();
    dPhi_hist_z_cut = new TH1F(name+"dPhi_hist_z_cut","delta phi_{dimuon,b}; #Delta#phi_{dimuon,b}; Number of events",50,-4,4); dPhi_hist_z_cut->Sumw2();

   
    }
  };


   histogramClass histClass("");
   
   Long64_t nentries = fChain->GetEntriesFast();


   //cs, totalN, Lumi -> Refer to see header file (.h)
   float weight = targetLumi * xsection/numberOfEvents;
   if(xsection < 0) weight = 1;
   std::cout << "sample_name "<< sample_name << std::endl;
   //std::cout << "weight "<< weight << std::endl;
   //std::cout << "targetLumi "<< targetLumi << std::endl;
   //std::cout << "xsection "<< xsection << std::endl;
   //std::cout << "numberOfEvents "<< numberOfEvents << std::endl;


   int count=0;
   Long64_t nbytes = 0, nb = 0;
   //Loop over all events
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
       Long64_t ientry = LoadTree(jentry);
       if (ientry < 0) break;
       nb = fChain->GetEntry(jentry);   nbytes += nb;
       // if (Cut(ientry) < 0) continue;

       histClass.run_hist->Fill(run);

       cutFlow.at(0) = cutFlow.at(0) + weight;

       if(lep_pt[0] > 53 &&lep_pt[1] > 53){ //lep pT > 53GeV
           if(dil_dR > 0.1){ // dR(lep,lep) > 0.1
               if(fabs(lep_dz[0])<0.5 && fabs(lep_dz[1])<0.5){


                const double muon_mass = 0.1056583715;
                TLorentzVector lep1;
                TLorentzVector lep2;
                lep1.SetPtEtaPhiM(lep_pt[0],lep_eta[0],lep_phi[0],muon_mass);
                lep2.SetPtEtaPhiM(lep_pt[1],lep_eta[1],lep_phi[1],muon_mass);


                //std::cout << lep_pfIso[0]/lep_pt[0] << std::endl;
                if ((lep1+lep2).M()< 55) continue;
                if (lep_pfIso[0]/lep_pt[0] > .05 or lep_pfIso[1]/lep_pt[1] > .05) continue;


                    cutFlow.at(1) = cutFlow.at(1) + weight;
                   //Opposite sign dilepton
                   if(lep_id[0] * lep_id[1] < 0){

                    cutFlow.at(2) = cutFlow.at(2) + weight;

                    //std::cout << lep_triggerMatchEta[1] << " " <<  lep_triggerMatchEta[0] << std::endl;
                    //if (lep_triggerMatchEta[0] == -999 && lep_triggerMatchEta[1] == -999) continue;


                       cutFlow.at(3) = cutFlow.at(3) + weight;

                       //if(dil_chosen != 0) continue;
                       //particle id
                       int id1 = lep_id[0];
                       int id2 = lep_id[1];

                       histClass.id_hist->Fill(id1);
                       histClass.id_hist->Fill(id2);

                       //Save leptons information
                       vector<TLorentzVector> leptons;
                       vector<Lepton> leptons_;
                       for(unsigned lep_N=0; lep_N<2; ++lep_N){
                           TLorentzVector lepton;
                           TLorentzVector lepton_;
                           lepton.SetPtEtaPhiM(lep_pt[lep_N],lep_eta[lep_N],lep_phi[lep_N],muon_mass);
                           lepton_.SetPtEtaPhiM(lep_pt[lep_N],lep_eta[lep_N],lep_phi[lep_N],muon_mass);
                           leptons.push_back(lepton);
                           Lepton dummy = {lepton_, lep_pfIso[lep_N]/lep_pt[lep_N]};
                           leptons_.push_back(dummy);
                       }  // example(1): float FirstLeptonMass = leptons[0].M();
                       ///// example(2): float FirstLeptonIso = leptons_[0].Iso;


                      //first lepton is negative
                      float lep_p_pt = lep_pt[1];
                      float lep_p_eta = lep_eta[1];
                      float lep_p_phi = lep_phi[1];

                      float lep_n_pt = lep_pt[0];
                      float lep_n_eta = lep_eta[0];
                      float lep_n_phi = lep_phi[0];

                      int nElectronsValue = 0;
                      int nMuonsValue = 0;
                      int nLepValue = 0;

    

                      for(unsigned lep_N=0; lep_N<sizeof(lep_pt)/sizeof(lep_pt[0])+1; ++lep_N){
                        if (lep_id[lep_N] == 13){
                          nMuonsValue = nMuonsValue+1;

                        }

                        if (lep_id[lep_N] == 11){
                            nElectronsValue = nElectronsValue+1;
                        }

                      }

                      nLepValue = nElectronsValue + nMuonsValue;

                       
                       vector<TLorentzVector> bJets;
                       vector<TLorentzVector> non_bJets;

                       vector<TLorentzVector> allJets;

                       for(int NJ=0; NJ<nJets; NJ++){


                           if(jet_pt[NJ] > 20){ //jet pT > 20GeV
                            //if (jet_pt[NJ] > 30) std::cout << "entery " << jentry << " jetn: " << NJ << " pt " << jet_pt[NJ] << " jet eta " << jet_eta[NJ] <<  " jet Btag " << jet_btag[NJ] << std::endl;
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

                        histClass.nJet_hist->Fill(njets);


                        
                        histClass.lepeta_p_hist->Fill(lep_p_eta);
                        histClass.lepphi_p_hist->Fill(lep_p_phi);
                        histClass.leppT_p_hist->Fill(lep_p_pt);
                        
                        histClass.lepeta_n_hist->Fill(lep_n_eta);
                        histClass.lepphi_n_hist->Fill(lep_n_phi);
                        histClass.leppT_n_hist->Fill(lep_n_pt);
                        
                        histClass.nLeptons->Fill(nLepValue);
                        histClass.nElectrons->Fill(nElectronsValue);
                        histClass.nMuons->Fill(nMuonsValue);
                        
                        if (njets >0){
                        
                          histClass.jet1eta_n_hist->Fill(allJets[0].Eta());
                          histClass.jet1phi_n_hist->Fill(allJets[0].Phi());
                          histClass.jet1pT_n_hist->Fill(allJets[0].Pt());
                          
                          if (njets >1){
                          histClass.jet2eta_n_hist->Fill(allJets[1].Eta());
                          histClass.jet2phi_n_hist->Fill(allJets[1].Phi());
                          histClass.jet2pT_n_hist->Fill(allJets[1].Pt());
                          }
                        
                        }
                        
                        
                        if (njets <3){
                          
                          if (nNonBjets >0){
                          histClass.jet1NonB_atleast2_eta_n_hist->Fill(non_bJets[0].Eta());
                          histClass.jet1NonB_atleast2_phi_n_hist->Fill(non_bJets[0].Phi());
                          histClass.jet1NonB_atleast2_pT_n_hist->Fill(non_bJets[0].Pt());
                        
                          if (nNonBjets >1){
                          histClass.jet2NonB_atleast2_eta_n_hist->Fill(non_bJets[1].Eta());
                          histClass.jet2NonB_atleast2_phi_n_hist->Fill(non_bJets[1].Phi());
                          histClass.jet2NonB_atleast2_pT_n_hist->Fill(non_bJets[1].Pt());
                          }
                          }
                        
                          if (nBjets >0){
                          histClass.jet1B_atleast2_eta_n_hist->Fill(bJets[0].Eta());
                          histClass.jet1B_atleast2_phi_n_hist->Fill(bJets[0].Phi());
                          histClass.jet1B_atleast2_pT_n_hist->Fill(bJets[0].Pt());
                          if (nBjets >1){
                          histClass.jet2B_atleast2_eta_n_hist->Fill(bJets[1].Eta());
                          histClass.jet2B_atleast2_phi_n_hist->Fill(bJets[1].Phi());
                          histClass.jet2B_atleast2_pT_n_hist->Fill(bJets[1].Pt());
                          }
                          } 
                        
                        }

                        if (nBjets ==0){
                          for(unsigned jet_N=0; jet_N<non_bJets.size(); ++jet_N){
                            histClass.jeteta_noB_hist->Fill(non_bJets[jet_N].Eta());
                            histClass.jetpT_noB_hist->Fill(non_bJets[jet_N].Pt());
                          }
                        }

                        float MET_t = met_pt;



                        //deltaR plot 

                        Float_t min_DeltaR = 1000;

                        for(unsigned lep_N=0; lep_N<sizeof(leptons)/sizeof(leptons[0])+1; ++lep_N){
                          for(unsigned jet_N=0; jet_N<non_bJets.size(); ++jet_N){
                            min_DeltaR  = min((Float_t)non_bJets[jet_N].DeltaR(leptons[lep_N]) ,min_DeltaR);
                          }
                        }

                        histClass.lep_jet_min_deltaR->Fill(min_DeltaR);


                        float DHTLT = calculateHTLT(bJets, non_bJets, leptons);

                       //METvsMmm (Normalized MET)
                       float Mmm = ((leptons[0])+(leptons[1])).M();

                       //if (Mmm < 50) continue;
                       //if (leptons_[0].Iso > 5 and leptons_[1].Iso > 5) continue;
                       //if (Mmm < 120) continue;
     
                       float METvsMmm = MET_t/Mmm ;
                       //if(METvsMmm<0.2){ // <0.2 cut

                      float aSBM[3]= {-1, -1, -1};

                      calculateSBM(aSBM, allJets, leptons);


                      float SBMMin =aSBM[1];
                      float SBMMax =aSBM[2];
                      float SBM = aSBM[0];


                        histClass.dilep_mass_hist_before_cut->Fill(Mmm, weight);
                        if (Mmm < 101 and Mmm > 81) histClass.dilep_mass_hist_z_cut->Fill(Mmm, weight);
                        histClass.dilep_mass_hist_z_cut_wide->Fill(Mmm, weight);
                        histClass.MET_hist_before_cut->Fill(MET_t);
                        histClass.SBM_hist_before_cut->Fill(SBMMax,weight);
                        histClass.METvsMmm_hist_before_cut->Fill(METvsMmm,weight);
                        histClass.HTLT_hist_before_cut->Fill(DHTLT,weight);


                        if(bJets.size()==1){
                           float Phi_dimuon = (leptons[0] + leptons[1]).Phi();
                           float Phi_b = bJets[0].Phi();
                           float dPhi_dimu_b = Phi_dimuon - Phi_b;
                           if(dPhi_dimu_b >= TMath::Pi()) dPhi_dimu_b -= 2.*TMath::Pi();
                           if(dPhi_dimu_b < -TMath::Pi()) dPhi_dimu_b += 2.*TMath::Pi();
                           histClass.dPhi_hist_before_cut->Fill(dPhi_dimu_b,weight);
                       }



                       float leading_lep_pt = max(leptons[0].Pt(),leptons[1].Pt());
                       float second_leading_lep_pt = min(leptons[0].Pt(),leptons[1].Pt());

                       int maxIndex = 0;
                       int minIndex = 1;
                       if (leptons[0].Pt() < leptons[1].Pt()){
                        maxIndex = 1;
                        minIndex = 0;
                       }


                      // std::cout << maxIndex << " " << leading_lep_pt<< " " << leptons[0].Pt() <<  " " << leptons[1].Pt() << std::endl;

                      // std::cout << leptons[maxIndex].Pt() - leptons[minIndex].Pt() << " " << leptons[maxIndex].Pt() << " " << leptons[minIndex].Pt() << std::endl;

                       histClass.lep1pT_p_hist->Fill(leptons[maxIndex].Pt());
                       histClass.lep1eta_p_hist->Fill(leptons[maxIndex].Eta());
                       histClass.lep1phi_p_hist->Fill(leptons[maxIndex].Phi());
                       histClass.lep1Iso_p_hist->Fill(leptons_[maxIndex].Iso);
                       
                       
                       histClass.lep2pT_p_hist->Fill(leptons[minIndex].Pt());
                       histClass.lep2eta_p_hist->Fill(leptons[minIndex].Eta());
                       histClass.lep2phi_p_hist->Fill(leptons[minIndex].Phi());
                       histClass.lep2Iso_p_hist->Fill(leptons_[minIndex].Iso);
                       

                      float pi =  3.14159265359;
                      float dPhi = leptons[maxIndex].DeltaPhi(leptons[minIndex]);
                       
                       histClass.lepDphi->Fill(dPhi);
                       if (Mmm < 101 and Mmm > 81) histClass.lepDphi_z_cut->Fill(dPhi);
                       if (not (Mmm < 101 and Mmm > 81)) histClass.lepDphi_anti_z_cut->Fill(dPhi);

                       if (leptons_[maxIndex].Iso > .5 and leptons_[minIndex].Iso > .5) histClass.lepDphi_iso_cut->Fill(dPhi);

                       histClass.lepDpt->Fill(leptons[maxIndex].Pt() - leptons[minIndex].Pt());
                       histClass.lepDeta->Fill(leptons[maxIndex].Eta() - leptons[minIndex].Eta());
                       histClass.lepDr->Fill(leptons[maxIndex].DeltaR(leptons[minIndex]));
                       histClass.lepSumPt->Fill(leptons[maxIndex].Pt() + leptons[minIndex].Pt());

/*

                       if (nBjets + njets > 1){

                          float dPhiJet = allJets[1].DeltaPhi(allJets[0]);
                          float dPtJet = -(allJets[1].Pt() - allJets[0].Pt());
                          float dRJet = allJets[1].DeltaR(allJets[0]);
  
                          histClass.jetDphi->Fill(dPhiJet);
                          if (not (Mmm < 101 and Mmm > 81)) histClass.jetDphi_anti_z_cut->Fill(dPhiJet);
                          if (Mmm < 101 and Mmm > 81) histClass.jetDphi_z_cut->Fill(dPhiJet);
                          histClass.jetDpt->Fill(dPtJet);
                          histClass.jetDeta->Fill(allJets[1].Eta() - allJets[0].Eta());
                          histClass.jetDr->Fill(dRJet);
                          histClass.jetSumPt->Fill(allJets[0].Pt() + allJets[1].Pt());
                        }
                       if (nBjets + njets > 1){

                          float dPhiLepJet = allJets[0].DeltaPhi(leptons[maxIndex]);
                          float dPtLepJet = abs(leptons[maxIndex].Pt() - allJets[0].Pt());
                          float dRLepJet = allJets[0].DeltaR(leptons[maxIndex]);
  
                          histClass.lepjetDphi->Fill(dPhiLepJet);
                          if (not (Mmm < 101 and Mmm > 81)) histClass.lepjetDphi_anti_z_cut->Fill(dPhiLepJet);
                          if (Mmm < 101 and Mmm > 81) histClass.lepjetDphi_z_cut->Fill(dPhiLepJet);
                          histClass.lepjetDpt->Fill(dPtLepJet);
                          histClass.lepjetDeta->Fill(leptons[maxIndex].Eta() - allJets[0].Eta());
                          histClass.lepjetDr->Fill(dRLepJet);
                          histClass.lepjetSumPt->Fill(allJets[0].Pt() + leptons[maxIndex].Pt());
                        }
                        if ( (Mmm < 101 and Mmm > 81)){
                          histClass.MET_hist_z_cut->Fill(MET_t);
                          histClass.METvsMmm_hist_z_cut->Fill(METvsMmm,weight);
                          histClass.SBM_hist_z_cut->Fill(SBMMax,weight);
                          histClass.HTLT_hist_z_cut->Fill(DHTLT,weight);
                        }

                      */

                       //Case 1 = Case 3 + Case 4 + Case 5
                       if(caseText == "1" and (nBjets < 1 || njets < 2) )continue;//N_jet >= 2, N_bjets >= 1 (Case 1)
                       //if(caseText == "na" and (nBjets < 1 || non_bJets < 2) )continue;//N_bjet >= 1, N_jet >= 2
                       if(caseText == "2" and (nBjets != 1 || nNonBjets != 0) )continue;//N_jet = 1, N_bjet = 1 (Case 2)
                       //if(caseText == "3" and (nBjets < 1 || njets == 2) )continue;//N_jet = 2, N_bjet >=1(1or2) (Case 3)
                       if(caseText == "3" and not (nBjets >= 1 && njets == 2) )continue;//N_jet = 2, N_bjet >=1(1or2) (Case 3)
                       if(caseText == "4" and (nBjets < 1 || nBjets > 2 || njets < 3) )continue;//N_jet >= 3, N_bjets = 1or2 (Case 4)
                       if(caseText == "5" and (nBjets < 3) )continue;//N_jet >=3, N_bjet >= 3 (Case 5)

                       //SR 1j
                       if(caseText == "b=1_j=0" and not (nBjets == 1 && nNonBjets == 0) )continue;
                       //CR 1j
                       if(caseText == "b=0_j=1" and not (nBjets == 0 && nNonBjets == 1) )continue;

                       //SR 2 j
                       if(caseText == "b=1,2_b+j=2" and not ( (nBjets == 1 || nBjets == 2) && njets == 2) )continue;
                       //CR 1 j
                       if(caseText == "b=0_b+j=2" and not ( (nBjets == 0 ) && njets == 2) )continue;

                       //1j
                       if(caseText == "1j" and not (njets == 1) )continue;


                       cutFlow.at(4) = cutFlow.at(4) + weight;



                       histClass.leading_lep_pt_second_lep_pt->Fill(leading_lep_pt,second_leading_lep_pt);


                       histClass.MET_hist->Fill(MET_t);
                       histClass.METvsMmm_hist->Fill(METvsMmm,weight);
                       histClass.mini_SBM_hist->Fill(SBMMin,weight);
                       histClass.SBM_hist->Fill(SBMMax,weight);
                       histClass.HTLT_hist->Fill(DHTLT,weight);





                        if(caseText == "b=1_j=0" || caseText ==  "2" || caseText ==  "b=0_j=1")
                       {
                        //std::cout << "1 "<< std::endl;
                        //(HT-LT) cut
                        if(DHTLT > -120)continue;
                        cutFlow.at(5) = cutFlow.at(5) + weight;
                        //METvsMmm (Normalized MET) cut
                        if(METvsMmm > .25)continue;
                        cutFlow.at(6) = cutFlow.at(6) + weight;
                        //TMB cut
                        if (SBM < 160) continue;
                        cutFlow.at(7) = cutFlow.at(7) + weight;
                       } else if (caseText == "b=1,2_b+j=2" || caseText ==  "b=0_b+j=2")
                       {
                        //std::cout << "2 "<< std::endl;
                        //(HT-LT) cut
                        if(DHTLT > -80)continue;
                        cutFlow.at(5) = cutFlow.at(5) + weight;
                        //METvsMmm (Normalized MET) cut
                        if(METvsMmm > .3)continue;
                        cutFlow.at(6) = cutFlow.at(6) + weight;
                        //TMB cut
                        if (SBM < 150) continue;
                        cutFlow.at(7) = cutFlow.at(7) + weight;
                       } else{
                         //std::cout << "what"<< std::endl;
                        continue;

                       }

                        histClass.dilep_mass_hist->Fill(Mmm, weight);

                       

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




                      // histClass.dilep_mass_hist->Fill(Mmm, weight);


                       //if(DHTLT<0){//<0 cut

                       //}
                       //}
                       //}
                       float Mm_1 = (leptons[0]).M();
                       float Mm_2 = (leptons[1]).M();
                       histClass.Mass_hist->Fill(Mm_1);
                       histClass.Mass_hist->Fill(Mm_2);

                       //          }

                      
                   }
               }
           }
       }
   } 
   std::cout << "count*weigth " << count*weight << std::endl;

std::vector<TH1F *> hists = {histClass.run_hist, histClass.mini_SBM_hist, histClass.mini_SBM_minus173_hist, histClass.leppT_hist, histClass.lepeta_hist, histClass.lepphi_hist, histClass.dPhi_dimuon_hist, histClass.dPhi_hist, histClass.dR_hist, histClass.mass_hist, histClass.jetpT_hist, histClass.jeteta_hist, histClass.bjetpT_hist, histClass.bjeteta_hist, histClass.NonbjetpT_hist, histClass.Nonbjeteta_hist, histClass.nbjet_hist, histClass.nNonbjet_hist, histClass.id_hist, histClass.MET_hist, histClass.dilep_mass_hist, histClass.SBM_hist, histClass.METvsMmm_hist, histClass.HTLT_hist, histClass.Mass_hist,
histClass.lepeta_p_hist,histClass.lepphi_p_hist,histClass.leppT_p_hist,histClass.lepeta_n_hist,histClass.lepphi_n_hist,histClass.leppT_n_hist,histClass.nLeptons,histClass.nElectrons,histClass.nMuons,histClass.jet1eta_n_hist,histClass.jet1phi_n_hist,histClass.jet1pT_n_hist,histClass.jet2eta_n_hist,histClass.jet2phi_n_hist,histClass.jet2pT_n_hist,histClass.nJet_hist,histClass.jet1NonB_atleast2_eta_n_hist,histClass.jet1NonB_atleast2_phi_n_hist,histClass.jet1NonB_atleast2_pT_n_hist,histClass.jet2NonB_atleast2_eta_n_hist,histClass.jet2NonB_atleast2_phi_n_hist,histClass.jet2NonB_atleast2_pT_n_hist,histClass.jet1B_atleast2_eta_n_hist,histClass.jet1B_atleast2_phi_n_hist,histClass.jet1B_atleast2_pT_n_hist,histClass.jet2B_atleast2_eta_n_hist,histClass.jet2B_atleast2_phi_n_hist,histClass.jet2B_atleast2_pT_n_hist,
histClass.lep_jet_min_deltaR, histClass.jetpT_noB_hist, histClass.jeteta_noB_hist,
histClass.dilep_mass_hist_before_cut, histClass.dilep_mass_hist_z_cut, histClass.dilep_mass_hist_z_cut_wide,histClass.MET_hist_before_cut,histClass.SBM_hist_before_cut,histClass.METvsMmm_hist_before_cut,histClass.HTLT_hist_before_cut,histClass.dPhi_hist_before_cut,
histClass.lep1pT_p_hist,histClass.lep1eta_p_hist,histClass.lep1phi_p_hist,histClass.lep1Iso_p_hist,histClass.lep2pT_p_hist,histClass.lep2eta_p_hist,histClass.lep2phi_p_hist,histClass.lep2Iso_p_hist,histClass.lepDphi,histClass.lepDpt,histClass.lepDeta,histClass.lepDr,histClass.lepSumPt, histClass.lepDphi_z_cut, histClass.lepDphi_iso_cut, histClass.lepDphi_anti_z_cut,
histClass.jetDphi, histClass.jetDphi_anti_z_cut, histClass.jetDphi_z_cut, histClass.jetDpt, histClass.jetDeta, histClass.jetDr, histClass.jetSumPt, histClass.lepjetDphi, histClass.lepjetDphi_anti_z_cut, histClass.lepjetDphi_z_cut, histClass.lepjetDpt, histClass.lepjetDeta, histClass.lepjetDr, histClass.lepjetSumPt, histClass.MET_hist_z_cut, histClass.METvsMmm_hist_z_cut, histClass.SBM_hist_z_cut, histClass.HTLT_hist_z_cut
};




    for(unsigned Nh=0; Nh<hists.size(); ++Nh) hists[Nh]->Write();

    histClass.njvsnbj_hist->Write();
    histClass.leading_lep_pt_second_lep_pt->Write();

    output->Close();

    return cutFlow;
}

