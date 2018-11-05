from ROOT import *

gROOT.SetBatch(True)

def CompileMacro():
    gSystem.CompileMacro("makeStackPlot.C", "gOck")
    gSystem.CompileMacro("makeRatioPlots.C", "gOck")
    gSystem.CompileMacro("makeNbJetNJet.C", "gOck")
    gSystem.CompileMacro("makeStackRatioPlot.C", "gOck")
    

def makePlots(prefix, postfix):
    gSystem.Load("makeStackPlot_C")
    gSystem.Load("makeStackRatioPlot_C")

    if "b=0_b+j=2" in prefix or "b=1,2_b+j=2" in prefix:
        makeStackPlot(prefix,postfix,"HTLT_hist", "\\sum_{0}^{1}p_{\\text{T}}^{\\text{jet}}-\\sum_{0}^{1}p_{\\text{T}}^{\\mathscr{l}}~[\\text{GeV}]")
        makeStackPlot(prefix,postfix,"SBM_hist", "\\text{max}(\\{\\text{M}_{\\text{jet}_{i}\\mathscr{l}_{j}},\\text{M}_{\\text{jet}_{k}\\mathscr{l}_{l}}\\}_{\\text{min}\\Delta\\text{M}})~[\\text{GeV}]")
    else:
        makeStackPlot(prefix,postfix,"HTLT_hist", "p_{\\text{T}}^{\\text{jet}}-\\sum_{0}^{1}p_{\\text{T}}^{\\mathscr{l}}~[\\text{GeV}]")
        makeStackPlot(prefix,postfix,"mini_SBM_hist", "\\text{min}(\\text{M}_{b\\mathscr{l}^{+}},\\text{M}_{b\\mathscr{l}^{-}})~[\\text{GeV}]")

    makeStackPlot(prefix,postfix,"METvsMmm_hist", "\\text{E}_{\\text{T}}^{\\text{miss}}/\\text{M}_{\\mathscr{l}^{+}\\mathscr{l}^{-}}")


    makeStackPlot(prefix,postfix,"MET_hist", "MET")

    makeStackPlot(prefix,postfix,"dilep_mass_hist", "\\text{M}_{\\mathscr{l}^{+}\\mathscr{l}^{-}}~[\\text{GeV}]")

    postFix = "_datatest"

    if "DiEle" in prefix:
        postFix = "_2016F_singleElectron"

    makeStackRatioPlot(prefix,postfix,"dilep_mass_hist","\\text{M}_{\\mathscr{l}^{+}\\mathscr{l}^{-}}~[\\text{GeV}]", postFix)
    makeStackRatioPlot(prefix,postfix,"MET_hist","MET", postFix)
    makeStackRatioPlot(prefix,postfix,"METvsMmm_hist","\\text{E}_{\\text{T}}^{\\text{miss}}/\\text{M}_{\\mathscr{l}^{+}\\mathscr{l}^{-}}", postFix)



    makeStackRatioPlot(prefix, postfix, "lepeta_p_hist", "nJet_hist", postFix)
    makeStackRatioPlot(prefix, postfix, "lepphi_p_hist", "lepphi_p_hist", postFix)
    makeStackRatioPlot(prefix, postfix, "leppT_p_hist", "leppT_p_hist", postFix)
    makeStackRatioPlot(prefix, postfix, "lepeta_n_hist", "lepeta_n_hist", postFix)
    makeStackRatioPlot(prefix, postfix, "lepphi_n_hist", "lepphi_n_hist", postFix)
    makeStackRatioPlot(prefix, postfix, "leppT_n_hist", "leppT_n_hist", postFix)
    makeStackRatioPlot(prefix, postfix, "nLeptons", "nLeptons", postFix)
    makeStackRatioPlot(prefix, postfix, "nElectrons", "nElectrons", postFix)
    makeStackRatioPlot(prefix, postfix, "nMuons", "nMuons", postFix)
    makeStackRatioPlot(prefix, postfix, "jet1eta_n_hist", "jet1eta_n_hist", postFix)
    makeStackRatioPlot(prefix, postfix, "jet1phi_n_hist", "jet1phi_n_hist", postFix)
    makeStackRatioPlot(prefix, postfix, "jet1pT_n_hist", "jet1pT_n_hist", postFix)
    makeStackRatioPlot(prefix, postfix, "jet2eta_n_hist", "jet2eta_n_hist", postFix)
    makeStackRatioPlot(prefix, postfix, "jet2phi_n_hist", "jet2phi_n_hist", postFix)
    makeStackRatioPlot(prefix, postfix, "jet2pT_n_hist", "jet2pT_n_hist", postFix)
    makeStackRatioPlot(prefix, postfix, "nJet_hist", "nJet_hist", postFix)
    makeStackRatioPlot(prefix, postfix, "jet1NonB_atleast2_eta_n_hist", "jet1NonB_atleast2_eta_n_hist", postFix)
    makeStackRatioPlot(prefix, postfix, "jet1NonB_atleast2_phi_n_hist", "jet1NonB_atleast2_phi_n_hist", postFix)
    makeStackRatioPlot(prefix, postfix, "jet1NonB_atleast2_pT_n_hist", "jet1NonB_atleast2_pT_n_hist", postFix)
    makeStackRatioPlot(prefix, postfix, "jet2NonB_atleast2_eta_n_hist", "jet2NonB_atleast2_eta_n_hist", postFix)
    makeStackRatioPlot(prefix, postfix, "jet2NonB_atleast2_phi_n_hist", "jet2NonB_atleast2_phi_n_hist", postFix)
    makeStackRatioPlot(prefix, postfix, "jet2NonB_atleast2_pT_n_hist", "jet2NonB_atleast2_pT_n_hist", postFix)
    makeStackRatioPlot(prefix, postfix, "jet1B_atleast2_eta_n_hist", "jet1B_atleast2_eta_n_hist", postFix)
    makeStackRatioPlot(prefix, postfix, "jet1B_atleast2_phi_n_hist", "jet1B_atleast2_phi_n_hist", postFix)
    makeStackRatioPlot(prefix, postfix, "jet1B_atleast2_pT_n_hist", "jet1B_atleast2_pT_n_hist", postFix)
    makeStackRatioPlot(prefix, postfix, "jet2B_atleast2_eta_n_hist", "jet2B_atleast2_eta_n_hist", postFix)
    makeStackRatioPlot(prefix, postfix, "jet2B_atleast2_phi_n_hist", "jet2B_atleast2_phi_n_hist", postFix)
    makeStackRatioPlot(prefix, postfix, "jet2B_atleast2_pT_n_hist", "jet2B_atleast2_pT_n_hist", postFix)


