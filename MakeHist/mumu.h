//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon May 28 00:13:36 2018 by ROOT version 6.06/01
// from TTree t/
// found on file: /xrootd/store/user/hyeahyun/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_20180527_181453/180527_091521/0000/zp2mu_histos_1.root
//////////////////////////////////////////////////////////

#ifndef mumu_h
#define mumu_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class mumu {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   //Define totalN and Lumi
   Float_t         Lumi = 35.9;

   Float_t         TT_totalN = 79092400;
   Float_t         DY_totalN = 122055388;
   Float_t         ZZ_totalN = 990064;
   Float_t         WZ_totalN = 1000000;
   Float_t         WW_totalN = 1999000;
   Float_t         ST_top_totalN = 6952830;
   Float_t         ST_antitop_totalN = 6933094;
   
   // Declaration of leaf types
   UInt_t          run;
   UInt_t          lumi;
   UInt_t          event;
   Float_t         beamspot_x;
   Float_t         beamspot_x_err;
   Float_t         beamspot_y;
   Float_t         beamspot_y_err;
   Float_t         beamspot_z;
   Float_t         beamspot_z_err;
   Int_t           nvertices;
   Int_t           dil_chosen;
   Float_t         dil_mass;
   Float_t         dil_pt;
   Float_t         dil_rap;
   Float_t         dil_eta;
   Float_t         dil_phi;
   Float_t         dil_dR;
   Float_t         dil_dPhi;
   Float_t         dil_lep_pt[2];
   Float_t         cos_angle;
   Float_t         vertex_chi2;
   Float_t         cos_cs;
   Float_t         chi_dilepton;
   Float_t         phi_cs;
   Float_t         vertex_m;
   Float_t         vertex_m_err;
   Float_t         vertex_x;
   Float_t         vertex_x_err;
   Float_t         vertex_y;
   Float_t         vertex_y_err;
   Float_t         vertex_z;
   Float_t         vertex_z_err;
   Int_t           lep_id[2];
   Int_t           lep_heep_id[2];
   Float_t         lep_p[2];
   Float_t         lep_pt[2];
   Float_t         lep_pt_err[2];
   Float_t         lep_px[2];
   Float_t         lep_py[2];
   Float_t         lep_pz[2];
   Float_t         lep_E[2];
   Float_t         lep_eta[2];
   Float_t         lep_phi[2];
   Float_t         lep_dxy[2];
   Float_t         lep_dz[2];
   Float_t         lep_qOverPt[2];
   Float_t         lep_tk_p[2];
   Float_t         lep_tk_pt[2];
   Float_t         lep_tk_pt_err[2];
   Float_t         lep_tk_px[2];
   Float_t         lep_tk_py[2];
   Float_t         lep_tk_pz[2];
   Float_t         lep_tk_eta[2];
   Float_t         lep_tk_phi[2];
   Float_t         lep_tk_dz[2];
   Float_t         lep_tk_vz[2];
   Float_t         lep_tk_chi2[2];
   Float_t         lep_tk_ndf[2];
   Float_t         lep_tk_qOverPt[2];
   Float_t         lep_glb_p[2];
   Float_t         lep_glb_pt[2];
   Float_t         lep_glb_pt_err[2];
   Float_t         lep_glb_px[2];
   Float_t         lep_glb_py[2];
   Float_t         lep_glb_pz[2];
   Float_t         lep_glb_eta[2];
   Float_t         lep_glb_phi[2];
   Float_t         lep_glb_chi2[2];
   Float_t         lep_glb_ndf[2];
   Float_t         lep_glb_qOverPt[2];
   Float_t         lep_tpfms_p[2];
   Float_t         lep_tpfms_pt[2];
   Float_t         lep_tpfms_pt_err[2];
   Float_t         lep_tpfms_px[2];
   Float_t         lep_tpfms_py[2];
   Float_t         lep_tpfms_pz[2];
   Float_t         lep_tpfms_eta[2];
   Float_t         lep_tpfms_phi[2];
   Float_t         lep_tpfms_chi2[2];
   Float_t         lep_tpfms_ndf[2];
   Float_t         lep_tpfms_qOverPt[2];
   Float_t         lep_picky_p[2];
   Float_t         lep_picky_pt[2];
   Float_t         lep_picky_pt_err[2];
   Float_t         lep_picky_px[2];
   Float_t         lep_picky_py[2];
   Float_t         lep_picky_pz[2];
   Float_t         lep_picky_eta[2];
   Float_t         lep_picky_phi[2];
   Float_t         lep_picky_chi2[2];
   Float_t         lep_picky_ndf[2];
   Float_t         lep_picky_qOverPt[2];
   Float_t         lep_cocktail_p[2];
   Float_t         lep_cocktail_pt[2];
   Float_t         lep_cocktail_pt_err[2];
   Float_t         lep_cocktail_px[2];
   Float_t         lep_cocktail_py[2];
   Float_t         lep_cocktail_pz[2];
   Float_t         lep_cocktail_eta[2];
   Float_t         lep_cocktail_phi[2];
   Float_t         lep_cocktail_chi2[2];
   Float_t         lep_cocktail_ndf[2];
   Float_t         lep_cocktail_qOverPt[2];
   Short_t         lep_cocktail_choice[2];
   Float_t         lep_tuneP_p[2];
   Float_t         lep_tuneP_pt[2];
   Float_t         lep_tuneP_pt_err[2];
   Float_t         lep_tuneP_px[2];
   Float_t         lep_tuneP_py[2];
   Float_t         lep_tuneP_pz[2];
   Float_t         lep_tuneP_eta[2];
   Float_t         lep_tuneP_phi[2];
   Float_t         lep_tuneP_chi2[2];
   Float_t         lep_tuneP_ndf[2];
   Float_t         lep_tuneP_qOverPt[2];
   Float_t         lep_triggerMatchPt[2];
   Float_t         lep_triggerMatchEta[2];
   Float_t         lep_chi2dof[2];
   Float_t         lep_dB[2];
   Float_t         lep_sumPt[2];
   Float_t         lep_emEt[2];
   Float_t         lep_hadEt[2];
   Float_t         lep_hoEt[2];
   Float_t         lep_pfIso[2];
   Float_t         lep_pfIsoDB[2];
   Int_t           lep_timeNdof[2];
   Float_t         lep_timeInOut[2];
   Float_t         lep_timeOutIn[2];
   Float_t         lep_timeInOutErr[2];
   Float_t         lep_timeOutInErr[2];
   Float_t         lep_min_muon_dR[2];
   Short_t         lep_tk_numberOfValidTrackerHits[2];
   Short_t         lep_tk_numberOfValidTrackerLayers[2];
   Short_t         lep_tk_numberOfValidPixelHits[2];
   Short_t         lep_glb_numberOfValidTrackerHits[2];
   Short_t         lep_glb_numberOfValidTrackerLayers[2];
   Short_t         lep_glb_numberOfValidPixelHits[2];
   Short_t         lep_glb_numberOfValidMuonHits[2];
   Short_t         lep_glb_numberOfValidMuonDTHits[2];
   Short_t         lep_glb_numberOfValidMuonCSCHits[2];
   Short_t         lep_glb_numberOfValidMuonRPCHits[2];
   Short_t         lep_glb_muonStationsWithValidHits[2];
   Short_t         lep_glb_dtStationsWithValidHits[2];
   Short_t         lep_glb_cscStationsWithValidHits[2];
   Short_t         lep_glb_rpcStationsWithValidHits[2];
   Short_t         lep_glb_innermostMuonStationWithValidHits[2];
   Short_t         lep_glb_outermostMuonStationWithValidHits[2];
   Short_t         lep_numberOfMatches[2];
   Short_t         lep_numberOfMatchedStations[2];
   Short_t         lep_numberOfMatchedRPCLayers[2];
   Int_t           lep_stationMask[2];
   Int_t           lep_numberOfChambers[2];
   Int_t           lep_numberOfChambersNoRPC[2];
   Int_t           lep_stationGapMaskDistance[2];
   Int_t           lep_stationGapMaskPull[2];
   Bool_t          lep_isGlobalMuon[2];
   Bool_t          lep_isTrackerMuon[2];
   Bool_t          GoodDataRan;
   Bool_t          GoodVtx;
   Bool_t          METFilter;
   Float_t         met_pt;
   Float_t         met_phi;
   Int_t           nJets;
   Float_t         jet_pt[10];
   Float_t         jet_eta[10];
   Float_t         jet_phi[10];
   Float_t         jet_btag[10];
   Float_t         jet_px[10];
   Float_t         jet_py[10];
   Float_t         jet_pz[10];
   Float_t         jet_E[10];
   Float_t         genWeight;
   Float_t         gen_res_mass;
   Float_t         gen_res_pt;
   Float_t         gen_res_rap;
   Float_t         gen_res_eta;
   Float_t         gen_res_phi;
   Float_t         gen_dil_mass;
   Float_t         gen_dil_pt;
   Float_t         gen_dil_rap;
   Float_t         gen_dil_eta;
   Float_t         gen_dil_phi;
   Float_t         gen_dil_dR;
   Float_t         gen_dil_dPhi;
   Float_t         gen_lep_p[2];
   Float_t         gen_lep_pt[2];
   Float_t         gen_lep_px[2];
   Float_t         gen_lep_py[2];
   Float_t         gen_lep_pz[2];
   Float_t         gen_lep_E[2];
   Float_t         gen_lep_eta[2];
   Float_t         gen_lep_phi[2];
   Float_t         gen_lep_qOverPt[2];
   Float_t         gen_lep_noib_pt[2];
   Float_t         gen_lep_noib_px[2];
   Float_t         gen_lep_noib_py[2];
   Float_t         gen_lep_noib_pz[2];
   Float_t         gen_lep_noib_E[2];
   Float_t         gen_lep_noib_eta[2];
   Float_t         gen_lep_noib_phi[2];
   Float_t         gen_lep_noib_qOverPt[2];

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_lumi;   //!
   TBranch        *b_event;   //!
   TBranch        *b_beamspot_x;   //!
   TBranch        *b_beamspot_x_err;   //!
   TBranch        *b_beamspot_y;   //!
   TBranch        *b_beamspot_y_err;   //!
   TBranch        *b_beamspot_z;   //!
   TBranch        *b_beamspot_z_err;   //!
   TBranch        *b_nvertices;   //!
   TBranch        *b_dil_chosen;   //!
   TBranch        *b_dil_mass;   //!
   TBranch        *b_dil_pt;   //!
   TBranch        *b_dil_rap;   //!
   TBranch        *b_dil_eta;   //!
   TBranch        *b_dil_phi;   //!
   TBranch        *b_dil_dR;   //!
   TBranch        *b_dil_dPhi;   //!
   TBranch        *b_dil_lep_pt;   //!
   TBranch        *b_cos_angle;   //!
   TBranch        *b_vertex_chi2;   //!
   TBranch        *b_cos_cs;   //!
   TBranch        *b_chi_dilepton;   //!
   TBranch        *b_phi_cs;   //!
   TBranch        *b_vertex_m;   //!
   TBranch        *b_vertex_m_err;   //!
   TBranch        *b_vertex_x;   //!
   TBranch        *b_vertex_x_err;   //!
   TBranch        *b_vertex_y;   //!
   TBranch        *b_vertex_y_err;   //!
   TBranch        *b_vertex_z;   //!
   TBranch        *b_vertex_z_err;   //!
   TBranch        *b_lep_id;   //!
   TBranch        *b_lep_heep_id;   //!
   TBranch        *b_lep_p;   //!
   TBranch        *b_lep_pt;   //!
   TBranch        *b_lep_pt_err;   //!
   TBranch        *b_lep_px;   //!
   TBranch        *b_lep_py;   //!
   TBranch        *b_lep_pz;   //!
   TBranch        *b_lep_E;   //!
   TBranch        *b_lep_eta;   //!
   TBranch        *b_lep_phi;   //!
   TBranch        *b_lep_dxy;   //!
   TBranch        *b_lep_dz;   //!
   TBranch        *b_lep_qOverPt;   //!
   TBranch        *b_lep_tk_p;   //!
   TBranch        *b_lep_tk_pt;   //!
   TBranch        *b_lep_tk_pt_err;   //!
   TBranch        *b_lep_tk_px;   //!
   TBranch        *b_lep_tk_py;   //!
   TBranch        *b_lep_tk_pz;   //!
   TBranch        *b_lep_tk_eta;   //!
   TBranch        *b_lep_tk_phi;   //!
   TBranch        *b_lep_tk_dz;   //!
   TBranch        *b_lep_tk_vz;   //!
   TBranch        *b_lep_tk_chi2;   //!
   TBranch        *b_lep_tk_ndf;   //!
   TBranch        *b_lep_tk_qOverPt;   //!
   TBranch        *b_lep_glb_p;   //!
   TBranch        *b_lep_glb_pt;   //!
   TBranch        *b_lep_glb_pt_err;   //!
   TBranch        *b_lep_glb_px;   //!
   TBranch        *b_lep_glb_py;   //!
   TBranch        *b_lep_glb_pz;   //!
   TBranch        *b_lep_glb_eta;   //!
   TBranch        *b_lep_glb_phi;   //!
   TBranch        *b_lep_glb_chi2;   //!
   TBranch        *b_lep_glb_ndf;   //!
   TBranch        *b_lep_glb_qOverPt;   //!
   TBranch        *b_lep_tpfms_p;   //!
   TBranch        *b_lep_tpfms_pt;   //!
   TBranch        *b_lep_tpfms_pt_err;   //!
   TBranch        *b_lep_tpfms_px;   //!
   TBranch        *b_lep_tpfms_py;   //!
   TBranch        *b_lep_tpfms_pz;   //!
   TBranch        *b_lep_tpfms_eta;   //!
   TBranch        *b_lep_tpfms_phi;   //!
   TBranch        *b_lep_tpfms_chi2;   //!
   TBranch        *b_lep_tpfms_ndf;   //!
   TBranch        *b_lep_tpfms_qOverPt;   //!
   TBranch        *b_lep_picky_p;   //!
   TBranch        *b_lep_picky_pt;   //!
   TBranch        *b_lep_picky_pt_err;   //!
   TBranch        *b_lep_picky_px;   //!
   TBranch        *b_lep_picky_py;   //!
   TBranch        *b_lep_picky_pz;   //!
   TBranch        *b_lep_picky_eta;   //!
   TBranch        *b_lep_picky_phi;   //!
   TBranch        *b_lep_picky_chi2;   //!
   TBranch        *b_lep_picky_ndf;   //!
   TBranch        *b_lep_picky_qOverPt;   //!
   TBranch        *b_lep_cocktail_p;   //!
   TBranch        *b_lep_cocktail_pt;   //!
   TBranch        *b_lep_cocktail_pt_err;   //!
   TBranch        *b_lep_cocktail_px;   //!
   TBranch        *b_lep_cocktail_py;   //!
   TBranch        *b_lep_cocktail_pz;   //!
   TBranch        *b_lep_cocktail_eta;   //!
   TBranch        *b_lep_cocktail_phi;   //!
   TBranch        *b_lep_cocktail_chi2;   //!
   TBranch        *b_lep_cocktail_ndf;   //!
   TBranch        *b_lep_cocktail_qOverPt;   //!
   TBranch        *b_lep_cocktail_choice;   //!
   TBranch        *b_lep_tuneP_p;   //!
   TBranch        *b_lep_tuneP_pt;   //!
   TBranch        *b_lep_tuneP_pt_err;   //!
   TBranch        *b_lep_tuneP_px;   //!
   TBranch        *b_lep_tuneP_py;   //!
   TBranch        *b_lep_tuneP_pz;   //!
   TBranch        *b_lep_tuneP_eta;   //!
   TBranch        *b_lep_tuneP_phi;   //!
   TBranch        *b_lep_tuneP_chi2;   //!
   TBranch        *b_lep_tuneP_ndf;   //!
   TBranch        *b_lep_tuneP_qOverPt;   //!
   TBranch        *b_lep_triggerMatchPt;   //!
   TBranch        *b_lep_triggerMatchEta;   //!
   TBranch        *b_lep_chi2dof;   //!
   TBranch        *b_lep_dB;   //!
   TBranch        *b_lep_sumPt;   //!
   TBranch        *b_lep_emEt;   //!
   TBranch        *b_lep_hadEt;   //!
   TBranch        *b_lep_hoEt;   //!
   TBranch        *b_lep_pfIso;   //!
   TBranch        *b_lep_pfIsoDB;   //!
   TBranch        *b_lep_timeNdof;   //!
   TBranch        *b_lep_timeInOut;   //!
   TBranch        *b_lep_timeOutIn;   //!
   TBranch        *b_lep_timeInOutErr;   //!
   TBranch        *b_lep_timeOutInErr;   //!
   TBranch        *b_lep_min_muon_dR;   //!
   TBranch        *b_lep_tk_numberOfValidTrackerHits;   //!
   TBranch        *b_lep_tk_numberOfValidTrackerLayers;   //!
   TBranch        *b_lep_tk_numberOfValidPixelHits;   //!
   TBranch        *b_lep_glb_numberOfValidTrackerHits;   //!
   TBranch        *b_lep_glb_numberOfValidTrackerLayers;   //!
   TBranch        *b_lep_glb_numberOfValidPixelHits;   //!
   TBranch        *b_lep_glb_numberOfValidMuonHits;   //!
   TBranch        *b_lep_glb_numberOfValidMuonDTHits;   //!
   TBranch        *b_lep_glb_numberOfValidMuonCSCHits;   //!
   TBranch        *b_lep_glb_numberOfValidMuonRPCHits;   //!
   TBranch        *b_lep_glb_muonStationsWithValidHits;   //!
   TBranch        *b_lep_glb_dtStationsWithValidHits;   //!
   TBranch        *b_lep_glb_cscStationsWithValidHits;   //!
   TBranch        *b_lep_glb_rpcStationsWithValidHits;   //!
   TBranch        *b_lep_glb_innermostMuonStationWithValidHits;   //!
   TBranch        *b_lep_glb_outermostMuonStationWithValidHits;   //!
   TBranch        *b_lep_numberOfMatches;   //!
   TBranch        *b_lep_numberOfMatchedStations;   //!
   TBranch        *b_lep_numberOfMatchedRPCLayers;   //!
   TBranch        *b_lep_stationMask;   //!
   TBranch        *b_lep_numberOfChambers;   //!
   TBranch        *b_lep_numberOfChambersNoRPC;   //!
   TBranch        *b_lep_stationGapMaskDistance;   //!
   TBranch        *b_lep_stationGapMaskPull;   //!
   TBranch        *b_lep_isGlobalMuon;   //!
   TBranch        *b_lep_isTrackerMuon;   //!
   TBranch        *b_GoodDataRan;   //!
   TBranch        *b_GoodVtx;   //!
   TBranch        *b_METFilter;   //!
   TBranch        *b_met_pt;   //!
   TBranch        *b_met_phi;   //!
   TBranch        *b_nJets;   //!
   TBranch        *b_jet_pt;   //!
   TBranch        *b_jet_eta;   //!
   TBranch        *b_jet_phi;   //!
   TBranch        *b_jet_btag;   //!
   TBranch        *b_jet_px;   //!
   TBranch        *b_jet_py;   //!
   TBranch        *b_jet_pz;   //!
   TBranch        *b_jet_E;   //!
   TBranch        *b_genWeight;   //!
   TBranch        *b_gen_res_mass;   //!
   TBranch        *b_gen_res_pt;   //!
   TBranch        *b_gen_res_rap;   //!
   TBranch        *b_gen_res_eta;   //!
   TBranch        *b_gen_res_phi;   //!
   TBranch        *b_gen_dil_mass;   //!
   TBranch        *b_gen_dil_pt;   //!
   TBranch        *b_gen_dil_rap;   //!
   TBranch        *b_gen_dil_eta;   //!
   TBranch        *b_gen_dil_phi;   //!
   TBranch        *b_gen_dil_dR;   //!
   TBranch        *b_gen_dil_dPhi;   //!
   TBranch        *b_gen_lep_p;   //!
   TBranch        *b_gen_lep_pt;   //!
   TBranch        *b_gen_lep_px;   //!
   TBranch        *b_gen_lep_py;   //!
   TBranch        *b_gen_lep_pz;   //!
   TBranch        *b_gen_lep_E;   //!
   TBranch        *b_gen_lep_eta;   //!
   TBranch        *b_gen_lep_phi;   //!
   TBranch        *b_gen_lep_qOverPt;   //!
   TBranch        *b_gen_lep_noib_pt;   //!
   TBranch        *b_gen_lep_noib_px;   //!
   TBranch        *b_gen_lep_noib_py;   //!
   TBranch        *b_gen_lep_noib_pz;   //!
   TBranch        *b_gen_lep_noib_E;   //!
   TBranch        *b_gen_lep_noib_eta;   //!
   TBranch        *b_gen_lep_noib_phi;   //!
   TBranch        *b_gen_lep_noib_qOverPt;   //!

   mumu(TTree *tree=0);
   virtual ~mumu();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   //virtual void     Loop();
   virtual void     Loop(TString sample_name);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

