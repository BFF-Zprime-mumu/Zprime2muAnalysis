from ROOT import *
from cut_flow import cutStrings

gROOT.SetBatch(True)

def CompileMacro():
    gSystem.CompileMacro("makeStackPlot.C", "gOck")
    gSystem.CompileMacro("makeRatioPlots.C", "gOck")
    gSystem.CompileMacro("makeNbJetNJet.C", "gOck")

def makePlots(prefix, postfix):
    gSystem.Load("makeStackPlot_C")

    if "b0bj2" in prefix or "b12bj2" in prefix:
        makeStackPlot(prefix,postfix,"HTLT_hist", "\\sum_{0}^{1}p_{\\text{T}}^{\\text{jet}}-\\sum_{0}^{1}p_{\\text{T}}^{\\mathscr{l}}~[\\text{GeV}]")
        makeStackPlot(prefix,postfix,"SBM_hist", "\\text{max}(\\{\\text{M}_{\\text{jet}_{i}\\mathscr{l}_{j}},\\text{M}_{\\text{jet}_{k}\\mathscr{l}_{l}}\\}_{\\text{min}\\Delta\\text{M}})~[\\text{GeV}]")
    else:
        makeStackPlot(prefix,postfix,"HTLT_hist", "p_{\\text{T}}^{\\text{jet}}-\\sum_{0}^{1}p_{\\text{T}}^{\\mathscr{l}}~[\\text{GeV}]")
        makeStackPlot(prefix,postfix,"mini_SBM_hist", "\\text{min}(\\text{M}_{b\\mathscr{l}^{+}},\\text{M}_{b\\mathscr{l}^{-}})~[\\text{GeV}]")

    makeStackPlot(prefix,postfix,"METvsMmm_hist", "\\text{E}_{\\text{T}}^{\\text{miss}}/\\text{M}_{\\mathscr{l}^{+}\\mathscr{l}^{-}}")

    makeStackPlot(prefix,postfix,"dilep_mass_hist", "\\text{M}_{\\mathscr{l}^{+}\\mathscr{l}^{-}}~[\\text{GeV}]")


treeName = ["SimpleNtuplerDiEle","SimpleNtupler"]

blinded = True

CompileMacro()

gSystem.Load("makeRatioPlots_C")
gSystem.Load("makeNbJetNJet_C")

if not blinded:
    makeRatioPlots("b12bj2_SimpleNtuplerDiEle", "b0bj2_SimpleNtupler","b0bj2_SimpleNtuplerDiEle", "b12bj2_SimpleNtupler" ,"dilep_mass_hist", "\\text{M}_{\\mathscr{l}^{+}\\mathscr{l}^{-}}~[\\text{GeV}]", "CR^{ee}_{1,2b j=2} #bullet CR^{#mu#mu}_{2j}/CR^{ee}_{2j}")
    makeRatioPlots("b1j0_SimpleNtuplerDiEle", "b0j1_SimpleNtupler","b0j1_SimpleNtuplerDiEle", "b1j0_SimpleNtupler" ,"dilep_mass_hist", "\\text{M}_{\\mathscr{l}^{+}\\mathscr{l}^{-}}~[\\text{GeV}]", "CR^{ee}_{1b j=1} #bullet CR^{#mu#mu}_{1j}/CR^{ee}_{1j}")
makeNbJetNJet("b0j1_SimpleNtupler","njvsnbj_hist")

postfix = "_2016"
for cut in cutStrings:
    for tree in treeName:
        if (cut == "b1j0" or cut == "b12bj2") and tree == "SimpleNtupler" and blinded:
            continue
        makePlots("{0}_{1}".format(cut,tree),postfix)

