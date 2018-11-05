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
#include <TMath.h>

void makeStackRatioPlot(TString prefix, TString postfix, TString plot, TString title, TString data_postfix){

   //THStack *hs = new THStack("hs","35.9 fb^{-1} (13TeV)");
    THStack *hs = new THStack("hs","2016F 3.102 fb^{-1} (13TeV)");

     std::cout << "plot" << plot << std::endl;

    //Open Files
    TFile *zp200           = new TFile("./output/"+ prefix + "_zp200"+postfix+".root");
    TFile *zp350           = new TFile("./output/"+ prefix + "_zp350"+postfix+".root");
    TFile *zp500           = new TFile("./output/"+ prefix + "_zp500"+postfix+".root");


    TFile *datatest           = new TFile("./output/"+ prefix + data_postfix+".root");

    TFile *WW              = new TFile("./output/"+ prefix + "_WWTo2L2Nu_13TeV.root");
    TFile *ST_tW_antitop   = new TFile("./output/"+ prefix + "_ST_tW_antitop_5f_inclusiveDecays_13TeV.root");
    TFile *TT              = new TFile("./output/"+ prefix + "_TTTo2L2Nu_TuneCUETP8M2_ttHtranche3_13TeV.root");
    TFile *ST_tW_top       = new TFile("./output/"+ prefix + "_ST_tW_top_5f_inclusiveDecays_13TeV.root");
    TFile *WZ              = new TFile("./output/"+ prefix + "_WZ_TuneCUETP8M1_13TeV.root");
    TFile *ZZ              = new TFile("./output/"+ prefix + "_ZZ_TuneCUETP8M1_13TeV.root");
    TFile *DY              = new TFile("./output/"+ prefix + "_DYJetsToLL_M.root");

    //Make TH1Fs
    TH1F *hist_200 = (TH1F*)zp200->Get(plot);
    TH1F *hist_350 = (TH1F*)zp350->Get(plot);
    TH1F *hist_500 = (TH1F*)zp500->Get(plot);
    TH1F *hist_datatest = (TH1F*)datatest->Get(plot);

    std::cout << hist_200->GetEntries() << std::endl;

    //first is named DB as it will include ww, wz, and zz
    TH1F *hist_DB = (TH1F*)WW->Get(plot);
    TH1F *hist_WZ = (TH1F*)WZ->Get(plot);
    TH1F *hist_ZZ = (TH1F*)ZZ->Get(plot);
    hist_DB->Add(hist_WZ);
    hist_DB->Add(hist_ZZ);

    TH1F *hist_TT = (TH1F*)TT->Get(plot);

    TH1F *hist_DY = (TH1F*)DY->Get(plot);

    //first is named ST as it will contain top and antitop
    TH1F *hist_ST = (TH1F*)ST_tW_antitop->Get(plot);
    TH1F *hist_ST_tW_top = (TH1F*)ST_tW_top->Get(plot);
    hist_ST->Add(hist_ST_tW_top);
   
    //Setting backgrounds FillColor
    hist_TT->SetFillColor(kYellow-9);
    hist_DY->SetFillColor(kCyan-9);
    hist_DB->SetFillColor(kGreen-10);
    hist_ST->SetFillColor(kMagenta-10);

    //Setting sample's LineColor
    hist_200->SetLineColor(kBlue);
    hist_350->SetLineColor(kRed);
    hist_500->SetLineColor(kGreen+1);
    hist_datatest->SetLineColor(kBlack);
    hist_DY->SetLineColor(1);
    hist_TT->SetLineColor(1);
    hist_DB->SetLineColor(1);
    hist_ST->SetLineColor(1);
    
    //Setting signal LineWidth
    hist_200->SetLineWidth(3);
    hist_350->SetLineWidth(3);
    hist_500->SetLineWidth(3);
    //hist_datatest->SetLineWidth(3);

    //hist_datatest->SetMarkerStyle(8);
    
    //hist_zp200->GetYaxis()->SetRangeUser(0.001,100000.);

    //Reduce number of bin
    //hist_200->Rebin(4);    
    //hist_350->Rebin(4);    
    //hist_500->Rebin(4);    
    //hist_DY->Rebin(4);    
    //hist_TT->Rebin(4);    
    //hist_DB->Rebin(4);    
    //hist_ST->Rebin(4);    




    //rebin thstack


    TAxis *axis = hist_200->GetXaxis(); 
   int nbins = 50;//axis->GetNbins();
    //Int_t nBins = 100;
    Double_t bins[nbins+1];
    Float_t maxEdge = axis->GetXmax(); //1000;
    Float_t minEdge = axis->GetXmin(); //1;
    Float_t width = TMath::Exp(TMath::Log(maxEdge - minEdge)/(nbins+1));
    //static Float_t bins[nBins + 1];
  
    std::cout << "min max " << minEdge << " " << maxEdge <<  " " << width << std::endl;
    for (int i = 0; i <= nbins+1; i++) {
      bins[i] = minEdge + TMath::Power(width,i ) ;
      //std::cout << i << " " <<  1 + TMath::Power(width,i ) <<std::endl;
    } 

   /* TH1F* hist_DB_new = (TH1F*)hist_DB->Rebin(nbins,"hnew1",bins );
    TH1F* hist_ST_new = (TH1F*)hist_ST->Rebin(nbins,"hnew2",bins );
    TH1F* hist_TT_new = (TH1F*)hist_TT->Rebin(nbins,"hnew3",bins );
    TH1F* hist_DY_new = (TH1F*)hist_DY->Rebin(nbins,"hnew4",bins );

    TH1F* hist_datatest_new = (TH1F*)hist_datatest->Rebin(nbins,"hnew5",bins );

    TH1F* hist_200_new = (TH1F*)hist_200->Rebin(nbins,"hnew6",bins );
    TH1F* hist_350_new = (TH1F*)hist_350->Rebin(nbins,"hnew7",bins );
    TH1F* hist_500_new = (TH1F*)hist_500->Rebin(nbins,"hnew8",bins );*/


    //std::cout << hist_datatest_new->GetEntries() << std::endl;
   //axis->Set(nbins, bins); 

    Float_t numMC = hist_DB->Integral(68, -1);
    numMC += hist_ST->Integral(68, -1);
    numMC += hist_TT->Integral(68, -1);
    numMC += hist_DY->Integral(68, -1);

    Float_t numData = hist_datatest->Integral(68, -1);

    Float_t mcSF = hist_datatest->Integral(68, -1)/numMC;

    mcSF = 3.102/35.9;
    //mcSF =  3.285/35.9;

    std::cout << "scale factor " << mcSF << " numMC " << numMC <<  " numdata " << numData <<  std::endl;

    hist_DB->Scale(mcSF);
    hist_ST->Scale(mcSF);
    hist_TT->Scale(mcSF);
    hist_DY->Scale(mcSF);
//
    hist_200->Scale(mcSF);
    hist_350->Scale(mcSF);
    hist_500->Scale(mcSF);


///-----

    ////////////////////// !! Stack order !! /////////////////////
    hs->Add(hist_DB,"");
    hs->Add(hist_ST,"");
    hs->Add(hist_TT,"");
    hs->Add(hist_DY,"");



    TH1F* sum = (TH1F*) hist_DB->Clone("MC");
    sum->Add(hist_ST);
    sum->Add(hist_TT);
    sum->Add(hist_DY);

    sum->Divide(hist_datatest);

    sum->Draw();
    Float_t maxValue = sum->GetMaximum();




    TCanvas *c1 = new TCanvas("c1","",800,800);
    TText T; 
    c1->SetLogy();
    gPad->SetTicks();
   
    
    hs->SetMinimum(0.1);
    hs->SetMaximum(100000); 

  auto rp = new TRatioPlot(hs,hist_datatest);


  rp->Draw();
  //hist_CR_prediction_data->Draw("same");
  
  //hist_data_b_ee->Draw("same");

  rp->GetLowerRefYaxis()->SetTitle("MC/Data");
  rp->GetUpperRefYaxis()->SetTitle("Events");
  rp->GetUpperRefYaxis()->SetTitleOffset(1.35);
  rp->GetLowerRefYaxis()->SetTitleOffset(1.35);

  rp->GetLowerRefYaxis()->SetLabelSize(0.02);  

  rp->GetUpperRefXaxis()->SetTitle(title);

  rp->GetLowerRefGraph()->SetMaximum(maxValue*1.2);
  //rp->GetLowerRefGraph()->SetMinimum(0);


  TLegend *leg_hist = new TLegend(0.5039599,0.6239974,0.8734336,0.8876973,NULL,"brNDC");

  leg_hist->SetLineColor(0);
  leg_hist->AddEntry(rp,"MC/Data","l");
  leg_hist->AddEntry(hist_DY,"DY+jets","f");
  leg_hist->AddEntry(hist_TT,"t#bar{t}","f");
  leg_hist->AddEntry(hist_ST,"tW,#bar{t}W","f");
  leg_hist->AddEntry(hist_DB,"WW, WZ, ZZ","f");
  
  leg_hist->Draw();

  TPaveText *pt = new TPaveText(0.6378446,0.9122768,0.972682,0.9847219,"blNDC");
  pt->SetName("title");
  pt->SetBorderSize(0);
  pt->SetFillColor(0);
  pt->SetFillStyle(0);
  pt->SetTextAlign(11);
  pt->SetTextFont(42);
  //TText *AText = pt->AddText("35.9 fb^{-1} (13TeV)");
  TText *AText = pt->AddText("2016F 3.102 fb^{-1} (13TeV)");
  pt->Draw();

  c1->SaveAs("./hists/ratio_"+prefix+"_"+plot+"_hist"+postfix+".png");
  TFile *savefile=new TFile("./hists/ratio_"+prefix+"_"+plot+"_hist"+postfix+"_hist.root","RECREATE");
  c1->Write();
  rp->Write("ratioTest");
  pt->Write("txt");
  leg_hist->Write("leg");
  savefile->Close();


  zp200->Close();
  zp350->Close();
  zp500->Close();
  datatest->Close();
  WW->Close();
  ST_tW_antitop->Close();
  TT->Close();
  ST_tW_top->Close();
  WZ->Close();
  ZZ->Close();
  DY->Close();


    delete c1;

}
