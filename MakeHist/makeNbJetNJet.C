#include <TCanvas.h>
#include <TH1.h>
#include <TH2.h>
#include <TFile.h>
#include <TText.h>
#include <TPaveText.h>
#include <TLegend.h>
#include <THStack.h>
#include <TColor.h>
#include <TStyle.h>
#include <iostream>

void makeNbJetNJet(TString prefix, TString plot){

  THStack *hs = new THStack("hs","35.9 fb^{-1} (13TeV)");
/*
  //Open Files
  TFile *zp200           = new TFile("./output/"+ prefix + "_zp200.root");
  TFile *zp350           = new TFile("./output/"+ prefix + "_zp350.root");
  TFile *zp500           = new TFile("./output/"+ prefix + "_zp500.root");

  TFile *WW              = new TFile("./output/"+ prefix + "_WWTo2L2Nu_13TeV.root");
  TFile *ST_tW_antitop   = new TFile("./output/"+ prefix + "_ST_tW_antitop_5f_inclusiveDecays_13TeV.root");
  TFile *TT              = new TFile("./output/"+ prefix + "_TTTo2L2Nu_TuneCUETP8M2_ttHtranche3_13TeV.root");
  TFile *ST_tW_top       = new TFile("./output/"+ prefix + "_ST_tW_top_5f_inclusiveDecays_13TeV.root");
  TFile *WZ              = new TFile("./output/"+ prefix + "_WZ_TuneCUETP8M1_13TeV.root");
  TFile *ZZ              = new TFile("./output/"+ prefix + "_ZZ_TuneCUETP8M1_13TeV.root");*/
  TFile *DY              = new TFile("./output/"+ prefix + "_DYJetsToLL_M_v2_new.root");


  TFile *DY_12b              = new TFile("./output/b=1,2_b+j=2_SimpleNtupler_DYJetsToLL_M_v2_new.root");
  TFile *DY_nob              = new TFile("./output/b=1,2_b+j=2_SimpleNtupler_DYJetsToLL_M_v2_new.root");


  TFile *datatest           = new TFile("./output/"+ prefix + "_datatest.root");
/*  TFile *datatest_SE           = new TFile("./output/"+ prefix + "_2016F_singleElectron.root");

*/
/*
  //Make TH1Fs
  TH2F *hist_200 = (TH2F*)zp200->Get(plot);
  TH2F *hist_350 = (TH2F*)zp350->Get(plot);
  TH2F *hist_500 = (TH2F*)zp500->Get(plot);

  //first is named DB as it will include ww, wz, and zz
  TH2F *hist_DB = (TH2F*)WW->Get(plot);
  TH2F *hist_WZ = (TH2F*)WZ->Get(plot);
  TH2F *hist_ZZ = (TH2F*)ZZ->Get(plot);
  hist_DB->Add(hist_WZ);
  hist_DB->Add(hist_ZZ);

  TH2F *hist_TT = (TH2F*)TT->Get(plot);
*/
  TH2F *hist_DY = (TH2F*)DY->Get(plot);

  TH2F *hist_DY_12b = (TH2F*)DY_12b->Get(plot);

  TH2F *hist_DY_nob = (TH2F*)DY_nob->Get(plot);


  TH2F *hist_datatest = (TH2F*)datatest->Get(plot);
/*  TH2F *hist_datatest_SE = (TH2F*)datatest_SE->Get(plot);
*/

  TCanvas *c1 = new TCanvas("c1","",800,800);
  TText T; 
  gPad->SetTicks();

  c1->SetRightMargin(0.13);

  hist_DY->SetStats(0);


  //create color table
  Double_t max       = hist_DY->GetMaximum();
  Double_t min       = hist_DY->GetMinimum();
  Double_t val_white = 1.;
  Double_t per_white = (val_white-min)/(max-min);

  const Int_t Number = 3;

  /*Double_t Red[Number]   = { 0., .164, 1.};
  Double_t Green[Number] = { 0., 0.4, .765};
  Double_t Blue[Number]  = { 1., 1., .164};
  Double_t Stops[Number] = { 0., 0., 1. };*/

  Double_t Red[Number]   = { 0., 1, 1.};
  Double_t Green[Number] = { 0., 1, .765};
  Double_t Blue[Number]  = { 1., 1, .164};
  Double_t Stops[Number] = { 0., .5, 1. };

  Int_t nb= 256;
  hist_DY->SetContour(nb);

  TColor::CreateGradientColorTable(Number,Stops,Red,Green,Blue,nb);


/*
  hist_200->GetYaxis()->SetLabelSize(0.03);
  hist_200->GetYaxis()->SetTitleOffset(1.3);

  hist_200->GetXaxis()->SetTitleOffset(1.25);

  hist_200->SetTitle("");
  hist_200->GetZaxis()->SetTitle("");
  
  hist_200->DrawNormalized("colz TEXT ");
  gStyle->SetPaintTextFormat("5.2f");

  TPaveText *pt = new TPaveText(0.6378446,0.8822768,0.9072682,0.9547219,"blNDC");
  pt->SetName("title");
  pt->SetBorderSize(0);
  pt->SetFillColor(0);
  pt->SetFillStyle(0);
  pt->SetTextAlign(11);
  pt->SetTextFont(42);
  TText *AText = pt->AddText("35.9 fb^{-1} (13TeV)");
  pt->Draw();


  pt->Draw();

  c1->SaveAs("./hists/zp200_"+plot+"_hist.png");

*/
  hist_DY->SetStats(0);

  //c1->SetLogz();

  hist_DY->GetYaxis()->SetLabelSize(0.03);
  hist_DY->GetYaxis()->SetTitleOffset(1.3);

  hist_DY->GetXaxis()->SetTitleOffset(1.25);

  hist_DY->SetTitle("");
  hist_DY->GetZaxis()->SetTitle("");
  
  hist_DY->DrawNormalized("colz  TEXT");
  gStyle->SetPaintTextFormat("5.2f");

  c1->SaveAs("./hists/DY_"+prefix+"_"+plot+"_hist.png");


  hist_DY_12b->Rebin2D(4,4);
  hist_DY_nob->Rebin2D(4,4);
  hist_DY_12b->Scale(1.0/hist_DY_12b->GetEntries());
  hist_DY_nob->Scale(-1.0/hist_DY_nob->GetEntries());
  hist_DY_12b->Add(hist_DY_nob);

  hist_DY_12b->GetYaxis()->SetLabelSize(0.03);
  hist_DY_12b->GetYaxis()->SetTitleOffset(1.3);

  hist_DY_12b->GetXaxis()->SetTitleOffset(1.25);

  hist_DY_12b->SetTitle("");
  hist_DY_12b->GetZaxis()->SetTitle("");
  
  hist_DY_12b->DrawNormalized("colz  ");
  gStyle->SetPaintTextFormat("5.2f");

  c1->SaveAs("./hists/DY_12b_divide_nob_hist.png");


/*
  hist_TT->SetStats(0);


  hist_TT->GetYaxis()->SetLabelSize(0.03);
  hist_TT->GetYaxis()->SetTitleOffset(1.3);

  hist_TT->GetXaxis()->SetTitleOffset(1.25);

  hist_TT->SetTitle("");
  hist_TT->GetZaxis()->SetTitle("");
  
  hist_TT->DrawNormalized("colz TEXT ");
  gStyle->SetPaintTextFormat("5.2f");


  c1->SaveAs("./hists/TT_"+plot+"_hist.png");

*/

    hist_datatest->SetStats(0);


  hist_datatest->GetYaxis()->SetLabelSize(0.03);
  hist_datatest->GetYaxis()->SetTitleOffset(1.3);

  hist_datatest->GetXaxis()->SetTitleOffset(1.25);

  hist_datatest->SetTitle("");
  hist_datatest->GetZaxis()->SetTitle("");
  
  hist_datatest->DrawNormalized("colz TEXT ");
  gStyle->SetPaintTextFormat("5.2f");


  c1->SaveAs("./hists/datatest_"+plot+"_hist.png");


/*

    hist_datatest_SE->SetStats(0);


  hist_datatest_SE->GetYaxis()->SetLabelSize(0.03);
  hist_datatest_SE->GetYaxis()->SetTitleOffset(1.3);

  hist_datatest_SE->GetXaxis()->SetTitleOffset(1.25);

  hist_datatest_SE->SetTitle("");
  hist_datatest_SE->GetZaxis()->SetTitle("");
  
  hist_datatest_SE->DrawNormalized("colz TEXT ");
  gStyle->SetPaintTextFormat("5.2f");


  c1->SaveAs("./hists/datatest_SE_"+plot+"_hist.png");

*/
  delete c1;

}
