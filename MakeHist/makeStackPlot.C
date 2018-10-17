#include <TCanvas.h>
#include <TH1.h>
#include <TH2.h>
#include <TFile.h>
#include <TText.h>
#include <TPaveText.h>
#include <TLegend.h>
#include <THStack.h>
#include <iostream>

TH1F * returnKeepGreaterThan(TH1F * background, TH1F * sample)
{
    float previousBin;
    float currentBin;
    int nBins = background->GetNbinsX();

    TH1F* background_integrated = (TH1F*) background->Clone();
    TH1F* sample_integrated = (TH1F*) sample->Clone();

    for(int i=1;i<nBins+2;i++){

        previousBin = background_integrated->GetBinContent(i-1);
        currentBin = background_integrated->GetBinContent(i);

        background_integrated->SetBinContent(i, currentBin+ previousBin);

        previousBin = sample_integrated->GetBinContent(i-1);
        currentBin = sample_integrated->GetBinContent(i);

        sample_integrated->SetBinContent(i, currentBin+ previousBin);

    }

    sample_integrated->Multiply(sample_integrated);

    sample_integrated->Divide(background_integrated);

    return sample_integrated;
};

TH1F * returnKeepLessThan(TH1F * background, TH1F * sample)
{

    float previousBin;
    float currentBin;
    int nBins = background->GetNbinsX();

    TH1F* background_integrated = (TH1F*) background->Clone();
    TH1F* sample_integrated = (TH1F*) sample->Clone();

    for(int i=nBins;i>-1;i--){

        previousBin = background_integrated->GetBinContent(i+1);
        currentBin = background_integrated->GetBinContent(i);

        background_integrated->SetBinContent(i, currentBin+ previousBin);

        previousBin = sample_integrated->GetBinContent(i+1);
        currentBin = sample_integrated->GetBinContent(i);

        sample_integrated->SetBinContent(i, currentBin+ previousBin);

    }

    sample_integrated->Multiply(sample_integrated);

    sample_integrated->Divide(background_integrated);

    return sample_integrated;
};


TH1F * returnTopCut(TH1F * background, TH1F * sample, Float_t centerValue)
{

    float previousBin;
    float currentBin;
    int nBins = background->GetNbinsX();

    TH1F* background_integrated = (TH1F*) background->Clone();
    TH1F* sample_integrated = (TH1F*) sample->Clone();

    TH1F* background_integrated_temp = (TH1F*) background->Clone();
    TH1F* sample_integrated_temp = (TH1F*) sample->Clone();

    float minRange = background_integrated->GetXaxis()->GetXmin();
    float maxRange = background_integrated->GetXaxis()->GetXmax();

    float sizePerBin = (maxRange-minRange)/(float)nBins;
   

    float binOfCenter = (int)(centerValue - minRange)/sizePerBin;

    std::cout << binOfCenter << std::endl;

    if(binOfCenter > nBins)
    {
        return sample_integrated;
    }

    float range;
    int binLow;
    int binHigh;

    float totalBck = background_integrated->Integral(-1,nBins+1);
    float totalSample = sample_integrated->Integral(-1,nBins+1);

   for(int i=0;i<nBins+2;i++){


        range = (float)i*sizePerBin;
        background_integrated_temp->SetBinContent(binOfCenter-i, totalBck - background_integrated->Integral(binOfCenter-1,binOfCenter+i));
        background_integrated_temp->SetBinContent(binOfCenter+i, totalBck - background_integrated->Integral(binOfCenter-1,binOfCenter+i));
        sample_integrated_temp->SetBinContent(binOfCenter-i, totalSample - sample_integrated->Integral(binOfCenter-1,binOfCenter+i));
        sample_integrated_temp->SetBinContent(binOfCenter+i, totalSample - sample_integrated->Integral(binOfCenter-1,binOfCenter+i));
    }

    background_integrated_temp->Add(sample_integrated_temp);

    sample_integrated_temp->Multiply(sample_integrated_temp);

    sample_integrated_temp->Divide(background_integrated_temp);


    return sample_integrated_temp;
};



void make2DPlotCut(TH1F * background, TH1F * sample, TCanvas *c1, TString prefix, TString plot)
{

    float previousBin;
    float currentBin;
    int nBins = background->GetNbinsX();

    float minRange = background->GetXaxis()->GetXmin();
    float maxRange = background->GetXaxis()->GetXmax();

    float sizePerBin = (maxRange-minRange)/(float)nBins;

    TH2F * TH2F_sample = new TH2F("sample1", "sample", nBins, minRange,maxRange, nBins, minRange,maxRange  );
    TH2F * TH2F_background = new TH2F("background1", "background", nBins, minRange,maxRange, nBins, minRange,maxRange  );

    float totalBck = background->Integral(-1,nBins+1);
    float totalSample = sample->Integral(-1,nBins+1);
    for(int i =0;  i<nBins+2; i++)
    {
         for(int j =0;  j<nBins+2; j++)
        {
            float sampleCount = sample->Integral(i,j);
            float backgroundCount = background->Integral(i,j);

            float siginificance = (totalSample-sampleCount)/sqrt( totalSample-sampleCount + totalBck-backgroundCount );

            if( i<=j)
            {
                TH2F_sample->SetBinContent(i,j, siginificance);
            }
        
        }
    }

    TH2F_sample->SetStats(0);
    TH2F_sample->SetTitle(prefix+"_"+plot);
    TH2F_sample->Draw("colz");
    c1->SaveAs("./hists/"+prefix+"_"+plot+"_centerCut.png");

}



