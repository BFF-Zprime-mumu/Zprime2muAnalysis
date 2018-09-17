import ROOT as r
import math

c1 = r.TCanvas("c1", "c1",500, 600)

prefix = "1"

ZZ_TuneCUETP8M1_13TeV = r.TFile("./output/{0}_ZZ_TuneCUETP8M1_13TeV.root".format(prefix), "read")
TTTo2L2Nu_TuneCUETP8M2_ttHtranche3_13TeV = r.TFile("./output/{0}_TTTo2L2Nu_TuneCUETP8M2_ttHtranche3_13TeV.root".format(prefix), "read")
DYJetsToLL_M = r.TFile("./output/{0}_DYJetsToLL_M.root".format(prefix), "read")
WWTo2L2Nu_13TeV = r.TFile("./output/{0}_WWTo2L2Nu_13TeV.root".format(prefix), "read")
ST_tW_top_5f_inclusiveDecays_13TeV = r.TFile("./output/{0}_ST_tW_top_5f_inclusiveDecays_13TeV.root".format(prefix), "read")
ST_tW_antitop_5f_inclusiveDecays_13TeV = r.TFile("./output/{0}_ST_tW_antitop_5f_inclusiveDecays_13TeV.root".format(prefix), "read")
WZ_TuneCUETP8M1_13TeV = r.TFile("./output/{0}_WZ_TuneCUETP8M1_13TeV.root".format(prefix), "read")

zp200 = r.TFile("./output/{0}_zp200.root".format(prefix), "read")
zp350 = r.TFile("./output/{0}_zp350.root".format(prefix), "read")
zp500 = r.TFile("./output/{0}_zp500.root".format(prefix), "read")


def rebinTHStack(THStack,rebin):
    for hist in THStack.GetHists():
        hist.Rebin(rebin)

r.gStyle.SetOptStat(0)

Lumi = 35900
#Lumi = 100000

output_text = "THStack_"
output_text = output_text + "_" + prefix

no_xsection = False

draw_leg = True

if no_xsection: output_text = output_text+"_no_xsection"
if draw_leg: output_text = output_text+"_leg"


log = True
if log: 
    r.gPad.SetLogy()
    output_text = output_text+"_log"


def returnSampleStats(name, xsection, Lumi, hist):
    events = float(xsection)*float(Lumi)
    entries = float(hist.GetEntries())
    norm = float(events)/float(entries)
    print "name, norm, entries, evetn", name, norm , entries, events
    return norm , entries, events


ZZ_TuneCUETP8M1_13TeV_h = ZZ_TuneCUETP8M1_13TeV.Get("run_hist")
ZZ_TuneCUETP8M1_13TeV_xsection = 1
if no_xsection: ZZ_TuneCUETP8M1_13TeV_xsection = 1
ZZ_TuneCUETP8M1_13TeV_norm, ZZ_TuneCUETP8M1_13TeV_entries, ZZ_TuneCUETP8M1_13TeV_events = returnSampleStats("ZZ_TuneCUETP8M1_13TeV", ZZ_TuneCUETP8M1_13TeV_xsection,Lumi, ZZ_TuneCUETP8M1_13TeV_h)

TTTo2L2Nu_TuneCUETP8M2_ttHtranche3_13TeV_h = TTTo2L2Nu_TuneCUETP8M2_ttHtranche3_13TeV.Get("run_hist")
TTTo2L2Nu_TuneCUETP8M2_ttHtranche3_13TeV_xsection = 1
if no_xsection: TTTo2L2Nu_TuneCUETP8M2_ttHtranche3_13TeV_xsection = 1
TTTo2L2Nu_TuneCUETP8M2_ttHtranche3_13TeV_norm, TTTo2L2Nu_TuneCUETP8M2_ttHtranche3_13TeV_entries, TTTo2L2Nu_TuneCUETP8M2_ttHtranche3_13TeV_events = returnSampleStats("TTTo2L2Nu_TuneCUETP8M2_ttHtranche3_13TeV", TTTo2L2Nu_TuneCUETP8M2_ttHtranche3_13TeV_xsection,Lumi, TTTo2L2Nu_TuneCUETP8M2_ttHtranche3_13TeV_h)

