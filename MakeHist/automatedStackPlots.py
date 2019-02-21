from ROOT import *

gROOT.SetBatch(True)

def CompileMacro():
    gSystem.CompileMacro("makeStackPlot.C", "gOck")
    gSystem.CompileMacro("makeRatioPlots.C", "gOck")
    gSystem.CompileMacro("makeNbJetNJet.C", "gOck")
    gSystem.CompileMacro("makeStackRatioPlot.C", "gOck")
    gSystem.CompileMacro("makeStackRatioPlotEEvMM.C", "gOck")
    

def makePlots(prefix, postfix):
    gSystem.Load("makeStackPlot_C")
    gSystem.Load("makeStackRatioPlot_C")


    '''
    if "b=0_b+j=2" in prefix or "b=1,2_b+j=2" in prefix:
        makeStackPlot(prefix,postfix,"HTLT_hist", "\\sum_{0}^{1}p_{\\text{T}}^{\\text{jet}}-\\sum_{0}^{1}p_{\\text{T}}^{\\mathscr{l}}~[\\text{GeV}]")
        makeStackPlot(prefix,postfix,"SBM_hist", "\\text{max}(\\{\\text{M}_{\\text{jet}_{i}\\mathscr{l}_{j}},\\text{M}_{\\text{jet}_{k}\\mathscr{l}_{l}}\\}_{\\text{min}\\Delta\\text{M}})~[\\text{GeV}]")
    else:
        makeStackPlot(prefix,postfix,"HTLT_hist", "p_{\\text{T}}^{\\text{jet}}-\\sum_{0}^{1}p_{\\text{T}}^{\\mathscr{l}}~[\\text{GeV}]")
        makeStackPlot(prefix,postfix,"mini_SBM_hist", "\\text{min}(\\text{M}_{b\\mathscr{l}^{+}},\\text{M}_{b\\mathscr{l}^{-}})~[\\text{GeV}]")

    makeStackPlot(prefix,postfix,"METvsMmm_hist", "\\text{E}_{\\text{T}}^{\\text{miss}}/\\text{M}_{\\mathscr{l}^{+}\\mathscr{l}^{-}}")


    makeStackPlot(prefix,postfix,"MET_hist", "MET")

    makeStackPlot(prefix,postfix,"dilep_mass_hist", "\\text{M}_{\\mathscr{l}^{+}\\mathscr{l}^{-}}~[\\text{GeV}]")
    '''
    
    postFix = "_datatest"
    postFix = "_2016_sepReReco"
    postFix = "_2016_singleMu"
    dataPostfix = "_2016_SingleMu"
    #postFix = "_2016G_SingleMu"
    if "DiEle" in prefix:
        postFix = "_2016F_singleElectron"
        postFix = "_2016_singleElectron"
        dataPostfix = "_2016_SingleElectron"

    if "b=0_b+j=2" in prefix or "b=1,2_b+j=2" in prefix:
        makeStackRatioPlot(prefix,postfix,"HTLT_hist", "\\sum_{0}^{1}p_{\\text{T}}^{\\text{jet}}-\\sum_{0}^{1}p_{\\text{T}}^{\\mathscr{l}}~[\\text{GeV}]", dataPostfix)
        makeStackRatioPlot(prefix,postfix,"SBM_hist", "\\text{max}(\\{\\text{M}_{\\text{jet}_{i}\\mathscr{l}_{j}},\\text{M}_{\\text{jet}_{k}\\mathscr{l}_{l}}\\}_{\\text{min}\\Delta\\text{M}})~[\\text{GeV}]", dataPostfix)
    else:
        makeStackRatioPlot(prefix,postfix,"HTLT_hist", "p_{\\text{T}}^{\\text{jet}}-\\sum_{0}^{1}p_{\\text{T}}^{\\mathscr{l}}~[\\text{GeV}]", dataPostfix)
        makeStackRatioPlot(prefix,postfix,"mini_SBM_hist", "\\text{min}(\\text{M}_{b\\mathscr{l}^{+}},\\text{M}_{b\\mathscr{l}^{-}})~[\\text{GeV}]", dataPostfix)

    
    makeStackRatioPlot(prefix,postfix,"dilep_mass_hist","\\text{M}_{\\mathscr{l}^{+}\\mathscr{l}^{-}}~[\\text{GeV}]", dataPostfix)
    makeStackRatioPlot(prefix,postfix,"MET_hist","MET", dataPostfix)
    makeStackRatioPlot(prefix,postfix,"METvsMmm_hist","\\text{E}_{\\text{T}}^{\\text{miss}}/\\text{M}_{\\mathscr{l}^{+}\\mathscr{l}^{-}}", dataPostfix)



    makeStackRatioPlot(prefix, postfix, "lepeta_p_hist", "nJet_hist", dataPostfix)
    makeStackRatioPlot(prefix, postfix, "lepphi_p_hist", "lepphi_p_hist", dataPostfix)
    makeStackRatioPlot(prefix, postfix, "leppT_p_hist", "leppT_p_hist", dataPostfix)
    makeStackRatioPlot(prefix, postfix, "lepeta_n_hist", "lepeta_n_hist", dataPostfix)
    makeStackRatioPlot(prefix, postfix, "lepphi_n_hist", "lepphi_n_hist", dataPostfix)
    makeStackRatioPlot(prefix, postfix, "leppT_n_hist", "leppT_n_hist", dataPostfix)
    makeStackRatioPlot(prefix, postfix, "nLeptons", "nLeptons", dataPostfix)
    makeStackRatioPlot(prefix, postfix, "nElectrons", "nElectrons", dataPostfix)
    makeStackRatioPlot(prefix, postfix, "nMuons", "nMuons", dataPostfix)
    makeStackRatioPlot(prefix, postfix, "jet1eta_n_hist", "jet1eta_n_hist", dataPostfix)
    makeStackRatioPlot(prefix, postfix, "jet1phi_n_hist", "jet1phi_n_hist", dataPostfix)
    makeStackRatioPlot(prefix, postfix, "jet1pT_n_hist", "jet1pT_n_hist", dataPostfix)
    makeStackRatioPlot(prefix, postfix, "jet2eta_n_hist", "jet2eta_n_hist", dataPostfix)
    makeStackRatioPlot(prefix, postfix, "jet2phi_n_hist", "jet2phi_n_hist", dataPostfix)
    makeStackRatioPlot(prefix, postfix, "jet2pT_n_hist", "jet2pT_n_hist", dataPostfix)
    makeStackRatioPlot(prefix, postfix, "nJet_hist", "nJet_hist", dataPostfix)
    makeStackRatioPlot(prefix, postfix, "jet1NonB_atleast2_eta_n_hist", "jet1NonB_atleast2_eta_n_hist", dataPostfix)
    makeStackRatioPlot(prefix, postfix, "jet1NonB_atleast2_phi_n_hist", "jet1NonB_atleast2_phi_n_hist", dataPostfix)
    makeStackRatioPlot(prefix, postfix, "jet1NonB_atleast2_pT_n_hist", "jet1NonB_atleast2_pT_n_hist", dataPostfix)
    makeStackRatioPlot(prefix, postfix, "jet2NonB_atleast2_eta_n_hist", "jet2NonB_atleast2_eta_n_hist", dataPostfix)
    makeStackRatioPlot(prefix, postfix, "jet2NonB_atleast2_phi_n_hist", "jet2NonB_atleast2_phi_n_hist", dataPostfix)
    makeStackRatioPlot(prefix, postfix, "jet2NonB_atleast2_pT_n_hist", "jet2NonB_atleast2_pT_n_hist", dataPostfix)
    makeStackRatioPlot(prefix, postfix, "jet1B_atleast2_eta_n_hist", "jet1B_atleast2_eta_n_hist", dataPostfix)
    makeStackRatioPlot(prefix, postfix, "jet1B_atleast2_phi_n_hist", "jet1B_atleast2_phi_n_hist", dataPostfix)
    makeStackRatioPlot(prefix, postfix, "jet1B_atleast2_pT_n_hist", "jet1B_atleast2_pT_n_hist", dataPostfix)
    makeStackRatioPlot(prefix, postfix, "jet2B_atleast2_eta_n_hist", "jet2B_atleast2_eta_n_hist", dataPostfix)
    makeStackRatioPlot(prefix, postfix, "jet2B_atleast2_phi_n_hist", "jet2B_atleast2_phi_n_hist", dataPostfix)
    makeStackRatioPlot(prefix, postfix, "jet2B_atleast2_pT_n_hist", "jet2B_atleast2_pT_n_hist", dataPostfix)
    makeStackRatioPlot(prefix, postfix, "nbjet_hist", "nbjet_hist", dataPostfix)
    
    makeStackRatioPlot(prefix, postfix, "jetpT_noB_hist", "jetpT_noB_hist", dataPostfix)
    makeStackRatioPlot(prefix, postfix, "jeteta_noB_hist", "jeteta_noB_hist", dataPostfix)

    makeStackRatioPlot(prefix, postfix, "dilep_mass_hist_before_cut", "dilep_mass_hist_before_cut", dataPostfix)


    makeStackRatioPlot(prefix, postfix, "lep1pT_p_hist", "ep1pT_p_hist", dataPostfix)
    makeStackRatioPlot(prefix, postfix, "lep1eta_p_hist", "ep1eta_p_hist", dataPostfix)
    makeStackRatioPlot(prefix, postfix, "lep1phi_p_hist", "ep1phi_p_hist", dataPostfix)
    makeStackRatioPlot(prefix, postfix, "lep1Iso_p_hist", "ep1Iso_p_hist", dataPostfix)
    makeStackRatioPlot(prefix, postfix, "lep2pT_p_hist", "ep2pT_p_hist", dataPostfix)
    makeStackRatioPlot(prefix, postfix, "lep2eta_p_hist", "ep2eta_p_hist", dataPostfix)
    makeStackRatioPlot(prefix, postfix, "lep2phi_p_hist", "ep2phi_p_hist", dataPostfix)
    makeStackRatioPlot(prefix, postfix, "lep2Iso_p_hist", "ep2Iso_p_hist", dataPostfix)
    makeStackRatioPlot(prefix, postfix, "lepDphi", "epDphi", dataPostfix)
    makeStackRatioPlot(prefix, postfix, "lepDpt", "epDpt", dataPostfix)
    makeStackRatioPlot(prefix, postfix, "lepDeta", "epDeta", dataPostfix)
    makeStackRatioPlot(prefix, postfix, "lepDr", "epDr", dataPostfix)
    makeStackRatioPlot(prefix, postfix, "lepSumPt", "epSumPt", dataPostfix)
    makeStackRatioPlot(prefix, postfix, "lepDphi_anti_z_cut", "lepDphi_anti_z_cut", dataPostfix)
    makeStackRatioPlot(prefix, postfix, "lepDphi_iso_cut", "lepDphi_iso_cut", dataPostfix)
    makeStackRatioPlot(prefix, postfix, "lepDphi_z_cut", "lepDphi_z_cut", dataPostfix)


    makeStackRatioPlot(prefix, postfix, "dilep_mass_hist_z_cut", "dilep_mass_hist_z_cut", dataPostfix)


    makeStackRatioPlot(prefix,postfix,"jetDphi", "jetDphi", dataPostfix)
    makeStackRatioPlot(prefix,postfix,"jetDphi_z_cut", "jetDphi_z_cut", dataPostfix)
    makeStackRatioPlot(prefix,postfix,"jetDphi_anti_z_cut", "jetDphi_anti_z_cut", dataPostfix)

    makeStackRatioPlot(prefix,postfix,"jetDpt", "jetDpt", dataPostfix)
    makeStackRatioPlot(prefix,postfix,"jetDeta", "jetDeta", dataPostfix)
    makeStackRatioPlot(prefix,postfix,"jetDr", "jetDr", dataPostfix)
    makeStackRatioPlot(prefix,postfix,"jetSumPt", "jetSumPt", dataPostfix)

    makeStackRatioPlot(prefix,postfix,"lepjetDphi", "lepjetDphi", dataPostfix)
    makeStackRatioPlot(prefix,postfix,"lepjetDphi_z_cut", "lepjetDphi_z_cut", dataPostfix)
    makeStackRatioPlot(prefix,postfix,"lepjetDphi_anti_z_cut", "lepjetDphi_anti_z_cut", dataPostfix)

    makeStackRatioPlot(prefix,postfix,"lepjetDpt", "lepjetDpt", dataPostfix)
    makeStackRatioPlot(prefix,postfix,"lepjetDeta", "lepjetDeta", dataPostfix)
    makeStackRatioPlot(prefix,postfix,"lepjetDr", "lepjetDr", dataPostfix)
    makeStackRatioPlot(prefix,postfix,"lepjetSumPt", "lepjetSumPt", dataPostfix)

    makeStackRatioPlot(prefix,postfix,"MET_hist_z_cut", "MET_hist_z_cut", dataPostfix)
    makeStackRatioPlot(prefix,postfix,"SBM_hist_z_cut", "SBM_hist_z_cut", dataPostfix)
    makeStackRatioPlot(prefix,postfix,"METvsMmm_hist_z_cut", "METvsMmm_hist_z_cut", dataPostfix)
    makeStackRatioPlot(prefix,postfix,"HTLT_hist_z_cut", "HTLT_hist_z_cut", dataPostfix)

    makeStackRatioPlot(prefix,postfix,"dilep_mass_hist_z_cut_wide", "dilep_mass_hist_z_cut_wide", dataPostfix)
    makeStackRatioPlot(prefix,postfix,"dilep_mass_hist_z_cut_highMass", "dilep_mass_hist_z_cut_highMass", dataPostfix)

    makeStackRatioPlot(prefix,postfix,"npv_hist_weighted", "npv_hist_weighted", dataPostfix)

    makeStackRatioPlot(prefix,postfix,"npv_hist", "npv_hist", dataPostfix)

    makeStackRatioPlot(prefix,postfix,"lepIso_hist_z_cut", "lepIso_hist_z_cut", dataPostfix)
    makeStackRatioPlot(prefix,postfix,"lepIso_hist", "lepIso_hist", dataPostfix)
    



