from ROOT import *

gROOT.SetBatch(True)

def CompileMacro():
    gSystem.CompileMacro("makeStackPlot.C", "gOck")

def makePlots(prefix):
    gSystem.Load("makeStackPlot_C")
    makeStackPlot(prefix,"mini_SBM_hist")

    gSystem.Load("makeStackPlot_C")
    makeStackPlot(prefix,"HTLT_hist")

    gSystem.Load("makeStackPlot_C")
    makeStackPlot(prefix,"METvsMmm_hist")

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