DYJetsToLL_M_h = DYJetsToLL_M.Get("run_hist")
DYJetsToLL_M_xsection = 1
if no_xsection: DYJetsToLL_M_xsection = 1
DYJetsToLL_M_norm, DYJetsToLL_M_entries, DYJetsToLL_M_events = returnSampleStats("DYJetsToLL_M", DYJetsToLL_M_xsection,Lumi, DYJetsToLL_M_h)

WWTo2L2Nu_13TeV_h = WWTo2L2Nu_13TeV.Get("run_hist")
WWTo2L2Nu_13TeV_xsection = 1
if no_xsection: WWTo2L2Nu_13TeV_xsection = 1
WWTo2L2Nu_13TeV_norm, WWTo2L2Nu_13TeV_entries, WWTo2L2Nu_13TeV_events = returnSampleStats("WWTo2L2Nu_13TeV", WWTo2L2Nu_13TeV_xsection,Lumi, WWTo2L2Nu_13TeV_h)

ST_tW_top_5f_inclusiveDecays_13TeV_h = ST_tW_top_5f_inclusiveDecays_13TeV.Get("run_hist")
ST_tW_top_5f_inclusiveDecays_13TeV_xsection = 1
if no_xsection: ST_tW_top_5f_inclusiveDecays_13TeV_xsection = 1
ST_tW_top_5f_inclusiveDecays_13TeV_norm, ST_tW_top_5f_inclusiveDecays_13TeV_entries, ST_tW_top_5f_inclusiveDecays_13TeV_events = returnSampleStats("ST_tW_top_5f_inclusiveDecays_13TeV", ST_tW_top_5f_inclusiveDecays_13TeV_xsection,Lumi, ST_tW_top_5f_inclusiveDecays_13TeV_h)

ST_tW_antitop_5f_inclusiveDecays_13TeV_h = ST_tW_antitop_5f_inclusiveDecays_13TeV.Get("run_hist")
ST_tW_antitop_5f_inclusiveDecays_13TeV_xsection = 1
if no_xsection: ST_tW_antitop_5f_inclusiveDecays_13TeV_xsection = 1
ST_tW_antitop_5f_inclusiveDecays_13TeV_norm, ST_tW_antitop_5f_inclusiveDecays_13TeV_entries, ST_tW_antitop_5f_inclusiveDecays_13TeV_events = returnSampleStats("ST_tW_antitop_5f_inclusiveDecays_13TeV", ST_tW_antitop_5f_inclusiveDecays_13TeV_xsection,Lumi, ST_tW_antitop_5f_inclusiveDecays_13TeV_h)

WZ_TuneCUETP8M1_13TeV_h = WZ_TuneCUETP8M1_13TeV.Get("run_hist")
WZ_TuneCUETP8M1_13TeV_xsection = 1
if no_xsection: WZ_TuneCUETP8M1_13TeV_xsection = 1
WZ_TuneCUETP8M1_13TeV_norm, WZ_TuneCUETP8M1_13TeV_entries, WZ_TuneCUETP8M1_13TeV_events = returnSampleStats("WZ_TuneCUETP8M1_13TeV", WZ_TuneCUETP8M1_13TeV_xsection,Lumi, WZ_TuneCUETP8M1_13TeV_h)

zp200_h = zp200.Get("run_hist")
zp200_xsection = 1
if no_xsection: zp200_xsection = 1
zp200_norm, zp200_entries, zp200_events = returnSampleStats("zp200", zp200_xsection,Lumi, zp200_h)

zp350_h = zp350.Get("run_hist")
zp350_xsection = 1
if no_xsection: zp350_xsection = 1
zp350_norm, zp350_entries, zp350_events = returnSampleStats("zp350", zp350_xsection,Lumi, zp350_h)


zp500_h = zp500.Get("run_hist")
zp500_xsection = 1
if no_xsection: zp500_xsection = 1
zp500_norm, zp500_entries, zp500_events = returnSampleStats("zp500", zp500_xsection,Lumi, zp500_h)



