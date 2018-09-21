void HTLT(){

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
    TH1F *HTLT_200 = (TH1F*)zp200->Get("HTLT_hist");
    TH1F *HTLT_350 = (TH1F*)zp350->Get("HTLT_hist");
    TH1F *HTLT_500 = (TH1F*)zp500->Get("HTLT_hist");
    TH1F *HTLT_DY = (TH1F*)DY->Get("HTLT_hist");
    TH1F *HTLT_TT = (TH1F*)TT->Get("HTLT_hist");
    TH1F *HTLT_DB = (TH1F*)DB->Get("HTLT_hist");
    TH1F *HTLT_ST = (TH1F*)ST->Get("HTLT_hist");
    
    //Setting backgrounds FillColor
    HTLT_TT->SetFillColor(kYellow-9);
    HTLT_DY->SetFillColor(kCyan-9);
    HTLT_DB->SetFillColor(kGreen-10);
    HTLT_ST->SetFillColor(kMagenta-10);

    //Setting sample's LineColor
    HTLT_200->SetLineColor(kBlue);
    HTLT_350->SetLineColor(kRed);
    HTLT_500->SetLineColor(kGreen+1);
    HTLT_DY->SetLineColor(1);
    HTLT_TT->SetLineColor(1);
    HTLT_DB->SetLineColor(1);
    HTLT_ST->SetLineColor(1);
   
    //Setting signal LineWidth
    HTLT_200->SetLineWidth(3);
    HTLT_350->SetLineWidth(3);
    HTLT_500->SetLineWidth(3);
     
    //HTLT_200->GetYaxis()->SetRangeUser(1,10000.);
  
    //Reduce number of bin
    HTLT_200->Rebin(2); 
    HTLT_350->Rebin(2); 
    HTLT_500->Rebin(2); 
    HTLT_DY->Rebin(2); 
    HTLT_TT->Rebin(2); 
    HTLT_DB->Rebin(2); 
    HTLT_ST->Rebin(2); 

    ////////////////////// !! Stack order !! /////////////////////
    hs->Add(HTLT_TT,"");
    hs->Add(HTLT_DY,"");
    hs->Add(HTLT_ST,"");
    hs->Add(HTLT_DB,"");

    TCanvas *c1 = new TCanvas("c1","",800,800);
    TText T; 
    c1->SetLogy();
    gPad->SetTicks();
    
    hs->SetMinimum(0.1);
    hs->SetMaximum(100000);
    hs->Draw("hist nostack");
    HTLT_200->Draw("same hist");
    HTLT_350->Draw("same hist");
    HTLT_500->Draw("same hist");

    TPaveText *pt = new TPaveText(0.6378446,0.8822768,0.9072682,0.9547219,"blNDC");
    pt->SetName("title");
    pt->SetBorderSize(0);
    pt->SetFillColor(0);
    pt->SetFillStyle(0);
    pt->SetTextAlign(11);
    pt->SetTextFont(42);
    TText *AText = pt->AddText("35.9 fb^{-1} (13TeV)");
    pt->Draw();

    //hs->GetYaxis()->SetRangeUser(1,100000.);
    hs->GetXaxis()->SetTitle("HT-LT");
    hs->GetYaxis()->SetTitle("Events");

    hs->GetYaxis()->SetLabelSize(0.03);

    leg_HTLT = new TLegend(0.5839599,0.6739974,0.8734336,0.8576973,NULL,"brNDC");
    leg_HTLT->AddEntry(HTLT_200,"Z' 200GeV","l");
    leg_HTLT->AddEntry(HTLT_350,"Z' 350GeV","l");
    leg_HTLT->AddEntry(HTLT_500,"Z' 500GeV","l");
    leg_HTLT->AddEntry(HTLT_DY,"DY+jets","f");
    leg_HTLT->AddEntry(HTLT_TT,"t#bar{t}","f");
    leg_HTLT->AddEntry(HTLT_ST,"tW,#bar{t}W","f");
    leg_HTLT->AddEntry(HTLT_DB,"WW, WZ, ZZ","f");

    leg_HTLT->Draw();

}
