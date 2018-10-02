#include <TCanvas.h>
#include <TH1.h>
#include <TFile.h>
#include <TText.h>
#include <TPaveText.h>
#include <TLegend.h>
#include <THStack.h>
#include <iostream>


void MET(TString prefix){

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
    TH1F *MET_200 = (TH1F*)zp200->Get("METvsMmm_hist");
    TH1F *MET_350 = (TH1F*)zp350->Get("METvsMmm_hist");
    TH1F *MET_500 = (TH1F*)zp500->Get("METvsMmm_hist");

    //first is named DB as it will include ww, wz, and zz
    TH1F *MET_DB = (TH1F*)WW->Get("METvsMmm_hist");
    TH1F *MET_WZ = (TH1F*)WZ->Get("METvsMmm_hist");
    TH1F *MET_ZZ = (TH1F*)ZZ->Get("METvsMmm_hist");
    MET_DB->Add(MET_WZ);
    MET_DB->Add(MET_ZZ);

    TH1F *MET_TT = (TH1F*)TT->Get("METvsMmm_hist");

    TH1F *MET_DY = (TH1F*)DY->Get("METvsMmm_hist");

    //first is named ST as it will contain top and antitop
    TH1F *MET_ST = (TH1F*)ST_tW_antitop->Get("METvsMmm_hist");
    TH1F *MET_ST_tW_top = (TH1F*)ST_tW_top->Get("METvsMmm_hist");
    MET_ST->Add(MET_ST_tW_top);

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
    hs->Add(MET_DB,"");
    hs->Add(MET_ST,"");
    hs->Add(MET_TT,"");
    hs->Add(MET_DY,"");

    TCanvas *c1 = new TCanvas("c1","",800,800);
    TText T; 
    c1->SetLogy();
    gPad->SetTicks();

    hs->SetMinimum(0.1);
    hs->SetMaximum(10000);
    
    hs->Draw("hist ");
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
    hs->GetYaxis()->SetTitleOffset(1.3);

    hs->GetXaxis()->SetTitleOffset(1.25);

    TLegend *leg_MET = new TLegend(0.5839599,0.6739974,0.8734336,0.8576973,NULL,"brNDC");
    leg_MET->AddEntry(MET_200,"Z' 200GeV","l");
    leg_MET->AddEntry(MET_350,"Z' 350GeV","l");
    leg_MET->AddEntry(MET_500,"Z' 500GeV","l");
    leg_MET->AddEntry(MET_DY,"DY+jets","f");
    leg_MET->AddEntry(MET_TT,"t#bar{t}","f");
    leg_MET->AddEntry(MET_ST,"tW,#bar{t}W","f");
    leg_MET->AddEntry(MET_DB,"WW, WZ, ZZ","f");

    leg_MET->Draw();

    c1->SaveAs("./hists/"+prefix+"_MET.png");

     //make bkg for siginificance plot
    MET_DB->Add(MET_ST);
    MET_DB->Add(MET_TT);
    MET_DB->Add(MET_DY);

    TH1F * MET_DB_copy = (TH1F*) MET_DB->Clone("DB_copy");

    TH1F * MET_200_copy = (TH1F*) MET_200->Clone("200_copy");

    //std::cout << "ComputeIntegral " << MET_DB->ComputeIntegral() << "\n";
    float previousBin;
    float currentBin;
    int nBins = MET_DB->GetNbinsX();

    //std::cout << "right cut \n";
    for(int i=1;i<nBins+2;i++){

        previousBin = MET_DB->GetBinContent(i-1);
        currentBin = MET_DB->GetBinContent(i);

        MET_DB->SetBinContent(i, currentBin+ previousBin);
        //std::cout << MET_DB->GetBinContent(i) << "\n";

        previousBin = MET_200->GetBinContent(i-1);
        currentBin = MET_200->GetBinContent(i);

        MET_200->SetBinContent(i, currentBin+ previousBin);
        //std::cout << MET_200->GetBinContent(i) << "\n";



    }



    std::cout << "left cut \n";
    for(int i=nBins;i>-1;i--){

        previousBin = MET_DB_copy->GetBinContent(i+1);
        currentBin = MET_DB_copy->GetBinContent(i);

        MET_DB_copy->SetBinContent(i, currentBin+ previousBin);
        //std::cout << MET_DB_copy->GetBinContent(i) << "\n";

        previousBin = MET_200_copy->GetBinContent(i+1);
        currentBin = MET_200_copy->GetBinContent(i);

        MET_200_copy->SetBinContent(i, currentBin+ previousBin);
        //std::cout << MET_200_copy->GetBinContent(i) << "\n";


    }

    //MET_200->Divide(MET_DB);
    MET_200->Draw();
    c1->SaveAs("./hists/"+prefix+"_MET_right_cut.png");

    MET_DB->Draw();
    c1->SaveAs("./hists/"+prefix+"_MET_DB_right_cut.png");


    MET_200->Divide(MET_DB);
    MET_200->Draw();
    c1->SaveAs("./hists/"+prefix+"_MET_right_cut_s_over_b.png");
    MET_200->Multiply(MET_DB);

    MET_DB->Add(MET_200);
    MET_200->Multiply(MET_200);
    MET_200->Divide(MET_DB);
    MET_200->Draw();
    c1->SaveAs("./hists/"+prefix+"_MET_right_cut_sig.png");




    //MET_200_copy->Divide(MET_DB_copy);
    MET_200_copy->Draw();
    c1->SaveAs("./hists/"+prefix+"_MET_left_cut.png");

    MET_DB_copy->Draw();
    c1->SaveAs("./hists/"+prefix+"_MET_DB_left_cut.png");


    MET_200_copy->Divide(MET_DB_copy);
    MET_200_copy->Draw();
    c1->SaveAs("./hists/"+prefix+"_MET_left_cut_s_over_b.png");
    MET_200_copy->Multiply(MET_DB_copy);
    
    MET_DB_copy->Add(MET_200_copy);
    MET_200_copy->Multiply(MET_200_copy);
    MET_200_copy->Divide(MET_DB_copy);
    MET_200_copy->Draw();
    c1->SaveAs("./hists/"+prefix+"_MET_left_cut_sig.png");


    delete c1;

}
