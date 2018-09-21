void TMB(){

    THStack *hs = new THStack("hs","35.9 fb^{-1} (13TeV)");

    //Signal input files
    TFile *zp200 = new TFile("/cms/ldap_home/hyeahyun/signal/zp200/zp200_DiMu_bjetpT20_2Njets_Histograms.root");
    TFile *zp350 = new TFile("/cms/ldap_home/hyeahyun/signal/zp350/zp350_DiMu_bjetpT20_2Njets_Histograms.root");
    TFile *zp500 = new TFile("/cms/ldap_home/hyeahyun/signal/zp500/zp500_DiMu_bjetpT20_2Njets_Histograms.root");
    
    //Background input files
    TFile *DY = new TFile("DY/DY_DiMu_bjetpT20_2Njets_Histograms.root");
    TFile *TT = new TFile("TT/TT_DiMu_bjetpT20_2Njets_Histograms.root");
    TFile *DB = new TFile("diboson/DB_DiMu_bjetpT20_2Njets_Histograms.root");
    TFile *ST = new TFile("ST/ST_DiMu_bjetpT20_2Njets_Histograms.root");

    //Branch
    TH1F *TMB_200 = (TH1F*)zp200->Get("SBM_hist");
    TH1F *TMB_350 = (TH1F*)zp350->Get("SBM_hist");
    TH1F *TMB_500 = (TH1F*)zp500->Get("SBM_hist");
    TH1F *TMB_DY = (TH1F*)DY->Get("SBM_hist");
    TH1F *TMB_TT = (TH1F*)TT->Get("SBM_hist");
    TH1F *TMB_DB = (TH1F*)DB->Get("SBM_hist");
    TH1F *TMB_ST = (TH1F*)ST->Get("SBM_hist");
   
    //Setting backgrounds FillColor
    TMB_TT->SetFillColor(kYellow-9);
    TMB_DY->SetFillColor(kCyan-9);
    TMB_DB->SetFillColor(kGreen-10);
    TMB_ST->SetFillColor(kMagenta-10);

    //Setting sample's LineColor
    TMB_200->SetLineColor(kBlue);
    TMB_350->SetLineColor(kRed);
    TMB_500->SetLineColor(kGreen+1);
    TMB_DY->SetLineColor(1);
    TMB_TT->SetLineColor(1);
    TMB_DB->SetLineColor(1);
    TMB_ST->SetLineColor(1);
    
    //Setting signal LineWidth
    TMB_200->SetLineWidth(3);
    TMB_350->SetLineWidth(3);
    TMB_500->SetLineWidth(3);
    
    //TMB_zp200->GetYaxis()->SetRangeUser(0.001,100000.);

    //Reduce number of bin
    TMB_200->Rebin(4);    
    TMB_350->Rebin(4);    
    TMB_500->Rebin(4);    
    TMB_DY->Rebin(4);    
    TMB_TT->Rebin(4);    
    TMB_DB->Rebin(4);    
    TMB_ST->Rebin(4);    

    ////////////////////// !! Stack order !! /////////////////////
    hs->Add(TMB_TT,"");
    hs->Add(TMB_DY,"");
    hs->Add(TMB_ST,"");
    hs->Add(TMB_DB,"");

    TCanvas *c1 = new TCanvas("c1","",800,800);
    TText T; 
    c1->SetLogy();
    gPad->SetTicks();
   
    //TMB_DY->GetYaxis()->SetRangeUser(0.01,100.);
    
    hs->SetMinimum(0.1);
    hs->SetMaximum(100000); 

    hs->Draw("hist nostack");
    TMB_200->Draw("same hist");
    TMB_350->Draw("same hist");
    TMB_500->Draw("same hist");

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
    hs->GetXaxis()->SetTitle("max(M_{b,lep})[GeV]");
    hs->GetYaxis()->SetTitle("Events");

    hs->GetYaxis()->SetLabelSize(0.03);

    leg_TMB = new TLegend(0.5839599,0.6739974,0.8734336,0.8576973,NULL,"brNDC");
    leg_TMB->AddEntry(TMB_200,"Z' 200GeV","l");
    leg_TMB->AddEntry(TMB_350,"Z' 350GeV","l");
    leg_TMB->AddEntry(TMB_500,"Z' 500GeV","l");
    leg_TMB->AddEntry(TMB_DY,"DY+jets","f");
    leg_TMB->AddEntry(TMB_TT,"t#bar{t}","f");
    //leg_TMB->AddEntry(TMB_Wj,"W+jets","f");
    leg_TMB->AddEntry(TMB_ST,"tW,#bar{t}W","f");
    leg_TMB->AddEntry(TMB_DB,"WW, WZ, ZZ","f");

    leg_TMB->Draw();

}