//#ifdef mumu_cxx
//mumu::mumu(TTree *tree) : fChain(0) 
//{
//// if parameter tree is not specified (or zero), connect the file
//// used to generate this class and read the Tree.
//   if (tree == 0) {
///*      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/xrootd/store/user/hyeahyun/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_20180527_181453/180527_091521/0000/zp2mu_histos_1.root");
//      if (!f || !f->IsOpen()) {
//         f = new TFile("/xrootd/store/user/hyeahyun/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_20180527_181453/180527_091521/0000/zp2mu_histos_1.root");
//      }
//      TDirectory * dir = (TDirectory*)f->Get("/xrootd/store/user/hyeahyun/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_20180527_181453/180527_091521/0000/zp2mu_histos_1.root:/SimpleNtupler");
//      dir->GetObject("t",tree);
//*/
//#ifdef SINGLE_TRmumu
//       TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/afs/cern.ch/work/h/hyeahyun/public/signal/zp500.root");
//       if (!f || !f->IsOpen()) {
//           f = new TFile("/afs/cern.ch/work/h/hyeahyun/public/signal/zp500.root");
//       }
//       f->GetObject("SimpleNtupler/t","");
//
//#else // SINGLE_TRmumu
//       // The following code should be used if you want this class to access a chain of trees.
//       TChain *chain = new TChain("SimpleNtupler/t","");
//
//       chain->Add("/afs/cern.ch/work/h/hyeahyun/public/signal/zp200.root*.root/SimpleNtupler/t");
//       //chain->Add("/xrootd/store/user/hyeahyun/TTTo2L2Nu_TuneCUETP8M2_ttHtranche3_13TeV-powheg-pythia8/crab_20180719_234954/180719_145025/0001/*.root/SimpleNtupler/t");
//
//       tree = chain;
//#endif // SINGLE_TRmumu
//
//   }
//   Init(tree);
//}