cutStrings = [
#"b=1_j=0",
#"b=1,2_b+j=2",
"b=0_b+j=2",
#"b=0_j=1"
]

#treeName = ["SimpleNtuplerDiEle","SimpleNtupler"]
#treeName = ["SimpleNtuplerDiEle"]
treeName = ["SimpleNtupler"]

#treeName = ["SimpleNtuplerEmu"]



blinded = False

CompileMacro()

gSystem.Load("makeRatioPlots_C")
gSystem.Load("makeNbJetNJet_C")


if not blinded:
    makeRatioPlots("b=1,2_b+j=2_SimpleNtuplerDiEle", "b=0_b+j=2_SimpleNtupler","b=0_b+j=2_SimpleNtuplerDiEle", "b=1,2_b+j=2_SimpleNtupler" ,"dilep_mass_hist", "\\text{M}_{\\mathscr{l}^{+}\\mathscr{l}^{-}}~[\\text{GeV}]", "CR^{ee}_{1,2b j=2} #bullet CR^{#mu#mu}_{2j}/CR^{ee}_{2j}")
    makeRatioPlots("b=1_j=0_SimpleNtuplerDiEle", "b=0_j=1_SimpleNtupler","b=0_j=1_SimpleNtuplerDiEle", "b=1_j=0_SimpleNtupler" ,"dilep_mass_hist", "\\text{M}_{\\mathscr{l}^{+}\\mathscr{l}^{-}}~[\\text{GeV}]", "CR^{ee}_{1b j=1} #bullet CR^{#mu#mu}_{1j}/CR^{ee}_{1j}")
