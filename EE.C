#define EE_cxx
#include "EE.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void EE::Loop()
{
//   In a ROOT session, you can do:
//      root> .L EE.C
//      root> EE t
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
//    ientry for DYree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   TFile *output = new TFile("DY_EE.root","recreate");

   TH1F *run_DY = new TH1F("run_DY","run",3,0,3);
   TH1F *leppT_DY = new TH1F("leppT_DY","lepton pt",100,0,500);
   
   TH1F *lepeta_DY = new TH1F("lepeta_DY","lepton eta",20,-3,3);
   
   TH1F *lepphi_DY = new TH1F("lepphi_DY","lepton phi",20,-3.5,3.5);
   
   TH1F *dPhi_DY = new TH1F("dPhi_DY","delta phi_{e,#mu}",50,-4,4);
   TH1F *dR_DY = new TH1F("dR_DY","delta R_{e,#mu}",50,0,5);
   TH1F *ee_mass_DY = new TH1F("ee_mass_DY","Mass_{e,e}",50,0,500);
  
   TH1F *eleIso_DY = new TH1F("eleIso_DY","electron isolation",100,0,400);

   TH1F *jetpT_DY = new TH1F("jetpT_DY","jet pT",100,0,500);
   TH1F *jeteta_DY = new TH1F("jeteta_DY","jet eta",20,-5,5);
   
   TH1F *bjetpT_DY = new TH1F("bjetpT_DY","b-jet pT",100,0,500);
   TH1F *bjeteta_DY = new TH1F("bjeteta_DY","b-jet eta",20,-5,5);

   TH1F *LeadJetpT_DY = new TH1F("LeadJetpT_DY","Leading b-jet pT",50,0,500);
   TH1F *SecJetpT_DY = new TH1F("SecJetpT_DY","2nd leading b-jet pT",50,0,500);
   
//   TH1F *btagEvent_DY = new TH1F("btagEvent_DY","btagEvent",100,0,500);

   TH1F *njet_DY = new TH1F("njet_DY","Number of jet",11,0,11);
   TH1F *nbjet_DY = new TH1F("nbjet_DY","Number of b-jet",11,0,11);
   TH1F *id_DY = new TH1F("id_DY","particle id",30,-15,15);
   
   TH1F *MET_DY = new TH1F("MET_DY","Missing ET",100,0,1000);
   TH1F *dilep_mass_DY = new TH1F("dilep_mass_DY","dilepton mass",100,0,1000);
   
   TH1F *SBM_DY = new TH1F("SBM_DY","max(SBM)",100,0,300);
   TH1F *METvsMmm_DY = new TH1F("METvsMmm_DY","E^{miss}_{T}/M(#mu^{+}#mu^{-})",100,0,1);
   TH1F *HTLT_DY = new TH1F("HTLT_DY","HT-LT",100,-500,500);

   TH1F *Mass_DY = new TH1F("Mass_DY","Lepton mass(M_{e})",100,0,500);
   
   TH2F *njvsnbj_DY = new TH2F("njvsnbj_DY","njet vs nbjet",10,0,10,5,0,5);
//   TH2F *bjetpT_dR_DY = new TH2F("bjetpT_dR_DY","b-jet pT vs DeltaR",100,0,500,50,0,5);
//   TH2F *bjetpT_elepT_DY = new TH2F("bjetpT_elepT_DY","b-jet pT vs electron pT",100,0,500,100,0,500);
//   TH2F *bjetpT_mupT_DY = new TH2F("bjetpT_mupT_DY","b-jet pT vs muon pT",100,0,500,100,0,500);
   
   Long64_t nentries = fChain->GetEntriesFast();

   float totalN = 122055388;
   float Lumi = 36.3;
   float cs = 5765.4;
   float weight = Lumi * cs/totalN;

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

      run_DY->Fill(run);

      //MET_DY->Fill(met_pt);
      //dilep_mass_DY->Fill(dil_mass);

      if(lep_pt[0] > 53 &&lep_pt[1] > 53){
      if(dil_dR > 0.1){
      if(fabs(lep_dz[0])<0.5 && fabs(lep_dz[1])<0.5){

	  
	 
	  //Opposite sign
	  if(lep_id[0] * lep_id[1] < 0){
	 
      //if(dil_chosen != 0) continue;
	      //particle id
	      int id1 = lep_id[0];
	      int id2 = lep_id[1];

	      id_DY->Fill(id1);
	      id_DY->Fill(id2);
	      
	      float Lep_pt[2] = {-999,-999};
	      float Lep_eta[2] = {-999,-999};
	      float Lep_phi[2] = {-999,-999};
	      float Lep_Iso[2] = {-999,-999};
	      float Lep_E[2] = {-999,-999};

	      float Dil_dPhi[1] = {-999};
	      float Dil_dR[1] = {-999};
	      float Dil_mass[1] = {-999};
	      
	      float MET[1] = {-999};
	      
	      int Njet = 0;
	      int Nbjet = 0;
	      int Nnon_bjet = 0;
	      
	      vector<float> bJet_pt; bJet_pt.clear();
	      vector<float> bJet_eta; bJet_eta.clear();
	      vector<float> bJet_phi; bJet_phi.clear();
	      vector<float> bJet_E; bJet_E.clear();

	      vector<float> Jet_pt; Jet_pt.clear();
	      vector<float> Jet_eta; Jet_eta.clear();
	      vector<float> Jet_phi; Jet_phi.clear();
	      vector<float> Jet_E; Jet_E.clear();
	//if(nJets==0)cout<<"Jet: "<<nJets<<endl;
		  for(int i=0; i<nJets; i++){
		      if(jet_pt[i] > 30){ //jet pT > 30GeV
			  if(jet_eta[i] < 5.0){ // jet |eta| <5.0

			      Lep_pt[0] = lep_pt[0];

			      //Number of jet
			      Njet++;

			      if(jet_btag[i] >= 0.8484) { //b-tagging(WP=0.8484)
				  Nbjet++;
				  bJet_pt.push_back(jet_pt[i]);
				  bJet_eta.push_back(jet_eta[i]);
				  bJet_phi.push_back(jet_phi[i]);
				  bJet_E.push_back(jet_E[i]);
			      }
			      else Nnon_bjet ++;
			  }
		      }

		  }
	     // }

	      //if(Njet == 0){cout<<"entry : "<<jentry << endl;}
	     // if(Lep_pt[0] == -999) continue;


	      if(Njet < 2) continue;//Number of jet >=2

		 //cout<<"NJet: "<<Njet<<endl; 
	      njet_DY->Fill(Njet);
	      nbjet_DY->Fill(Nbjet);

	      njvsnbj_DY->Fill(Nnon_bjet,Nbjet);

	      //if(Nbjet < 1) continue;// >= 1 b-jet

	      for(int i=0; i<nJets; i++){
		  if(jet_eta[i] == -999.) continue;
		  if(jet_phi[i] == -999.) continue;
		  if(jet_pt[i] <= 30) continue; //jet pT > 30GeV
		  if(jet_eta[i] >= 5.0) continue; // jet |eta| < 5.0
		  
		  
		  //lepton
		  Lep_pt[0] = lep_pt[0];
		  Lep_pt[1] = lep_pt[1];
		  
		  Lep_eta[0] = lep_eta[0];
		  Lep_eta[1] = lep_eta[1];
		  
		  Lep_phi[0] = lep_phi[0];
		  Lep_phi[1] = lep_phi[1];
		  
		  Lep_Iso[1] = lep_pfIso[0];
		  Lep_Iso[1] = lep_pfIso[1];

		  Lep_E[0] = lep_E[0];
		  Lep_E[1] = lep_E[1];

		  //di-lepton(e,mu)
		  Dil_dPhi[0] = dil_dPhi;
		  Dil_dR[0] = dil_dR;
		  Dil_mass[0] = dil_mass;

		  //Missing ET
		  MET[0] = met_pt;
		  
		  //jet
		  Jet_pt.push_back(jet_pt[i]);
		  Jet_eta.push_back(jet_eta[i]);
		  Jet_phi.push_back(jet_phi[i]);
          Jet_E.push_back(jet_E[i]);
		  }
	      
	      
	      if(Lep_pt[0] == -999) continue;
	      
	  
	  //pT
	  float pt1 = Lep_pt[0];
	  float pt2 = Lep_pt[1];


	  leppT_DY->Fill(pt1);
	  leppT_DY->Fill(pt2);

	  //Iso
		  eleIso_DY->Fill(Lep_Iso[1]);
		  eleIso_DY->Fill(Lep_Iso[0]);
	 

	  //e-mu dPhi and dR, e-mu mass
	  dPhi_DY->Fill(Dil_dPhi[0]);
	  dR_DY->Fill(Dil_dR[0]);
	  ee_mass_DY->Fill(Dil_mass[0]);

	  //eta
	  float eta1 = Lep_eta[0];
	  float eta2 = Lep_eta[1];


	  lepeta_DY->Fill(eta1);
	  lepeta_DY->Fill(eta2);

	  //phi
	  float phi1 = Lep_phi[0];
	  float phi2 = Lep_phi[1];


	  lepphi_DY->Fill(phi1);
	  lepphi_DY->Fill(phi2);

	 //leading and 2nd leading declaration 
	  float leadjet_pT = -999;
	  float secjet_pT = -999;

	  //dR(electron,b-jet)..what is closest electron?
	  //float EleBjet_dR;

//		    btagEvent_DY->Fill(lep_pt[0]);
//		    btagEvent_DY->Fill(lep_pt[1]);

		    //jet pT and jet eta(if Number of b-jet = 1, it is possible to use)
		    for(int k=0; k<Jet_pt.size(); k++){
			
		    jetpT_DY->Fill(Jet_pt[k]);
		    jeteta_DY->Fill(Jet_eta[k]);
		    }


		    //all jet pT sum^2
		    float sum_jetpT = 0.;

		    //leading jet
		    for(int j=0; j<bJet_pt.size(); j++){
		        bjetpT_DY->Fill(bJet_pt[j]); // all b jet pT
		        bjeteta_DY->Fill(bJet_eta[j]); // all b jet pT

			//all jet pT sum
			sum_jetpT = sum_jetpT + sqrt(Jet_pt[j]*jet_pt[j]);


			//b-jet pT vs dR
			float dphi = Lep_phi[1] - bJet_phi[j];
			float deta = Lep_eta[1] - bJet_eta[j];
			if(dphi < -TMath::Pi()) dphi = dphi + 2.*TMath::Pi();
			if(dphi >= TMath::Pi()) dphi = dphi - 2.*TMath::Pi();
			float EleBjet_dR = sqrt(pow(dphi,2) + pow(deta,2));//Delta R(electron,b-jet)...what is closect electron?
			//bjetpT_dR_DY->Fill(bJet_pt[j],EleBjet_dR);

			//b-jet pT vs electron pT
			//bjetpT_elepT_DY->Fill(bJet_pt[j],Lep_pt[1]);

			//b-jet pT vs muon pT
			//bjetpT_mupT_DY->Fill(bJet_pt[j],Lep_pt[0]);
			
			if(bJet_pt[j] >= leadjet_pT) leadjet_pT = bJet_pt[j];
			else leadjet_pT = leadjet_pT;
		    }
	      
		    if(leadjet_pT == -999) continue;
		    //2nd leading jet
	  	    for(int u=0; u<bJet_pt.size(); u++){
		  //if(jet_pt[i] >= leadjet_pT) continue;
		  	if(secjet_pT < bJet_pt[u] && bJet_pt[u] < leadjet_pT) secjet_pT = bJet_pt[u];
			else secjet_pT = secjet_pT;
		    }
	      
	  //if(leadjet_pT < 30) continue;
	  //if(secjet_pT < 30) continue;
	      

      //SBM

            if(Nbjet == 1 || Nbjet == 2){

                int Jet2_nonB=-1;
                float Jet2_nonB_PT=0.;

                for(unsigned Nj=0; Nj<Jet_pt.size(); ++Nj){
                    if(Jet2_nonB_PT<Jet_pt[Nj]){
                        if(Jet2_nonB_PT != bJet_pt[0]){
                            Jet2_nonB=Nj;
                            Jet2_nonB_PT=jet_pt[Nj];
                        }
                    }
                }

                //const double muon_mass = 0.1056583715;
                const double ele_mass = 0.0005109989461;

                TLorentzVector lep1;
                TLorentzVector lep2;

                TLorentzVector bjet1;
                TLorentzVector bjet2;

                TLorentzVector met_p4;

                if(Nbjet == 2){

                    bjet1.SetPtEtaPhiE(bJet_pt[0], bJet_eta[0], bJet_phi[0], bJet_E[0]);
                    lep1.SetPtEtaPhiE(Lep_pt[0], Lep_eta[0], Lep_phi[0], Lep_E[0]);

                    bjet2.SetPtEtaPhiE(bJet_pt[1], bJet_eta[1], bJet_phi[1], bJet_E[1]);
                    lep2.SetPtEtaPhiE(Lep_pt[1], Lep_eta[1], Lep_phi[1], Lep_E[1]);
                }

                else if(Nbjet == 1){
                    bjet1.SetPtEtaPhiE(bJet_pt[0], bJet_eta[0], bJet_phi[0], bJet_E[0]);
                    lep1.SetPtEtaPhiE(Lep_pt[0], Lep_eta[0], Lep_phi[0], Lep_E[0]);

                    bjet2.SetPtEtaPhiE(Jet_pt[Jet2_nonB], Jet_eta[Jet2_nonB], Jet_phi[Jet2_nonB], Jet_E[Jet2_nonB]);
                    lep2.SetPtEtaPhiE(Lep_pt[1], Lep_eta[1], Lep_phi[1], Lep_E[1]);
                }

                float lep1_jet1_mass = ((lep1)+(bjet1)).M();
                float lep1_jet2_mass = ((lep1)+(bjet2)).M();
                float lep2_jet1_mass = ((lep2)+(bjet1)).M();
                float lep2_jet2_mass = ((lep2)+(bjet2)).M();

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

                //Fill max SBM
                //if(SBM1>170. || SBM2>170.){//>170 cut
                    if(SBM1<SBM2)SBM_DY->Fill(SBM2);
                    else SBM_DY->Fill(SBM1);



                    //METvsMmm
                    //if(Nnon_bjet == 1 && Nbjet == 0){
                    float Mmm = ((lep1)+(lep2)).M();
                    float MET_t = MET[0];
                    float METvsMmm = MET_t/Mmm ;
                    //if(METvsMmm<0.2){ // <0.2 cut
                        METvsMmm_DY->Fill(METvsMmm);


                        MET_DY->Fill(MET_t);
                        dilep_mass_DY->Fill(Mmm);
                        //}
                        //HT-LT
                        float DHTLT = -999.;
                        if(Nbjet == 2){
                            DHTLT = (bJet_pt[0]+bJet_pt[1]) - (Lep_pt[0]+Lep_pt[1]);
                        }
                        else if(Nbjet == 1){
                            DHTLT = (bJet_pt[0]+Jet2_nonB_PT) - (Lep_pt[0]+Lep_pt[1]);
                        }
                        else continue;

                        //if(DHTLT<0){//<0 cut
                            HTLT_DY->Fill(DHTLT);
                        //}
                //}
                //}
                float Mm_1 = (lep1).M();
                float Mm_2 = (lep2).M();
                Mass_DY->Fill(Mm_1);
                Mass_DY->Fill(Mm_2);
            }
            //leading jet & 2nd leading jet pT    
            if(secjet_pT == -999) secjet_pT = leadjet_pT;
            LeadJetpT_DY->Fill(leadjet_pT);
            SecJetpT_DY->Fill(secjet_pT);

	  }
      }
      }
      }
      
      
   }
  
   run_DY->Write();

   leppT_DY->Write();
   elepT_DY->Write();
   mupT_DY->Write();
   
   lepeta_DY->Write();
   eleEta_DY->Write();
   muEta_DY->Write();

   lepphi_DY->Write();
   elePhi_DY->Write();
   muPhi_DY->Write();

   dPhi_DY->Write();
   dR_DY->Write();
   ee_mass_DY->Write();

   eleIso_DY->Write();
   muIso_DY->Write();

   jetpT_DY->Write();
   jeteta_DY->Write();

   bjetpT_DY->Write();
   bjeteta_DY->Write();
   
   njvsnbj_DY->Write();
   //bjetpT_dR_DY->Write();
   //bjetpT_elepT_DY->Write();
   //bjetpT_mupT_DY->Write();

   LeadJetpT_DY->Write();
   SecJetpT_DY->Write();

//   btagEvent_DY->Write();

   njet_DY->Write();
   nbjet_DY->Write();
   id_DY->Write();
   
   MET_DY->Write();
   dilep_mass_DY->Write();

   SBM_DY->Write();
   METvsMmm_DY->Write();
   HTLT_DY->Write();

   Mass_DY->Write();

   output->Close();

}

