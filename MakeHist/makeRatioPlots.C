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

  //make CRs
  TH1F * hist_b_ee = (TH1F*) returnStack(prefix_b_ee, plot);
  TH1F * hist_antib_mumu = (TH1F*) returnStack(prefix_antib_mumu, plot);
  TH1F * hist_antib_ee = (TH1F*) returnStack(prefix_antib_ee, plot);

  //make SRs
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

  //calculate SR predition
  TH1F * hist_CR_prediction = (TH1F*) hist_b_ee->Clone();

  hist_CR_prediction->Divide(hist_antib_ee);
  hist_CR_prediction->Multiply(hist_antib_mumu);

  hist_CR_prediction->SetLineColor(1);
  hist_CR_prediction->SetTitle("");

  hist_CR_prediction->Rebin(4);

  hist_DB_SR->Rebin(4);
  hist_ST_SR->Rebin(4);
  hist_TT_SR->Rebin(4);
  hist_DY_SR->Rebin(4);

  TCanvas *c1 = new TCanvas("c1","",800,800);
  TText T; 
  c1->SetLogy();
  gPad->SetTicks();


  hs->SetTitle("");
  hs->SetMinimum(0.1);
  hs->SetMaximum(100000); 
  auto rp = new TRatioPlot(hs,hist_CR_prediction);


  rp->Draw();

  rp->GetLowerRefYaxis()->SetTitle("MC/Pred");
  rp->GetUpperRefYaxis()->SetTitle("Events");
  rp->GetUpperRefYaxis()->SetTitleOffset(1.35);
  rp->GetLowerRefYaxis()->SetTitleOffset(1.35);

  rp->GetLowerRefYaxis()->SetLabelSize(0.02);  

  rp->GetUpperRefXaxis()->SetTitle(title);

  rp->GetLowerRefGraph()->SetMaximum(2);
  rp->GetLowerRefGraph()->SetMinimum(0);


  TLegend *leg_hist = new TLegend(0.5039599,0.6239974,0.8734336,0.8876973,NULL,"brNDC");

  leg_hist->SetLineColor(0);
  leg_hist->AddEntry(rp,titleY,"l");
  leg_hist->AddEntry(hist_DY_SR,"DY+jets","f");
  leg_hist->AddEntry(hist_TT_SR,"t#bar{t}","f");
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

  c1->SaveAs("./hists/"+prefix_b_ee+"_"+prefix_antib_mumu+"_"+prefix_antib_ee+"_"+plot+"_hist.png");
  TFile *savefile=new TFile("test.root","RECREATE");
  c1->Write();
  rp->Write("ratioTest");
  pt->Write("txt");
  leg_hist->Write("leg");
  savefile->Close();

  delete c1;

}
