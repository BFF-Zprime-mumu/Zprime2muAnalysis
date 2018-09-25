from ROOT import *


def CompileMacro():
    gSystem.CompileMacro("HTLT.C", "gOck")
    gSystem.CompileMacro("MET.C", "gOck")
    gSystem.CompileMacro("TMB.C", "gOck")

def makePlots(prefix):

    gSystem.Load("HTLT_C")
    HTLT(prefix)

    gSystem.Load("MET_C")
    MET(prefix)

    gSystem.Load("TMB_C")
    TMB(prefix)


cutStrings = ["1",
"2",
"3",
"4",
"5",
""]

CompileMacro()


for cut in cutStrings:
    makePlots(cut)