ZZ_TuneCUETP8M1_13TeV.cd()
dirList = r.gDirectory.GetListOfKeys()
leg = r.TLegend(.6, .5, .89, .89)
for k1 in dirList: 
    zp200_h = k1.ReadObj()
    name =  zp200_h.GetName()

    zp350_h = zp350.Get(name)
    zp500_h = zp500.Get(name)

    ZZ_TuneCUETP8M1_13TeV_h = ZZ_TuneCUETP8M1_13TeV.Get(name)
    TTTo2L2Nu_TuneCUETP8M2_ttHtranche3_13TeV_h = TTTo2L2Nu_TuneCUETP8M2_ttHtranche3_13TeV.Get(name)
    DYJetsToLL_M_h = DYJetsToLL_M.Get(name)
    WWTo2L2Nu_13TeV_h = WWTo2L2Nu_13TeV.Get(name)
    ST_tW_top_5f_inclusiveDecays_13TeV_h = ST_tW_top_5f_inclusiveDecays_13TeV.Get(name)
    ST_tW_antitop_5f_inclusiveDecays_13TeV_h = ST_tW_antitop_5f_inclusiveDecays_13TeV.Get(name)
    WZ_TuneCUETP8M1_13TeV_h = WZ_TuneCUETP8M1_13TeV.Get(name)


    print "get", name
    hs = r.THStack("hs",name)
    if(zp200_h.GetEntries() > 0):


        #zp350_h.Scale(zp350_norm)
        #zp500_h.Scale(zp500_norm)

        #zp200_h.Scale(zp200_norm)
        #ZZ_TuneCUETP8M1_13TeV_h.Scale(ZZ_TuneCUETP8M1_13TeV_norm)
        #TTTo2L2Nu_TuneCUETP8M2_ttHtranche3_13TeV_h.Scale(TTTo2L2Nu_TuneCUETP8M2_ttHtranche3_13TeV_norm)
        #DYJetsToLL_M_h.Scale(DYJetsToLL_M_norm)
        #WWTo2L2Nu_13TeV_h.Scale(WWTo2L2Nu_13TeV_norm)
        #ST_tW_top_5f_inclusiveDecays_13TeV_h.Scale(ST_tW_top_5f_inclusiveDecays_13TeV_norm)
        #ST_tW_antitop_5f_inclusiveDecays_13TeV_h.Scale(ST_tW_antitop_5f_inclusiveDecays_13TeV_norm)
        #WZ_TuneCUETP8M1_13TeV_h.Scale(WZ_TuneCUETP8M1_13TeV_norm)

        ZZ_TuneCUETP8M1_13TeV_h.SetFillColor(91)
        TTTo2L2Nu_TuneCUETP8M2_ttHtranche3_13TeV_h.SetFillColor(52)
        DYJetsToLL_M_h.SetFillColor(60)
        WWTo2L2Nu_13TeV_h.SetFillColor(8)
        ST_tW_top_5f_inclusiveDecays_13TeV_h.SetFillColor(2)
        ST_tW_antitop_5f_inclusiveDecays_13TeV_h.SetFillColor(4)
        WZ_TuneCUETP8M1_13TeV_h.SetFillColor(4)


        #zp350_h.Rebin(2)
        #zp500_h.Rebin(2)
        #zp200_h.Rebin(2)
        #ZZ_TuneCUETP8M1_13TeV_h.Rebin(2)
        #TTTo2L2Nu_TuneCUETP8M2_ttHtranche3_13TeV_h.Rebin(2)
        #DYJetsToLL_M_h.Rebin(2)
        #WWTo2L2Nu_13TeV_h.Rebin(2)
        #ST_tW_top_5f_inclusiveDecays_13TeV_h.Rebin(2)
        #ST_tW_antitop_5f_inclusiveDecays_13TeV_h.Rebin(2)
        #WZ_TuneCUETP8M1_13TeV_h.Rebin(2)

        zp200_h.SetLineColor(3)
        zp200_h.SetMarkerStyle(8)
        zp200_h.SetMarkerColor(3)
        zp200_h.SetMarkerSize(1)
        zp200_h.SetFillColorAlpha(3,0)

        zp350_h.SetLineColor(2)
        zp350_h.SetMarkerStyle(8)
        zp350_h.SetMarkerColor(2)
        zp350_h.SetMarkerSize(1)
        zp350_h.SetFillColorAlpha(2,0)


        zp500_h.SetLineColor(1)
        zp500_h.SetMarkerStyle(8)
        zp500_h.SetMarkerColor(1)
        zp500_h.SetMarkerSize(1)
        zp500_h.SetFillColorAlpha(1,0)



        leg.Clear()
        leg.AddEntry(zp200_h, "zp200_h", "l")
        leg.AddEntry(zp350_h, "zp350_h", "l")
        leg.AddEntry(zp500_h, "zp500_h", "l")
        leg.AddEntry(ZZ_TuneCUETP8M1_13TeV_h, "ZZ_TuneCUETP8M1_13TeV_h", "f")
        leg.AddEntry(TTTo2L2Nu_TuneCUETP8M2_ttHtranche3_13TeV_h, "TTTo2L2Nu_TuneCUETP8M2_ttHtranche3_13TeV_h", "f")
        leg.AddEntry(DYJetsToLL_M_h, "DYJetsToLL_M_h", "f")
        leg.AddEntry(WWTo2L2Nu_13TeV_h, "WWTo2L2Nu_13TeV_h", "f")
        leg.AddEntry(ST_tW_top_5f_inclusiveDecays_13TeV_h, "ST_tW_top_5f_inclusiveDecays_13TeV_h", "f")
        leg.AddEntry(ST_tW_antitop_5f_inclusiveDecays_13TeV_h, "ST_tW_antitop_5f_inclusiveDecays_13TeV_h", "f")
        leg.AddEntry(WZ_TuneCUETP8M1_13TeV_h, "WZ_TuneCUETP8M1_13TeV_h", "f")
        leg.SetBorderSize(0);




        #hs.Add(ZZ_TuneCUETP8M1_13TeV_h)
        hs.Add(TTTo2L2Nu_TuneCUETP8M2_ttHtranche3_13TeV_h)
        hs.Add(DYJetsToLL_M_h)
        hs.Add(WWTo2L2Nu_13TeV_h)
        hs.Add(ST_tW_top_5f_inclusiveDecays_13TeV_h)
        hs.Add(ST_tW_antitop_5f_inclusiveDecays_13TeV_h)
        hs.Add(WZ_TuneCUETP8M1_13TeV_h)
        '''
        rebinTHStack(hs,10)
        #hs.Rebin(10)
        RH_h.Rebin(10)
        LH_h.Rebin(10)
        '''
        hs.Draw("HIST")
        hs.SetMinimum(.1)
        zp200_h.Draw("same")
        zp350_h.Draw("same")
        zp500_h.Draw("same")
        if draw_leg: leg.Draw()
        c1.SaveAs("hists/{0}_{1}.png".format(output_text, name ))


        ZZ_TuneCUETP8M1_13TeV_h.Add(TTTo2L2Nu_TuneCUETP8M2_ttHtranche3_13TeV_h)
        ZZ_TuneCUETP8M1_13TeV_h.Add(DYJetsToLL_M_h)
        ZZ_TuneCUETP8M1_13TeV_h.Add(WWTo2L2Nu_13TeV_h)
        ZZ_TuneCUETP8M1_13TeV_h.Add(ST_tW_top_5f_inclusiveDecays_13TeV_h)
        ZZ_TuneCUETP8M1_13TeV_h.Add(ST_tW_antitop_5f_inclusiveDecays_13TeV_h)
        ZZ_TuneCUETP8M1_13TeV_h.Add(WZ_TuneCUETP8M1_13TeV_h)

        for i in reversed(xrange(ZZ_TuneCUETP8M1_13TeV_h.GetNbinsX() +1 )):
            #print i
            #print DY_100_250_h.GetBinContent(i), DY_100_250_h.GetBinContent(i+1)

            ZZ_TuneCUETP8M1_13TeV_h.SetBinContent(i,  ZZ_TuneCUETP8M1_13TeV_h.GetBinContent(i) + ZZ_TuneCUETP8M1_13TeV_h.GetBinContent(i+1) )

            zp200_h.SetBinContent(i,  zp200_h.GetBinContent(i) + zp200_h.GetBinContent(i+1) )




        zp200_h.Divide(ZZ_TuneCUETP8M1_13TeV_h)


        zp200_h.Draw()
        c1.SaveAs("hists/{0}_{1}_significance_left_cut.png".format(output_text, name ))


'''
        if name == "TH1F_cutflow":
            for bins in RH_h:
                print bins
            DY_100_250_h.Add(DY_250_400_h)
            DY_100_250_h.Add(DY_400_650_h)
            DY_100_250_h.Add(DY_650_Inf_h)
            DY_100_250_h.Add(ST_t_anti_h)
            DY_100_250_h.Add(ST_t_top_h)
            DY_100_250_h.Add(ST_tw_anti_h)
            DY_100_250_h.Add(ST_tw_top_h)
            DY_100_250_h.Add(ST_s_h)
            DY_100_250_h.Add(TTJets_h)
            for bins in DY_100_250_h:
                print bins  
'''        
