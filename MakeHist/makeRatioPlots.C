#include <TCanvas.h>
#include <TH1.h>
#include <TH2.h>
#include <TFile.h>
#include <TText.h>
#include <TPaveText.h>
#include <TLegend.h>
#include <THStack.h>
#include <iostream>
#include <TRatioPlot.h>

TH1F * returnStack(TString prefix, TString plot)
{
    TFile *WW            = new TFile("./output/"+ prefix + "_WWTo2L2Nu_13TeV.root");
    TFile *ST_tW_antitop = new TFile("./output/"+ prefix + "_ST_tW_antitop_5f_inclusiveDecays_13TeV.root");
    TFile *TT            = new TFile("./output/"+ prefix + "_TTTo2L2Nu_TuneCUETP8M2_ttHtranche3_13TeV.root");
    TFile *ST_tW_top     = new TFile("./output/"+ prefix + "_ST_tW_top_5f_inclusiveDecays_13TeV.root");
    TFile *WZ            = new TFile("./output/"+ prefix + "_WZ_TuneCUETP8M1_13TeV.root");
    TFile *ZZ            = new TFile("./output/"+ prefix + "_ZZ_TuneCUETP8M1_13TeV.root");
    TFile *DY            = new TFile("./output/"+ prefix + "_DYJetsToLL_M.root");

    //first is named DB as it will include ww, wz, and zz
    TH1F *hist_DB = (TH1F*)WW->Get(plot);
    TH1F *hist_WZ = (TH1F*)WZ->Get(plot);
    TH1F *hist_ZZ = (TH1F*)ZZ->Get(plot);
    TH1F *hist_TT = (TH1F*)TT->Get(plot);
    TH1F *hist_DY = (TH1F*)DY->Get(plot);
    //first is named ST as it will contain top and antitop
    TH1F *hist_ST = (TH1F*)ST_tW_antitop->Get(plot);
    TH1F *hist_ST_tW_top = (TH1F*)ST_tW_top->Get(plot);


    TH1F* hist = (TH1F*) hist_DB->Clone();

    hist->Add(hist_WZ);
    hist->Add(hist_ZZ);
    hist->Add(hist_TT);
    hist->Add(hist_DY);
    hist->Add(hist_ST);
    hist->Add(hist_ST_tW_top);

    return hist;
}