#
    #makeRatioPlots("b=1,2_b+j=2_SimpleNtuplerDiEle", "b=0_b+j=2_SimpleNtupler","b=0_b+j=2_SimpleNtuplerDiEle", "b=1,2_b+j=2_SimpleNtupler" ,"dilep_mass_hist_before_cut", "\\text{M}_{\\mathscr{l}^{+}\\mathscr{l}^{-}}~[\\text{GeV}]", "CR^{ee}_{1,2b j=2} #bullet CR^{#mu#mu}_{2j}/CR^{ee}_{2j}")
    #makeRatioPlots("b=1_jl=0_SimpleNtuplerDiEle", "b=0_j=1_SimpleNtupler","b=0_j=1_SimpleNtuplerDiEle", "b=1_j=0_SimpleNtupler" ,"dilep_mass_hist_z_cut", "\\text{M}_{\\mathscr{l}^{+}\\mathscr{l}^{-}}~[\\text{GeV}]", "CR^{ee}_{1b j=1} #bullet CR^{#mu#mu}_{1j}/CR^{ee}_{1j}")
    #makeRatioPlots("b=1,2_b+j=2_SimpleNtuplerDiEle", "b=0_b+j=2_SimpleNtupler","b=0_b+j=2_SimpleNtuplerDiEle", "b=1,2_b+j=2_SimpleNtupler" ,"dilep_mass_hist_z_cut", "\\text{M}_{\\mathscr{l}^{+}\\mathscr{l}^{-}}~[\\text{GeV}]", "CR^{ee}_{1b j=1} #bullet CR^{#mu#mu}_{1j}/CR^{ee}_{1j}")
    #makeRatioPlots("b=1_j=0_SimpleNtuplerDiEle", "b=0_j=1_SimpleNtupler","b=0_j=1_SimpleNtuplerDiEle", "b=1_j=0_SimpleNtupler" ,"dilep_mass_hist_before_cut", "\\text{M}_{\\mathscr{l}^{+}\\mathscr{l}^{-}}~[\\text{GeV}]", "CR^{ee}_{1,2b j=2} #bullet CR^{#mu#mu}_{2j}/CR^{ee}_{2j}")
