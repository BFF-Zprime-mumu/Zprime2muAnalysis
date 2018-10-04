from ROOT import *

gROOT.SetBatch(True)

def CompileMacro():
    gSystem.CompileMacro("makeStackPlot.C", "gOck")

def makePlots(prefix):
    gSystem.Load("makeStackPlot_C")
    makeStackPlot(prefix,"mini_SBM_hist", "max(M_{b,lep})[GeV]")

    gSystem.Load("makeStackPlot_C")
    makeStackPlot(prefix,"HTLT_hist", "HT-LT")

    gSystem.Load("makeStackPlot_C")
    makeStackPlot(prefix,"METvsMmm_hist", "E^{miss}_{T}/M_{#mu^{+}#mu^{-}}")

#cutStrings = ["1",
#"2",
#"3",
#"4",
#"5",
#""]


cutStrings = [#"b=1_j=0",
"b=1,2_b+j=2",
"2"]

treeName = ["SimpleNtuplerDiEle","SimpleNtupler"]

CompileMacro()


for cut in cutStrings:
    for tree in treeName:
        makePlots("{0}_{1}".format(cut,tree))