#ifdef mumu_cxx
mumu::mumu(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/afs/cern.ch/work/h/hyeahyun/public/signal/zp500.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/afs/cern.ch/work/h/hyeahyun/public/signal/zp500.root");
      }
      f->GetObject("SimpleNtupler/t",tree);


   }
   Init(tree);
}


mumu::~mumu()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t mumu::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t mumu::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void mumu::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("lumi", &lumi, &b_lumi);
   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("beamspot_x", &beamspot_x, &b_beamspot_x);
   fChain->SetBranchAddress("beamspot_x_err", &beamspot_x_err, &b_beamspot_x_err);
   fChain->SetBranchAddress("beamspot_y", &beamspot_y, &b_beamspot_y);
   fChain->SetBranchAddress("beamspot_y_err", &beamspot_y_err, &b_beamspot_y_err);
   fChain->SetBranchAddress("beamspot_z", &beamspot_z, &b_beamspot_z);
   fChain->SetBranchAddress("beamspot_z_err", &beamspot_z_err, &b_beamspot_z_err);
   fChain->SetBranchAddress("nvertices", &nvertices, &b_nvertices);
   fChain->SetBranchAddress("dil_chosen", &dil_chosen, &b_dil_chosen);
   fChain->SetBranchAddress("dil_mass", &dil_mass, &b_dil_mass);
   fChain->SetBranchAddress("dil_pt", &dil_pt, &b_dil_pt);
   fChain->SetBranchAddress("dil_rap", &dil_rap, &b_dil_rap);
   fChain->SetBranchAddress("dil_eta", &dil_eta, &b_dil_eta);
   fChain->SetBranchAddress("dil_phi", &dil_phi, &b_dil_phi);
   fChain->SetBranchAddress("dil_dR", &dil_dR, &b_dil_dR);
   fChain->SetBranchAddress("dil_dPhi", &dil_dPhi, &b_dil_dPhi);
   fChain->SetBranchAddress("dil_lep_pt", dil_lep_pt, &b_dil_lep_pt);
   fChain->SetBranchAddress("cos_angle", &cos_angle, &b_cos_angle);
   fChain->SetBranchAddress("vertex_chi2", &vertex_chi2, &b_vertex_chi2);
   fChain->SetBranchAddress("cos_cs", &cos_cs, &b_cos_cs);
   fChain->SetBranchAddress("chi_dilepton", &chi_dilepton, &b_chi_dilepton);
   fChain->SetBranchAddress("phi_cs", &phi_cs, &b_phi_cs);
   fChain->SetBranchAddress("vertex_m", &vertex_m, &b_vertex_m);
   fChain->SetBranchAddress("vertex_m_err", &vertex_m_err, &b_vertex_m_err);
   fChain->SetBranchAddress("vertex_x", &vertex_x, &b_vertex_x);
   fChain->SetBranchAddress("vertex_x_err", &vertex_x_err, &b_vertex_x_err);
   fChain->SetBranchAddress("vertex_y", &vertex_y, &b_vertex_y);
   fChain->SetBranchAddress("vertex_y_err", &vertex_y_err, &b_vertex_y_err);
   fChain->SetBranchAddress("vertex_z", &vertex_z, &b_vertex_z);
   fChain->SetBranchAddress("vertex_z_err", &vertex_z_err, &b_vertex_z_err);
   fChain->SetBranchAddress("lep_id", lep_id, &b_lep_id);
   fChain->SetBranchAddress("lep_heep_id", lep_heep_id, &b_lep_heep_id);
   fChain->SetBranchAddress("lep_p", lep_p, &b_lep_p);
   fChain->SetBranchAddress("lep_pt", lep_pt, &b_lep_pt);
   fChain->SetBranchAddress("lep_pt_err", lep_pt_err, &b_lep_pt_err);
   fChain->SetBranchAddress("lep_px", lep_px, &b_lep_px);
   fChain->SetBranchAddress("lep_py", lep_py, &b_lep_py);
   fChain->SetBranchAddress("lep_pz", lep_pz, &b_lep_pz);
   fChain->SetBranchAddress("lep_E", lep_E, &b_lep_E);
   fChain->SetBranchAddress("lep_eta", lep_eta, &b_lep_eta);
   fChain->SetBranchAddress("lep_phi", lep_phi, &b_lep_phi);
   fChain->SetBranchAddress("lep_dxy", lep_dxy, &b_lep_dxy);
   fChain->SetBranchAddress("lep_dz", lep_dz, &b_lep_dz);
   fChain->SetBranchAddress("lep_qOverPt", lep_qOverPt, &b_lep_qOverPt);
   fChain->SetBranchAddress("lep_tk_p", lep_tk_p, &b_lep_tk_p);
   fChain->SetBranchAddress("lep_tk_pt", lep_tk_pt, &b_lep_tk_pt);
   fChain->SetBranchAddress("lep_tk_pt_err", lep_tk_pt_err, &b_lep_tk_pt_err);
   fChain->SetBranchAddress("lep_tk_px", lep_tk_px, &b_lep_tk_px);
   fChain->SetBranchAddress("lep_tk_py", lep_tk_py, &b_lep_tk_py);
   fChain->SetBranchAddress("lep_tk_pz", lep_tk_pz, &b_lep_tk_pz);
   fChain->SetBranchAddress("lep_tk_eta", lep_tk_eta, &b_lep_tk_eta);
   fChain->SetBranchAddress("lep_tk_phi", lep_tk_phi, &b_lep_tk_phi);
   fChain->SetBranchAddress("lep_tk_dz", lep_tk_dz, &b_lep_tk_dz);
   fChain->SetBranchAddress("lep_tk_vz", lep_tk_vz, &b_lep_tk_vz);
   fChain->SetBranchAddress("lep_tk_chi2", lep_tk_chi2, &b_lep_tk_chi2);
   fChain->SetBranchAddress("lep_tk_ndf", lep_tk_ndf, &b_lep_tk_ndf);
   fChain->SetBranchAddress("lep_tk_qOverPt", lep_tk_qOverPt, &b_lep_tk_qOverPt);
   fChain->SetBranchAddress("lep_glb_p", lep_glb_p, &b_lep_glb_p);
   fChain->SetBranchAddress("lep_glb_pt", lep_glb_pt, &b_lep_glb_pt);
   fChain->SetBranchAddress("lep_glb_pt_err", lep_glb_pt_err, &b_lep_glb_pt_err);
   fChain->SetBranchAddress("lep_glb_px", lep_glb_px, &b_lep_glb_px);
   fChain->SetBranchAddress("lep_glb_py", lep_glb_py, &b_lep_glb_py);
   fChain->SetBranchAddress("lep_glb_pz", lep_glb_pz, &b_lep_glb_pz);
   fChain->SetBranchAddress("lep_glb_eta", lep_glb_eta, &b_lep_glb_eta);
   fChain->SetBranchAddress("lep_glb_phi", lep_glb_phi, &b_lep_glb_phi);
   fChain->SetBranchAddress("lep_glb_chi2", lep_glb_chi2, &b_lep_glb_chi2);
   fChain->SetBranchAddress("lep_glb_ndf", lep_glb_ndf, &b_lep_glb_ndf);
   fChain->SetBranchAddress("lep_glb_qOverPt", lep_glb_qOverPt, &b_lep_glb_qOverPt);
   fChain->SetBranchAddress("lep_tpfms_p", lep_tpfms_p, &b_lep_tpfms_p);
   fChain->SetBranchAddress("lep_tpfms_pt", lep_tpfms_pt, &b_lep_tpfms_pt);
   fChain->SetBranchAddress("lep_tpfms_pt_err", lep_tpfms_pt_err, &b_lep_tpfms_pt_err);
   fChain->SetBranchAddress("lep_tpfms_px", lep_tpfms_px, &b_lep_tpfms_px);
   fChain->SetBranchAddress("lep_tpfms_py", lep_tpfms_py, &b_lep_tpfms_py);
   fChain->SetBranchAddress("lep_tpfms_pz", lep_tpfms_pz, &b_lep_tpfms_pz);
   fChain->SetBranchAddress("lep_tpfms_eta", lep_tpfms_eta, &b_lep_tpfms_eta);
   fChain->SetBranchAddress("lep_tpfms_phi", lep_tpfms_phi, &b_lep_tpfms_phi);
   fChain->SetBranchAddress("lep_tpfms_chi2", lep_tpfms_chi2, &b_lep_tpfms_chi2);
   fChain->SetBranchAddress("lep_tpfms_ndf", lep_tpfms_ndf, &b_lep_tpfms_ndf);
   fChain->SetBranchAddress("lep_tpfms_qOverPt", lep_tpfms_qOverPt, &b_lep_tpfms_qOverPt);
   fChain->SetBranchAddress("lep_picky_p", lep_picky_p, &b_lep_picky_p);
   fChain->SetBranchAddress("lep_picky_pt", lep_picky_pt, &b_lep_picky_pt);
   fChain->SetBranchAddress("lep_picky_pt_err", lep_picky_pt_err, &b_lep_picky_pt_err);
   fChain->SetBranchAddress("lep_picky_px", lep_picky_px, &b_lep_picky_px);
   fChain->SetBranchAddress("lep_picky_py", lep_picky_py, &b_lep_picky_py);
   fChain->SetBranchAddress("lep_picky_pz", lep_picky_pz, &b_lep_picky_pz);
   fChain->SetBranchAddress("lep_picky_eta", lep_picky_eta, &b_lep_picky_eta);
   fChain->SetBranchAddress("lep_picky_phi", lep_picky_phi, &b_lep_picky_phi);
   fChain->SetBranchAddress("lep_picky_chi2", lep_picky_chi2, &b_lep_picky_chi2);
   fChain->SetBranchAddress("lep_picky_ndf", lep_picky_ndf, &b_lep_picky_ndf);
   fChain->SetBranchAddress("lep_picky_qOverPt", lep_picky_qOverPt, &b_lep_picky_qOverPt);
   fChain->SetBranchAddress("lep_cocktail_p", lep_cocktail_p, &b_lep_cocktail_p);
   fChain->SetBranchAddress("lep_cocktail_pt", lep_cocktail_pt, &b_lep_cocktail_pt);
   fChain->SetBranchAddress("lep_cocktail_pt_err", lep_cocktail_pt_err, &b_lep_cocktail_pt_err);
   fChain->SetBranchAddress("lep_cocktail_px", lep_cocktail_px, &b_lep_cocktail_px);
   fChain->SetBranchAddress("lep_cocktail_py", lep_cocktail_py, &b_lep_cocktail_py);
   fChain->SetBranchAddress("lep_cocktail_pz", lep_cocktail_pz, &b_lep_cocktail_pz);
   fChain->SetBranchAddress("lep_cocktail_eta", lep_cocktail_eta, &b_lep_cocktail_eta);
   fChain->SetBranchAddress("lep_cocktail_phi", lep_cocktail_phi, &b_lep_cocktail_phi);
   fChain->SetBranchAddress("lep_cocktail_chi2", lep_cocktail_chi2, &b_lep_cocktail_chi2);
   fChain->SetBranchAddress("lep_cocktail_ndf", lep_cocktail_ndf, &b_lep_cocktail_ndf);
   fChain->SetBranchAddress("lep_cocktail_qOverPt", lep_cocktail_qOverPt, &b_lep_cocktail_qOverPt);
   fChain->SetBranchAddress("lep_cocktail_choice", lep_cocktail_choice, &b_lep_cocktail_choice);
   fChain->SetBranchAddress("lep_tuneP_p", lep_tuneP_p, &b_lep_tuneP_p);
   fChain->SetBranchAddress("lep_tuneP_pt", lep_tuneP_pt, &b_lep_tuneP_pt);
   fChain->SetBranchAddress("lep_tuneP_pt_err", lep_tuneP_pt_err, &b_lep_tuneP_pt_err);
   fChain->SetBranchAddress("lep_tuneP_px", lep_tuneP_px, &b_lep_tuneP_px);
   fChain->SetBranchAddress("lep_tuneP_py", lep_tuneP_py, &b_lep_tuneP_py);
   fChain->SetBranchAddress("lep_tuneP_pz", lep_tuneP_pz, &b_lep_tuneP_pz);
   fChain->SetBranchAddress("lep_tuneP_eta", lep_tuneP_eta, &b_lep_tuneP_eta);
   fChain->SetBranchAddress("lep_tuneP_phi", lep_tuneP_phi, &b_lep_tuneP_phi);
   fChain->SetBranchAddress("lep_tuneP_chi2", lep_tuneP_chi2, &b_lep_tuneP_chi2);
   fChain->SetBranchAddress("lep_tuneP_ndf", lep_tuneP_ndf, &b_lep_tuneP_ndf);
   fChain->SetBranchAddress("lep_tuneP_qOverPt", lep_tuneP_qOverPt, &b_lep_tuneP_qOverPt);
   fChain->SetBranchAddress("lep_triggerMatchPt", lep_triggerMatchPt, &b_lep_triggerMatchPt);
   fChain->SetBranchAddress("lep_triggerMatchEta", lep_triggerMatchEta, &b_lep_triggerMatchEta);
   fChain->SetBranchAddress("lep_chi2dof", lep_chi2dof, &b_lep_chi2dof);
   fChain->SetBranchAddress("lep_dB", lep_dB, &b_lep_dB);
   fChain->SetBranchAddress("lep_sumPt", lep_sumPt, &b_lep_sumPt);
   fChain->SetBranchAddress("lep_emEt", lep_emEt, &b_lep_emEt);
   fChain->SetBranchAddress("lep_hadEt", lep_hadEt, &b_lep_hadEt);
   fChain->SetBranchAddress("lep_hoEt", lep_hoEt, &b_lep_hoEt);
   fChain->SetBranchAddress("lep_pfIso", lep_pfIso, &b_lep_pfIso);
   fChain->SetBranchAddress("lep_pfIsoDB", lep_pfIsoDB, &b_lep_pfIsoDB);
   fChain->SetBranchAddress("lep_timeNdof", lep_timeNdof, &b_lep_timeNdof);
   fChain->SetBranchAddress("lep_timeInOut", lep_timeInOut, &b_lep_timeInOut);
   fChain->SetBranchAddress("lep_timeOutIn", lep_timeOutIn, &b_lep_timeOutIn);
   fChain->SetBranchAddress("lep_timeInOutErr", lep_timeInOutErr, &b_lep_timeInOutErr);
   fChain->SetBranchAddress("lep_timeOutInErr", lep_timeOutInErr, &b_lep_timeOutInErr);
   fChain->SetBranchAddress("lep_min_muon_dR", lep_min_muon_dR, &b_lep_min_muon_dR);
   fChain->SetBranchAddress("lep_tk_numberOfValidTrackerHits", lep_tk_numberOfValidTrackerHits, &b_lep_tk_numberOfValidTrackerHits);
   fChain->SetBranchAddress("lep_tk_numberOfValidTrackerLayers", lep_tk_numberOfValidTrackerLayers, &b_lep_tk_numberOfValidTrackerLayers);
   fChain->SetBranchAddress("lep_tk_numberOfValidPixelHits", lep_tk_numberOfValidPixelHits, &b_lep_tk_numberOfValidPixelHits);
   fChain->SetBranchAddress("lep_glb_numberOfValidTrackerHits", lep_glb_numberOfValidTrackerHits, &b_lep_glb_numberOfValidTrackerHits);
   fChain->SetBranchAddress("lep_glb_numberOfValidTrackerLayers", lep_glb_numberOfValidTrackerLayers, &b_lep_glb_numberOfValidTrackerLayers);
   fChain->SetBranchAddress("lep_glb_numberOfValidPixelHits", lep_glb_numberOfValidPixelHits, &b_lep_glb_numberOfValidPixelHits);
   fChain->SetBranchAddress("lep_glb_numberOfValidMuonHits", lep_glb_numberOfValidMuonHits, &b_lep_glb_numberOfValidMuonHits);
   fChain->SetBranchAddress("lep_glb_numberOfValidMuonDTHits", lep_glb_numberOfValidMuonDTHits, &b_lep_glb_numberOfValidMuonDTHits);
   fChain->SetBranchAddress("lep_glb_numberOfValidMuonCSCHits", lep_glb_numberOfValidMuonCSCHits, &b_lep_glb_numberOfValidMuonCSCHits);
   fChain->SetBranchAddress("lep_glb_numberOfValidMuonRPCHits", lep_glb_numberOfValidMuonRPCHits, &b_lep_glb_numberOfValidMuonRPCHits);
   fChain->SetBranchAddress("lep_glb_muonStationsWithValidHits", lep_glb_muonStationsWithValidHits, &b_lep_glb_muonStationsWithValidHits);
   fChain->SetBranchAddress("lep_glb_dtStationsWithValidHits", lep_glb_dtStationsWithValidHits, &b_lep_glb_dtStationsWithValidHits);
   fChain->SetBranchAddress("lep_glb_cscStationsWithValidHits", lep_glb_cscStationsWithValidHits, &b_lep_glb_cscStationsWithValidHits);
   fChain->SetBranchAddress("lep_glb_rpcStationsWithValidHits", lep_glb_rpcStationsWithValidHits, &b_lep_glb_rpcStationsWithValidHits);
   fChain->SetBranchAddress("lep_glb_innermostMuonStationWithValidHits", lep_glb_innermostMuonStationWithValidHits, &b_lep_glb_innermostMuonStationWithValidHits);
   fChain->SetBranchAddress("lep_glb_outermostMuonStationWithValidHits", lep_glb_outermostMuonStationWithValidHits, &b_lep_glb_outermostMuonStationWithValidHits);
   fChain->SetBranchAddress("lep_numberOfMatches", lep_numberOfMatches, &b_lep_numberOfMatches);
   fChain->SetBranchAddress("lep_numberOfMatchedStations", lep_numberOfMatchedStations, &b_lep_numberOfMatchedStations);
   fChain->SetBranchAddress("lep_numberOfMatchedRPCLayers", lep_numberOfMatchedRPCLayers, &b_lep_numberOfMatchedRPCLayers);
   fChain->SetBranchAddress("lep_stationMask", lep_stationMask, &b_lep_stationMask);
   fChain->SetBranchAddress("lep_numberOfChambers", lep_numberOfChambers, &b_lep_numberOfChambers);
   fChain->SetBranchAddress("lep_numberOfChambersNoRPC", lep_numberOfChambersNoRPC, &b_lep_numberOfChambersNoRPC);
   fChain->SetBranchAddress("lep_stationGapMaskDistance", lep_stationGapMaskDistance, &b_lep_stationGapMaskDistance);
   fChain->SetBranchAddress("lep_stationGapMaskPull", lep_stationGapMaskPull, &b_lep_stationGapMaskPull);
   fChain->SetBranchAddress("lep_isGlobalMuon", lep_isGlobalMuon, &b_lep_isGlobalMuon);
   fChain->SetBranchAddress("lep_isTrackerMuon", lep_isTrackerMuon, &b_lep_isTrackerMuon);
   fChain->SetBranchAddress("GoodDataRan", &GoodDataRan, &b_GoodDataRan);
   fChain->SetBranchAddress("GoodVtx", &GoodVtx, &b_GoodVtx);
   fChain->SetBranchAddress("METFilter", &METFilter, &b_METFilter);
   fChain->SetBranchAddress("met_pt", &met_pt, &b_met_pt);
   fChain->SetBranchAddress("met_phi", &met_phi, &b_met_phi);
   fChain->SetBranchAddress("nJets", &nJets, &b_nJets);
   fChain->SetBranchAddress("jet_pt", jet_pt, &b_jet_pt);
   fChain->SetBranchAddress("jet_eta", jet_eta, &b_jet_eta);
   fChain->SetBranchAddress("jet_phi", jet_phi, &b_jet_phi);
   fChain->SetBranchAddress("jet_btag", jet_btag, &b_jet_btag);
   fChain->SetBranchAddress("jet_px", jet_px, &b_jet_px);
   fChain->SetBranchAddress("jet_py", jet_py, &b_jet_py);
   fChain->SetBranchAddress("jet_pz", jet_pz, &b_jet_pz);
   fChain->SetBranchAddress("jet_E", jet_E, &b_jet_E);
   fChain->SetBranchAddress("genWeight", &genWeight, &b_genWeight);
   fChain->SetBranchAddress("gen_res_mass", &gen_res_mass, &b_gen_res_mass);
   fChain->SetBranchAddress("gen_res_pt", &gen_res_pt, &b_gen_res_pt);
   fChain->SetBranchAddress("gen_res_rap", &gen_res_rap, &b_gen_res_rap);
   fChain->SetBranchAddress("gen_res_eta", &gen_res_eta, &b_gen_res_eta);
   fChain->SetBranchAddress("gen_res_phi", &gen_res_phi, &b_gen_res_phi);
   fChain->SetBranchAddress("gen_dil_mass", &gen_dil_mass, &b_gen_dil_mass);
   fChain->SetBranchAddress("gen_dil_pt", &gen_dil_pt, &b_gen_dil_pt);
   fChain->SetBranchAddress("gen_dil_rap", &gen_dil_rap, &b_gen_dil_rap);
   fChain->SetBranchAddress("gen_dil_eta", &gen_dil_eta, &b_gen_dil_eta);
   fChain->SetBranchAddress("gen_dil_phi", &gen_dil_phi, &b_gen_dil_phi);
   fChain->SetBranchAddress("gen_dil_dR", &gen_dil_dR, &b_gen_dil_dR);
   fChain->SetBranchAddress("gen_dil_dPhi", &gen_dil_dPhi, &b_gen_dil_dPhi);
   fChain->SetBranchAddress("gen_lep_p", gen_lep_p, &b_gen_lep_p);
   fChain->SetBranchAddress("gen_lep_pt", gen_lep_pt, &b_gen_lep_pt);
   fChain->SetBranchAddress("gen_lep_px", gen_lep_px, &b_gen_lep_px);
   fChain->SetBranchAddress("gen_lep_py", gen_lep_py, &b_gen_lep_py);
   fChain->SetBranchAddress("gen_lep_pz", gen_lep_pz, &b_gen_lep_pz);
   fChain->SetBranchAddress("gen_lep_E", gen_lep_E, &b_gen_lep_E);
   fChain->SetBranchAddress("gen_lep_eta", gen_lep_eta, &b_gen_lep_eta);
   fChain->SetBranchAddress("gen_lep_phi", gen_lep_phi, &b_gen_lep_phi);
   fChain->SetBranchAddress("gen_lep_qOverPt", gen_lep_qOverPt, &b_gen_lep_qOverPt);
   fChain->SetBranchAddress("gen_lep_noib_pt", gen_lep_noib_pt, &b_gen_lep_noib_pt);
   fChain->SetBranchAddress("gen_lep_noib_px", gen_lep_noib_px, &b_gen_lep_noib_px);
   fChain->SetBranchAddress("gen_lep_noib_py", gen_lep_noib_py, &b_gen_lep_noib_py);
   fChain->SetBranchAddress("gen_lep_noib_pz", gen_lep_noib_pz, &b_gen_lep_noib_pz);
   fChain->SetBranchAddress("gen_lep_noib_E", gen_lep_noib_E, &b_gen_lep_noib_E);
   fChain->SetBranchAddress("gen_lep_noib_eta", gen_lep_noib_eta, &b_gen_lep_noib_eta);
   fChain->SetBranchAddress("gen_lep_noib_phi", gen_lep_noib_phi, &b_gen_lep_noib_phi);
   fChain->SetBranchAddress("gen_lep_noib_qOverPt", gen_lep_noib_qOverPt, &b_gen_lep_noib_qOverPt);
   Notify();
}

Bool_t mumu::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void mumu::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t mumu::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef mumu_cxx