#makeNbJetNJet("b=1,2_b+j=2_SimpleNtupler","njvsnbj_hist")
#
#makeNbJetNJet("b=1_j=0_SimpleNtupler","leading_lep_pt_second_lep_pt")
#makeNbJetNJet("b=1,2_b+j=2_SimpleNtupler","leading_lep_pt_second_lep_pt")
#makeNbJetNJet("b=0_b+j=2_SimpleNtupler","leading_lep_pt_second_lep_pt")
#makeNbJetNJet("b=0_j=1_SimpleNtupler","leading_lep_pt_second_lep_pt")


postfix = "_2016"
#cutStrings = []
for cut in cutStrings:

    gSystem.Load("makeStackRatioPlotEEvMM_C")

    #makeStackRatioPlotEEvMM(cut, postfix, "jeteta_noB_hist", "jeteta_noB_hist", cut)

    #makeStackRatioPlotEEvMM(cut, postfix, "jet1eta_n_hist", "jet1eta_n_hist", cut)

    #makeStackRatioPlotEEvMM(cut, postfix, "jet1NonB_atleast2_eta_n_hist", "jet1NonB_atleast2_eta_n_hist", cut)
    #makeStackRatioPlotEEvMM(cut, postfix, "jet1B_atleast2_eta_n_hist", "jet1B_atleast2_eta_n_hist", cut)

    print "asdfsdfadsfasdfas", treeName
    for tree in treeName:
        #if (cut == "b=1_j=0" or cut == "b=1,2_b+j=2") and tree == "SimpleNtupler" and blinded:
        #    continue
        makePlots("{0}_{1}".format(cut,tree),postfix)