cutStrings = [
"b=1_j=0",
"b=1,2_b+j=2",
"b=0_b+j=2",
"b=0_j=1"
]

treeName = ["SimpleNtuplerDiEle","SimpleNtupler"]
#treeName = ["SimpleNtuplerDiEle"]
#treeName = ["SimpleNtupler"]


blinded = True

CompileMacro()

gSystem.Load("makeRatioPlots_C")
gSystem.Load("makeNbJetNJet_C")

if not blinded:
    makeRatioPlots("b=1,2_b+j=2_SimpleNtuplerDiEle", "b=0_b+j=2_SimpleNtupler","b=0_b+j=2_SimpleNtuplerDiEle", "b=1,2_b+j=2_SimpleNtupler" ,"dilep_mass_hist", "\\text{M}_{\\mathscr{l}^{+}\\mathscr{l}^{-}}~[\\text{GeV}]", "CR^{ee}_{1,2b j=2} #bullet CR^{#mu#mu}_{2j}/CR^{ee}_{2j}")
    makeRatioPlots("b=1_j=0_SimpleNtuplerDiEle", "b=0_j=1_SimpleNtupler","b=0_j=1_SimpleNtuplerDiEle", "b=1_j=0_SimpleNtupler" ,"dilep_mass_hist", "\\text{M}_{\\mathscr{l}^{+}\\mathscr{l}^{-}}~[\\text{GeV}]", "CR^{ee}_{1b j=1} #bullet CR^{#mu#mu}_{1j}/CR^{ee}_{1j}")
makeNbJetNJet("b=0_j=1_SimpleNtupler","njvsnbj_hist")

postfix = "_2016"
#cutStrings = []
for cut in cutStrings:
    for tree in treeName:
        if (cut == "b=1_j=0" or cut == "b=1,2_b+j=2") and tree == "SimpleNtupler" and blinded:
            continue
        makePlots("{0}_{1}".format(cut,tree),postfix)

