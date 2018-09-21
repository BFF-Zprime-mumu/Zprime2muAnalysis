void MET(){

    THStack *hs = new THStack("hs","35.9 fb^{-1} (13TeV)");
   
    //Signal input files
    TFile *zp200 = new TFile("/cms/ldap_home/hyeahyun/signal/zp200/zp200_basic_DiMu_bjetpT20_Histograms.root");
    TFile *zp350 = new TFile("/cms/ldap_home/hyeahyun/signal/zp350/zp350_basic_DiMu_bjetpT20_Histograms.root");
    TFile *zp500 = new TFile("/cms/ldap_home/hyeahyun/signal/zp500/zp500_basic_DiMu_bjetpT20_Histograms.root");

    //Background input files
    TFile *DY = new TFile("DY/DY_basic_DiMu_bjetpT20_Histograms.root");
    TFile *TT = new TFile("TT/TT_basic_DiMu_bjetpT20_Histograms.root");
    TFile *DB = new TFile("diboson/DB_basic_DiMu_bjetpT20_Histograms.root");
    TFile *ST = new TFile("ST/ST_basic_DiMu_bjetpT20_Histograms.root");

    //Branch
    TH1F *MET_200 = (TH1F*)zp200->Get("METvsMmm_hist");
    TH1F *MET_350 = (TH1F*)zp350->Get("METvsMmm_hist");
    TH1F *MET_500 = (TH1F*)zp500->Get("METvsMmm_hist");
    TH1F *MET_DY = (TH1F*)DY->Get("METvsMmm_hist");
    TH1F *MET_TT = (TH1F*)TT->Get("METvsMmm_hist");
    TH1F *MET_DB = (TH1F*)DB->Get("METvsMmm_hist");
    TH1F *MET_ST = (TH1F*)ST->Get("METvsMmm_hist");
    
    //Setting backgrounds FillColor
    MET_TT->SetFillColor(kYellow-9);
    MET_DY->SetFillColor(kCyan-9);
    MET_DB->SetFillColor(kGreen-10);
    MET_ST->SetFillColor(kMagenta-10);

    //Setting sample's LineColor
    MET_200->SetLineColor(kBlue);
    MET_350->SetLineColor(kRed);
    MET_500->SetLineColor(kGreen+1);
    MET_DY->SetLineColor(1);
    MET_TT->SetLineColor(1);
    MET_DB->SetLineColor(1);
    MET_ST->SetLineColor(1);
   
    //Setting signal LineWidth
    MET_200->SetLineWidth(3);
    MET_350->SetLineWidth(3);
    MET_500->SetLineWidth(3);
    
    //MET_zp200->GetYaxis()->SetRangeUser(0.001,100000.);
  
    //Reduce number of bin
    MET_200->Rebin(2); 
    MET_350->Rebin(2); 
    MET_500->Rebin(2); 
    MET_DY->Rebin(2); 
    MET_TT->Rebin(2); 
    MET_DB->Rebin(2); 
    MET_ST->Rebin(2); 

    ////////////////////// !! Stack order !! /////////////////////
    hs->Add(MET_TT,"");
    hs->Add(MET_DY,"");
    hs->Add(MET_ST,"");
    hs->Add(MET_DB,"");

    TCanvas *c1 = new TCanvas("c1","",800,800);
    TText T; 
    c1->SetLogy();
    gPad->SetTicks();

    hs->SetMinimum(0.1);
    hs->SetMaximum(10000);
    
    hs->Draw("hist nostack");
    MET_200->Draw("same hist");
    MET_350->Draw("same hist");
    MET_500->Draw("same hist");

    TPaveText *pt = new TPaveText(0.6378446,0.8822768,0.9072682,0.9547219,"blNDC");
    pt->SetName("title");
    pt->SetBorderSize(0);
    pt->SetFillColor(0);
    pt->SetFillStyle(0);
    pt->SetTextAlign(11);
    pt->SetTextFont(42);
    TText *AText = pt->AddText("35.9 fb^{-1} (13TeV)");
    pt->Draw();

    //hs->GetYaxis()->SetRangeUser(0.001,100000.);
    hs->GetXaxis()->SetTitle("E^{miss}_{T}/M_{#mu^{+}#mu^{-}}");
    hs->GetYaxis()->SetTitle("Events");

    hs->GetYaxis()->SetLabelSize(0.03);

    leg_MET = new TLegend(0.5839599,0.6739974,0.8734336,0.8576973,NULL,"brNDC");
    leg_MET->AddEntry(MET_200,"Z' 200GeV","l");
    leg_MET->AddEntry(MET_350,"Z' 350GeV","l");
    leg_MET->AddEntry(MET_500,"Z' 500GeV","l");
    leg_MET->AddEntry(MET_DY,"DY+jets","f");
    leg_MET->AddEntry(MET_TT,"t#bar{t}","f");
    leg_MET->AddEntry(MET_ST,"tW,#bar{t}W","f");
    leg_MET->AddEntry(MET_DB,"WW, WZ, ZZ","f");

    leg_MET->Draw();

}