void makeRatioPlots(TString prefix_b_ee,TString prefix_antib_mumu,TString prefix_antib_ee, TString prefix_b_mumu, TString plot, TString title, TString titleY){

    THStack *hs = new THStack("hs","35.9 fb^{-1} (13TeV)");

    TH1F * hist_b_ee = (TH1F*) returnStack(prefix_b_ee, plot);
    TH1F * hist_antib_mumu = (TH1F*) returnStack(prefix_antib_mumu, plot);
    TH1F * hist_antib_ee = (TH1F*) returnStack(prefix_antib_ee, plot);


    TFile *WW_SR              = new TFile("./output/"+ prefix_b_mumu + "_WWTo2L2Nu_13TeV.root");
    TFile *ST_tW_antitop_SR   = new TFile("./output/"+ prefix_b_mumu + "_ST_tW_antitop_5f_inclusiveDecays_13TeV.root");
    TFile *TT_SR              = new TFile("./output/"+ prefix_b_mumu + "_TTTo2L2Nu_TuneCUETP8M2_ttHtranche3_13TeV.root");
    TFile *ST_tW_top_SR       = new TFile("./output/"+ prefix_b_mumu + "_ST_tW_top_5f_inclusiveDecays_13TeV.root");
    TFile *WZ_SR              = new TFile("./output/"+ prefix_b_mumu + "_WZ_TuneCUETP8M1_13TeV.root");
    TFile *ZZ_SR              = new TFile("./output/"+ prefix_b_mumu + "_ZZ_TuneCUETP8M1_13TeV.root");
    TFile *DY_SR              = new TFile("./output/"+ prefix_b_mumu + "_DYJetsToLL_M.root");

    //first is named DB as it will include ww, wz, and zz
    TH1F *hist_DB_SR = (TH1F*)WW_SR->Get(plot);
    TH1F *hist_WZ_SR = (TH1F*)WZ_SR->Get(plot);
    TH1F *hist_ZZ_SR = (TH1F*)ZZ_SR->Get(plot);
    hist_DB_SR->Add(hist_WZ_SR);
    hist_DB_SR->Add(hist_ZZ_SR);

    TH1F *hist_TT_SR = (TH1F*)TT_SR->Get(plot);
    TH1F *hist_DY_SR = (TH1F*)DY_SR->Get(plot);
    //first is named ST as it will contain top and antitop
    TH1F *hist_ST_SR = (TH1F*)ST_tW_antitop_SR->Get(plot);
    TH1F *hist_ST_tW_top_SR = (TH1F*)ST_tW_top_SR->Get(plot);
    hist_ST_SR->Add(hist_ST_tW_top_SR);


     //Setting backgrounds FillColor
    hist_TT_SR->SetFillColor(kYellow-9);
    hist_DY_SR->SetFillColor(kCyan-9);
    hist_DB_SR->SetFillColor(kGreen-10);
    hist_ST_SR->SetFillColor(kMagenta-10);

    //Setting sample's LineColor
    hist_DY_SR->SetLineColor(1);
    hist_TT_SR->SetLineColor(1);
    hist_DB_SR->SetLineColor(1);
    hist_ST_SR->SetLineColor(1);


    ////////////////////// !! Stack order !! /////////////////////
    hs->Add(hist_DB_SR,"");
    hs->Add(hist_ST_SR,"");
    hs->Add(hist_TT_SR,"");
    hs->Add(hist_DY_SR,"");

    TList *histos = hs->GetHists(); 
    TH1F *sum = new TH1F("sum","sum of histograms",100,-4,4); 
    TIter next(histos); 
    TH1F *hist; 
    while ((hist =(TH1F*)next())) 
    { 
        cout << "Adding " << hist->GetName() << endl; sum->Add(hist); 
    } 


    //Reduce number of bin   
    hist_DY_SR->Rebin(4);    
    hist_TT_SR->Rebin(4);    
    hist_DB_SR->Rebin(4);    
    hist_ST_SR->Rebin(4);    
    sum->Rebin(4);
    TH1F *sum2 = (TH1F*)hist_DY_SR->Clone("h3");
    sum2->Add(hist_TT_SR);
    sum2->Add(hist_DB_SR);
    sum2->Add(hist_ST_SR);
  
    //Setting backgrounds FillColor
    //hist_b_ee->SetFillColor(kCyan-9);


    //Setting sample's LineColor

    hist_b_ee->SetLineColor(1);

    
    //hist_zp200->GetYaxis()->SetRangeUser(0.001,100000.);

    //Reduce number of bin
    hist_b_ee->Rebin(4);    
    hist_antib_mumu->Rebin(4);    
    hist_antib_ee->Rebin(4);    


    TCanvas *c1 = new TCanvas("c1","",800,800);
    TText T; 
    c1->SetLogy();
    gPad->SetTicks();
     //hist_DY->GetYaxis()->SetRangeUser(0.01,100.);
    

/*
   TPad *pad1 = new TPad("pad1", "pad1", 0, 0.3, 1, 1.0);
   pad1->SetBottomMargin(0); // Upper and lower plot are joined
   pad1->SetGridx();         // Vertical grid
   pad1->SetLogy();         
   pad1->Draw();             // Draw the upper pad: pad1
   pad1->cd();               // pad1 becomes the current pad

    hs->Draw("hist");





    hs->GetXaxis()->SetTitle(title);
    hs->GetYaxis()->SetTitle("Events");

    hs->GetYaxis()->SetLabelSize(0.03);
    hs->GetYaxis()->SetTitleOffset(1.3);

    hs->GetXaxis()->SetTitleOffset(1.25);




    hist_b_ee->SetStats(0);
    hist_b_ee->Multiply(hist_antib_mumu);
    hist_b_ee->Divide(hist_antib_ee);

    hist_b_ee->SetLineColor(kRed);

    //Setting signal LineWidth
    hist_b_ee->SetLineWidth(3);


    hist_b_ee->Draw("same hist");
    
    TPaveText *pt = new TPaveText(0.6378446,0.8822768,0.9072682,0.9547219,"blNDC");
    pt->SetName("title");
    pt->SetBorderSize(0);
    pt->SetFillColor(0);
    pt->SetFillStyle(0);
    pt->SetTextAlign(11);
    pt->SetTextFont(42);
    TText *AText = pt->AddText("35.9 fb^{-1} (13TeV)");
    pt->Draw();



    //hist_b_ee->SetTitle("35.9 fb^{-1} (13TeV)");
    sum->SetLineWidth(3);
    sum->SetLineColor(kBlue);
    //sum->Draw("same hist");

    sum2->SetFillStyle(0);
    sum2->SetLineWidth(3);
    sum2->SetLineColor(kBlue);
    //sum2->Draw("same hist");

    //hs->GetYaxis()->SetRangeUser(0.001,100000.);
    //hist_b_ee->GetXaxis()->SetTitle(title);
    //hist_b_ee->GetYaxis()->SetTitle(titleY);

    //hist_b_ee->GetYaxis()->SetLabelSize(0.03);
    //hist_b_ee->GetYaxis()->SetTitleOffset(1.3);

    //hist_b_ee->GetXaxis()->SetTitleOffset(1.25);

    pt->Draw();



    //c1->SaveAs("test.png");


    c1->cd();          // Go back to the main canvas before defining pad2
   TPad *pad2 = new TPad("pad2", "pad2", 0, 0.05, 1, 0.3);
   pad2->SetTopMargin(0);
   pad2->SetBottomMargin(0.2);
   pad2->SetGridx(); // vertical grid
   pad2->Draw();
   pad2->cd();       // pad2 becomes the current pad






    TH1F *h3 = (TH1F*)hist_b_ee->Clone("h3");
   h3->SetLineColor(kBlack);
   h3->SetMinimum(0);  // Define Y ..
   h3->SetMaximum(2); // .. range
   h3->Sumw2();
   h3->SetStats(0);      // No statistics on lower plot
   h3->Divide(sum2);
   h3->SetMarkerStyle(21);
   h3->Draw("ep");       // Draw the ratio plot


   // hist_b_ee settings
   hist_b_ee->SetLineColor(kBlue+1);
   hist_b_ee->SetLineWidth(2);

   // Y axis hist_b_ee plot settings
   hist_b_ee->GetYaxis()->SetTitleSize(20);
   hist_b_ee->GetYaxis()->SetTitleFont(43);
   hist_b_ee->GetYaxis()->SetTitleOffset(1.55);


   // hs settings
   hs->SetLineColor(kRed);
   hs->SetLineWidth(2);

   // Ratio plot (h3) settings
   h3->SetTitle(""); // Remove the ratio title

   // Y axis ratio plot settings
   h3->GetYaxis()->SetTitle("ratio h1/hs ");
   h3->GetYaxis()->SetNdivisions(505);
   h3->GetYaxis()->SetTitleSize(20);
   h3->GetYaxis()->SetTitleFont(43);
   h3->GetYaxis()->SetTitleOffset(1.55);
   h3->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
   h3->GetYaxis()->SetLabelSize(15);

   // X axis ratio plot settings
   h3->GetXaxis()->SetTitleSize(20);
   h3->GetXaxis()->SetTitleFont(43);
   h3->GetXaxis()->SetTitleOffset(4.);
   h3->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
   h3->GetXaxis()->SetLabelSize(15);
*/

  hist_b_ee->SetTitle("");
  hs->SetTitle("");
  hs->SetMinimum(0.1);
  hs->SetMaximum(100000); 
  auto rp = new TRatioPlot(hs,hist_b_ee);



  //rp->GetLowYaxis()->SetTitle("Prediction/Observation");

  //rp->GetXaxis()->SetTitle(title);
  rp->Draw();

  rp->GetLowerRefYaxis()->SetTitle("MC/Pred");
  rp->GetUpperRefYaxis()->SetTitle("Events");
  rp->GetUpperRefYaxis()->SetTitleOffset(1.35);
  rp->GetLowerRefYaxis()->SetTitleOffset(1.35);

  rp->GetLowerRefYaxis()->SetLabelSize(0.2);  

  rp->GetUpperRefXaxis()->SetTitle(title);

  rp->GetLowerRefGraph()->SetMaximum(2);
   rp->GetLowerRefGraph()->SetMinimum(0);
  //rp->GetUpperRefObject()->SetMaximum(10000);


      TLegend *leg_hist = new TLegend(0.5039599,0.6239974,0.8734336,0.8876973,NULL,"brNDC");

      leg_hist->SetLineColor(0);
    leg_hist->AddEntry(rp,titleY,"l");
    leg_hist->AddEntry(hist_DY_SR,"DY+jets","f");
    leg_hist->AddEntry(hist_TT_SR,"t#bar{t}","f");
    //leg_hist->AddEntry(hist_Wj,"W+jets","f");
    leg_hist->AddEntry(hist_ST_SR,"tW,#bar{t}W","f");
    leg_hist->AddEntry(hist_DB_SR,"WW, WZ, ZZ","f");
    

    leg_hist->Draw();


    TPaveText *pt = new TPaveText(0.6378446,0.9122768,0.972682,0.9847219,"blNDC");
    pt->SetName("title");
    pt->SetBorderSize(0);
    pt->SetFillColor(0);
    pt->SetFillStyle(0);
    pt->SetTextAlign(11);
    pt->SetTextFont(42);
    TText *AText = pt->AddText("35.9 fb^{-1} (13TeV)");
    pt->Draw();
  ///afs/cern.ch/work/r/rymuelle/public/CMSSW_8_0_29/src/SUSYBSMAnalysis/Zprime2muAnalysis/MakeHist

    c1->SaveAs("./hists/"+prefix_b_ee+"_"+prefix_antib_mumu+"_"+prefix_antib_ee+"_"+plot+"_hist.png");
  TFile *savefile=new TFile("test.root","RECREATE");
  c1->Write();
  rp->Write("ratioTest");
  pt->Write("txt");
  leg_hist->Write("leg");
  savefile->Close();


    delete c1;

}