void makeStackPlot(TString prefix, TString plot, TString title){

    THStack *hs = new THStack("hs","35.9 fb^{-1} (13TeV)");

    //Open Files
    TFile *zp200           = new TFile("./output/"+ prefix + "_zp200.root");
    TFile *zp350           = new TFile("./output/"+ prefix + "_zp350.root");
    TFile *zp500           = new TFile("./output/"+ prefix + "_zp500.root");

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
    hist_DY->SetLineColor(1);
    hist_TT->SetLineColor(1);
    hist_DB->SetLineColor(1);
    hist_ST->SetLineColor(1);
    
    //Setting signal LineWidth
    hist_200->SetLineWidth(3);
    hist_350->SetLineWidth(3);
    hist_500->SetLineWidth(3);
    
    //hist_zp200->GetYaxis()->SetRangeUser(0.001,100000.);

    //Reduce number of bin
    hist_200->Rebin(4);    
    hist_350->Rebin(4);    
    hist_500->Rebin(4);    
    hist_DY->Rebin(4);    
    hist_TT->Rebin(4);    
    hist_DB->Rebin(4);    
    hist_ST->Rebin(4);    

    ////////////////////// !! Stack order !! /////////////////////
    hs->Add(hist_DB,"");
    hs->Add(hist_ST,"");
    hs->Add(hist_TT,"");
    hs->Add(hist_DY,"");

    TCanvas *c1 = new TCanvas("c1","",800,800);
    TText T; 
    c1->SetLogy();
    gPad->SetTicks();
   
    
    hs->SetMinimum(0.1);
    hs->SetMaximum(100000); 

    hs->Draw("hist ");
    hist_200->Draw("same hist");
    hist_350->Draw("same hist");
    hist_500->Draw("same hist");

    TPaveText *pt = new TPaveText(0.6378446,0.8822768,0.9072682,0.9547219,"blNDC");
    pt->SetName("title");
    pt->SetBorderSize(0);
    pt->SetFillColor(0);
    pt->SetFillStyle(0);
    pt->SetTextAlign(11);
    pt->SetTextFont(42);
    TText *AText = pt->AddText("35.9 fb^{-1} (13TeV)");
    pt->Draw();

    hs->GetXaxis()->SetTitle(title);
    hs->GetYaxis()->SetTitle("Events");

    hs->GetYaxis()->SetLabelSize(0.03);
    hs->GetYaxis()->SetTitleOffset(1.3);

    hs->GetXaxis()->SetTitleOffset(1.25);

    TLegend *leg_hist = new TLegend(0.5839599,0.6739974,0.8734336,0.8576973,NULL,"brNDC");
    leg_hist->AddEntry(hist_200,"Z' 200GeV","l");
    leg_hist->AddEntry(hist_350,"Z' 350GeV","l");
    leg_hist->AddEntry(hist_500,"Z' 500GeV","l");
    leg_hist->AddEntry(hist_DY,"DY+jets","f");
    leg_hist->AddEntry(hist_TT,"t#bar{t}","f");
    leg_hist->AddEntry(hist_ST,"tW,#bar{t}W","f");
    leg_hist->AddEntry(hist_DB,"WW, WZ, ZZ","f");

    leg_hist->Draw();

    c1->SaveAs("./hists/"+prefix+"_"+plot+"_hist.png");


    //make bkg for siginificance plot

    TH1F * hist_background = (TH1F*) hist_DB->Clone("background");
    hist_background->Add(hist_ST);
    hist_background->Add(hist_TT);
    hist_background->Add(hist_DY);


    TH1F * hist_top = (TH1F*) hist_ST->Clone("background");
    hist_top->Add(hist_TT);

    TH1F * leftCut = (TH1F*) returnKeepGreaterThan(hist_top,hist_500);

    leftCut->Draw();
    c1->SaveAs("./hists/"+prefix+"_"+plot+"_hist_keep_less_than_s_over_sqrtb.png");

    TH1F * rightCut = (TH1F*) returnKeepLessThan(hist_top,hist_500);

    rightCut->Draw();
    c1->SaveAs("./hists/"+prefix+"_"+plot+"_hist_keep_greater_than_s_over_sqrtb.png");


    TH1F * leftCutTop = (TH1F*) returnKeepGreaterThan(hist_top,hist_500);

    leftCutTop->Draw();
    c1->SaveAs("./hists/"+prefix+"_"+plot+"_hist_keep_less_than_s_over_sqrtb_tops.png");


    TH1F * rightCutTop = (TH1F*) returnKeepLessThan(hist_top,hist_500);

    rightCutTop->Draw();
    c1->SaveAs("./hists/"+prefix+"_"+plot+"_hist_keep_greater_than_s_over_sqrtb_tops.png");


    TH1F * topCut = returnTopCut(hist_top, hist_500, 120);

    topCut->Draw();
    c1->SaveAs("./hists/"+prefix+"_"+plot+"_top_cut_s_over_sqrtb_tops.png");

    make2DPlotCut(hist_top, hist_200,c1,prefix,plot);


    delete c1;

}
