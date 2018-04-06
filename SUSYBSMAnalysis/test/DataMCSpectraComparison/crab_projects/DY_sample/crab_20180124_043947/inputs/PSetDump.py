import FWCore.ParameterSet.Config as cms

process = cms.Process("Zprime2muAnalysis")

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring('/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext2-v1/MINIAODSIM')
)
process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

process.mvaEleID_PHYS14_PU20bx25_nonTrig_V1_producer_config = cms.PSet(
    mvaName = cms.string('ElectronMVAEstimatorRun2Phys14NonTrig'),
    mvaTag = cms.string('25nsV1'),
    weightFileNames = cms.vstring('RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EB1_5_oldscenario2phys14_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EB2_5_oldscenario2phys14_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EE_5_oldscenario2phys14_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EB1_10_oldscenario2phys14_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EB2_10_oldscenario2phys14_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EE_10_oldscenario2phys14_BDT.weights.xml')
)

process.mvaEleID_PHYS14_PU20bx25_nonTrig_V1_wp80 = cms.PSet(
    cutFlow = cms.VPSet(cms.PSet(
        cutName = cms.string('GsfEleMVACut'),
        isIgnored = cms.bool(False),
        mvaCategoriesMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Phys14NonTrig25nsV1Categories"),
        mvaCuts = cms.vdouble(-0.253, 0.081, -0.081, 0.965, 0.917, 
            0.683),
        mvaValueMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Phys14NonTrig25nsV1Values"),
        needsAdditionalProducts = cms.bool(True)
    )),
    idName = cms.string('mvaEleID-PHYS14-PU20bx25-nonTrig-V1-wp80'),
    isPOGApproved = cms.untracked.bool(False)
)

process.mvaEleID_PHYS14_PU20bx25_nonTrig_V1_wp90 = cms.PSet(
    cutFlow = cms.VPSet(cms.PSet(
        cutName = cms.string('GsfEleMVACut'),
        isIgnored = cms.bool(False),
        mvaCategoriesMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Phys14NonTrig25nsV1Categories"),
        mvaCuts = cms.vdouble(-0.483, -0.267, -0.323, 0.933, 0.825, 
            0.337),
        mvaValueMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Phys14NonTrig25nsV1Values"),
        needsAdditionalProducts = cms.bool(True)
    )),
    idName = cms.string('mvaEleID-PHYS14-PU20bx25-nonTrig-V1-wp90'),
    isPOGApproved = cms.untracked.bool(False)
)

process.mvaEleID_Spring15_25ns_Trig_V1_producer_config = cms.PSet(
    beamSpot = cms.InputTag("offlineBeamSpot"),
    conversionsAOD = cms.InputTag("allConversions"),
    conversionsMiniAOD = cms.InputTag("reducedEgamma","reducedConversions"),
    mvaName = cms.string('ElectronMVAEstimatorRun2Spring15Trig'),
    mvaTag = cms.string('25nsV1'),
    weightFileNames = cms.vstring('RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB1_10_oldTrigSpring15_25ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB2_10_oldTrigSpring15_25ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EE_10_oldTrigSpring15_25ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml')
)

process.mvaEleID_Spring15_25ns_Trig_V1_wp80 = cms.PSet(
    cutFlow = cms.VPSet(cms.PSet(
        cutName = cms.string('GsfEleMVACut'),
        isIgnored = cms.bool(False),
        mvaCategoriesMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring15Trig25nsV1Categories"),
        mvaCuts = cms.vdouble(0.988153, 0.96791, 0.841729),
        mvaValueMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring15Trig25nsV1Values"),
        needsAdditionalProducts = cms.bool(True)
    )),
    idName = cms.string('mvaEleID-Spring15-25ns-Trig-V1-wp80'),
    isPOGApproved = cms.untracked.bool(True)
)

process.mvaEleID_Spring15_25ns_Trig_V1_wp90 = cms.PSet(
    cutFlow = cms.VPSet(cms.PSet(
        cutName = cms.string('GsfEleMVACut'),
        isIgnored = cms.bool(False),
        mvaCategoriesMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring15Trig25nsV1Categories"),
        mvaCuts = cms.vdouble(0.972153, 0.922126, 0.610764),
        mvaValueMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring15Trig25nsV1Values"),
        needsAdditionalProducts = cms.bool(True)
    )),
    idName = cms.string('mvaEleID-Spring15-25ns-Trig-V1-wp90'),
    isPOGApproved = cms.untracked.bool(True)
)

process.mvaEleID_Spring15_25ns_nonTrig_V1_producer_config = cms.PSet(
    beamSpot = cms.InputTag("offlineBeamSpot"),
    conversionsAOD = cms.InputTag("allConversions"),
    conversionsMiniAOD = cms.InputTag("reducedEgamma","reducedConversions"),
    mvaName = cms.string('ElectronMVAEstimatorRun2Spring15NonTrig'),
    mvaTag = cms.string('25nsV1'),
    weightFileNames = cms.vstring('RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB1_5_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB2_5_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EE_5_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB1_10_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB2_10_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EE_10_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml')
)

process.mvaEleID_Spring15_25ns_nonTrig_V1_wp80 = cms.PSet(
    cutFlow = cms.VPSet(cms.PSet(
        cutName = cms.string('GsfEleMVACut'),
        isIgnored = cms.bool(False),
        mvaCategoriesMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring15NonTrig25nsV1Categories"),
        mvaCuts = cms.vdouble(0.287435, 0.221846, -0.303263, 0.967083, 0.929117, 
            0.726311),
        mvaValueMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring15NonTrig25nsV1Values"),
        needsAdditionalProducts = cms.bool(True)
    )),
    idName = cms.string('mvaEleID-Spring15-25ns-nonTrig-V1-wp80'),
    isPOGApproved = cms.untracked.bool(True)
)

process.mvaEleID_Spring15_25ns_nonTrig_V1_wp90 = cms.PSet(
    cutFlow = cms.VPSet(cms.PSet(
        cutName = cms.string('GsfEleMVACut'),
        isIgnored = cms.bool(False),
        mvaCategoriesMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring15NonTrig25nsV1Categories"),
        mvaCuts = cms.vdouble(-0.083313, -0.235222, -0.67099, 0.913286, 0.805013, 
            0.358969),
        mvaValueMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring15NonTrig25nsV1Values"),
        needsAdditionalProducts = cms.bool(True)
    )),
    idName = cms.string('mvaEleID-Spring15-25ns-nonTrig-V1-wp90'),
    isPOGApproved = cms.untracked.bool(True)
)

process.mvaEleID_Spring15_25ns_nonTrig_V1_wpLoose = cms.PSet(
    cutFlow = cms.VPSet(cms.PSet(
        cutName = cms.string('GsfEleMVACut'),
        isIgnored = cms.bool(False),
        mvaCategoriesMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring15NonTrig25nsV1Categories"),
        mvaCuts = cms.vdouble(-0.265, -0.556, -0.551, -0.072, -0.286, 
            -0.267),
        mvaValueMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring15NonTrig25nsV1Values"),
        needsAdditionalProducts = cms.bool(True)
    )),
    idName = cms.string('mvaEleID-Spring15-25ns-nonTrig-V1-wpLoose'),
    isPOGApproved = cms.untracked.bool(True)
)

process.mvaEleID_Spring15_50ns_Trig_V1_producer_config = cms.PSet(
    beamSpot = cms.InputTag("offlineBeamSpot"),
    conversionsAOD = cms.InputTag("allConversions"),
    conversionsMiniAOD = cms.InputTag("reducedEgamma","reducedConversions"),
    mvaName = cms.string('ElectronMVAEstimatorRun2Spring15Trig'),
    mvaTag = cms.string('50nsV1'),
    weightFileNames = cms.vstring('RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB1_10_oldTrigSpring15_50ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB2_10_oldTrigSpring15_50ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EE_10_oldTrigSpring15_50ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml')
)

process.mvaEleID_Spring15_50ns_Trig_V1_wp80 = cms.PSet(
    cutFlow = cms.VPSet(cms.PSet(
        cutName = cms.string('GsfEleMVACut'),
        isIgnored = cms.bool(False),
        mvaCategoriesMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring15Trig50nsV1Categories"),
        mvaCuts = cms.vdouble(0.981841, 0.946762, 0.79704),
        mvaValueMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring15Trig50nsV1Values"),
        needsAdditionalProducts = cms.bool(True)
    )),
    idName = cms.string('mvaEleID-Spring15-50ns-Trig-V1-wp80'),
    isPOGApproved = cms.untracked.bool(True)
)

process.mvaEleID_Spring15_50ns_Trig_V1_wp90 = cms.PSet(
    cutFlow = cms.VPSet(cms.PSet(
        cutName = cms.string('GsfEleMVACut'),
        isIgnored = cms.bool(False),
        mvaCategoriesMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring15Trig50nsV1Categories"),
        mvaCuts = cms.vdouble(0.953843, 0.849994, 0.514118),
        mvaValueMapName = cms.InputTag("electronMVAValueMapProducer","ElectronMVAEstimatorRun2Spring15Trig50nsV1Values"),
        needsAdditionalProducts = cms.bool(True)
    )),
    idName = cms.string('mvaEleID-Spring15-50ns-Trig-V1-wp90'),
    isPOGApproved = cms.untracked.bool(True)
)

process.options = cms.untracked.PSet(
    wantSummary = cms.untracked.bool(False)
)

process.mvaConfigsForEleProducer = cms.VPSet(cms.PSet(
    mvaName = cms.string('ElectronMVAEstimatorRun2Phys14NonTrig'),
    mvaTag = cms.string('25nsV1'),
    weightFileNames = cms.vstring('RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EB1_5_oldscenario2phys14_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EB2_5_oldscenario2phys14_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EE_5_oldscenario2phys14_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EB1_10_oldscenario2phys14_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EB2_10_oldscenario2phys14_BDT.weights.xml', 
        'RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EE_10_oldscenario2phys14_BDT.weights.xml')
), 
    cms.PSet(
        beamSpot = cms.InputTag("offlineBeamSpot"),
        conversionsAOD = cms.InputTag("allConversions"),
        conversionsMiniAOD = cms.InputTag("reducedEgamma","reducedConversions"),
        mvaName = cms.string('ElectronMVAEstimatorRun2Spring15NonTrig'),
        mvaTag = cms.string('25nsV1'),
        weightFileNames = cms.vstring('RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB1_5_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml', 
            'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB2_5_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml', 
            'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EE_5_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml', 
            'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB1_10_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml', 
            'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB2_10_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml', 
            'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EE_10_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml')
    ), 
    cms.PSet(
        beamSpot = cms.InputTag("offlineBeamSpot"),
        conversionsAOD = cms.InputTag("allConversions"),
        conversionsMiniAOD = cms.InputTag("reducedEgamma","reducedConversions"),
        mvaName = cms.string('ElectronMVAEstimatorRun2Spring15Trig'),
        mvaTag = cms.string('50nsV1'),
        weightFileNames = cms.vstring('RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB1_10_oldTrigSpring15_50ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml', 
            'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB2_10_oldTrigSpring15_50ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml', 
            'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EE_10_oldTrigSpring15_50ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml')
    ), 
    cms.PSet(
        beamSpot = cms.InputTag("offlineBeamSpot"),
        conversionsAOD = cms.InputTag("allConversions"),
        conversionsMiniAOD = cms.InputTag("reducedEgamma","reducedConversions"),
        mvaName = cms.string('ElectronMVAEstimatorRun2Spring15Trig'),
        mvaTag = cms.string('25nsV1'),
        weightFileNames = cms.vstring('RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB1_10_oldTrigSpring15_25ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml', 
            'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB2_10_oldTrigSpring15_25ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml', 
            'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EE_10_oldTrigSpring15_25ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml')
    ))

process.Our2016Leptons = cms.EDProducer("Zprime2muLeptonProducer_miniAOD",
    bits = cms.InputTag("TriggerResults","","HLT"),
    electron_id = cms.InputTag("egmGsfElectronIDs","heepElectronID-HEEPV60"),
    electron_muon_veto_dR = cms.double(-1),
    electron_src = cms.InputTag("slimmedElectrons"),
    muon_cuts = cms.string('isGlobalMuon && isTrackerMuon && pt > 53 && abs(eta) < 2.4 && abs(dB) < 0.2 && isolationR03.sumPt / innerTrack.pt < 0.10 && globalTrack.hitPattern.trackerLayersWithMeasurement > 5 && globalTrack.hitPattern.numberOfValidPixelHits > 0 && globalTrack.hitPattern.numberOfValidMuonHits > 0 && numberOfMatchedStations > 1'),
    muon_photon_match_src = cms.InputTag("muonPhotonMatchMiniAOD"),
    muon_src = cms.InputTag("slimmedMuons"),
    muon_srcSecond = cms.InputTag("slimmedMuons"),
    muon_track_for_momentum = cms.string('TunePNew'),
    muon_track_for_momentum_CSC = cms.string('Inner'),
    prescales = cms.InputTag("patTrigger"),
    trigger_match_max_dR = cms.double(0.2),
    trigger_summary = cms.InputTag("selectedPatTrigger")
)


process.Our2016MuonsAllSigns = cms.EDProducer("Zprime2muCompositeCandidatePicker",
    back_to_back_cos_angle_min = cms.double(-0.9998),
    cut = cms.string(''),
    do_remove_overlap = cms.bool(True),
    dpt_over_pt_max = cms.double(0.3),
    max_candidates = cms.uint32(1),
    sort_by_pt = cms.bool(True),
    src = cms.InputTag("allOur2016MuonsAllSigns"),
    vertex_chi2_max = cms.double(20)
)


process.Our2016MuonsMinusMuonsMinus = cms.EDProducer("Zprime2muCompositeCandidatePicker",
    back_to_back_cos_angle_min = cms.double(-0.9998),
    cut = cms.string(''),
    do_remove_overlap = cms.bool(True),
    dpt_over_pt_max = cms.double(0.3),
    max_candidates = cms.uint32(1),
    sort_by_pt = cms.bool(True),
    src = cms.InputTag("allOur2016MuonsMinusMuonsMinus"),
    vertex_chi2_max = cms.double(20)
)


process.Our2016MuonsPlusMuonsMinus = cms.EDProducer("Zprime2muCompositeCandidatePicker",
    back_to_back_cos_angle_min = cms.double(-0.9998),
    cut = cms.string(''),
    do_remove_overlap = cms.bool(True),
    dpt_over_pt_max = cms.double(0.3),
    max_candidates = cms.uint32(1),
    sort_by_pt = cms.bool(True),
    src = cms.InputTag("allOur2016MuonsPlusMuonsMinus"),
    vertex_chi2_max = cms.double(20)
)


process.Our2016MuonsPlusMuonsPlus = cms.EDProducer("Zprime2muCompositeCandidatePicker",
    back_to_back_cos_angle_min = cms.double(-0.9998),
    cut = cms.string(''),
    do_remove_overlap = cms.bool(True),
    dpt_over_pt_max = cms.double(0.3),
    max_candidates = cms.uint32(1),
    sort_by_pt = cms.bool(True),
    src = cms.InputTag("allOur2016MuonsPlusMuonsPlus"),
    vertex_chi2_max = cms.double(20)
)


process.Our2016MuonsSameSign = cms.EDProducer("Zprime2muCompositeCandidatePicker",
    back_to_back_cos_angle_min = cms.double(-0.9998),
    cut = cms.string(''),
    do_remove_overlap = cms.bool(True),
    dpt_over_pt_max = cms.double(0.3),
    max_candidates = cms.uint32(1),
    sort_by_pt = cms.bool(True),
    src = cms.InputTag("allOur2016MuonsSameSign"),
    vertex_chi2_max = cms.double(20)
)


process.SimpleLeptons = cms.EDProducer("Zprime2muLeptonProducer_miniAOD",
    bits = cms.InputTag("TriggerResults","","HLT"),
    electron_id = cms.InputTag("egmGsfElectronIDs","heepElectronID-HEEPV60"),
    electron_muon_veto_dR = cms.double(-1),
    electron_src = cms.InputTag("slimmedElectrons"),
    muon_cuts = cms.string(''),
    muon_photon_match_src = cms.InputTag("muonPhotonMatchMiniAOD"),
    muon_src = cms.InputTag("slimmedMuons"),
    muon_srcSecond = cms.InputTag("slimmedMuons"),
    muon_track_for_momentum = cms.string('TunePNew'),
    muon_track_for_momentum_CSC = cms.string('Inner'),
    prescales = cms.InputTag("patTrigger"),
    trigger_match_max_dR = cms.double(0.2),
    trigger_summary = cms.InputTag("selectedPatTrigger")
)


process.SimpleMuonsAllSigns = cms.EDProducer("Zprime2muCompositeCandidatePicker",
    cut = cms.string(''),
    do_remove_overlap = cms.bool(False),
    max_candidates = cms.uint32(100),
    sort_by_pt = cms.bool(True),
    src = cms.InputTag("allSimpleMuonsAllSigns")
)


process.SimpleMuonsMinusMuonsMinus = cms.EDProducer("Zprime2muCompositeCandidatePicker",
    cut = cms.string(''),
    do_remove_overlap = cms.bool(False),
    max_candidates = cms.uint32(100),
    sort_by_pt = cms.bool(True),
    src = cms.InputTag("allSimpleMuonsMinusMuonsMinus")
)


process.SimpleMuonsPlusMuonsMinus = cms.EDProducer("Zprime2muCompositeCandidatePicker",
    cut = cms.string(''),
    do_remove_overlap = cms.bool(False),
    max_candidates = cms.uint32(100),
    sort_by_pt = cms.bool(True),
    src = cms.InputTag("allSimpleMuonsPlusMuonsMinus")
)


process.SimpleMuonsPlusMuonsPlus = cms.EDProducer("Zprime2muCompositeCandidatePicker",
    cut = cms.string(''),
    do_remove_overlap = cms.bool(False),
    max_candidates = cms.uint32(100),
    sort_by_pt = cms.bool(True),
    src = cms.InputTag("allSimpleMuonsPlusMuonsPlus")
)


process.SimpleMuonsSameSign = cms.EDProducer("Zprime2muCompositeCandidatePicker",
    cut = cms.string(''),
    do_remove_overlap = cms.bool(False),
    max_candidates = cms.uint32(100),
    sort_by_pt = cms.bool(True),
    src = cms.InputTag("allSimpleMuonsSameSign")
)


process.allDimuons = cms.EDProducer("Zprime2muCombiner",
    cut = cms.string(''),
    decay = cms.string('leptons:muons@+ leptons:muons@-'),
    loose_cut = cms.string('isGlobalMuon && isTrackerMuon && pt > 53 && abs(eta) < 2.4 && abs(dB) < 0.2 && isolationR03.sumPt / innerTrack.pt < 0.10 && globalTrack.hitPattern.trackerLayersWithMeasurement > 5 && globalTrack.hitPattern.numberOfValidPixelHits > 0 && globalTrack.hitPattern.numberOfValidMuonHits > 0 && numberOfMatchedStations > 1'),
    tight_cut = cms.string('userFloat("TriggerMatchPt") > 50 ')
)


process.allOur2016MuonsAllSigns = cms.EDProducer("Zprime2muCombiner",
    checkCharge = cms.bool(False),
    cut = cms.string(''),
    decay = cms.string('Our2016Leptons:muons@- Our2016Leptons:muons@-'),
    loose_cut = cms.string('isGlobalMuon && isTrackerMuon && pt > 53 && abs(eta) < 2.4 && abs(dB) < 0.2 && isolationR03.sumPt / innerTrack.pt < 0.10 && globalTrack.hitPattern.trackerLayersWithMeasurement > 5 && globalTrack.hitPattern.numberOfValidPixelHits > 0 && globalTrack.hitPattern.numberOfValidMuonHits > 0 && numberOfMatchedStations > 1'),
    tight_cut = cms.string('userFloat("TriggerMatchPt") > 50 ')
)


process.allOur2016MuonsMinusMuonsMinus = cms.EDProducer("Zprime2muCombiner",
    cut = cms.string('daughter(0).pdgId() + daughter(1).pdgId() == 26'),
    decay = cms.string('Our2016Leptons:muons@- Our2016Leptons:muons@-'),
    loose_cut = cms.string('isGlobalMuon && isTrackerMuon && pt > 53 && abs(eta) < 2.4 && abs(dB) < 0.2 && isolationR03.sumPt / innerTrack.pt < 0.10 && globalTrack.hitPattern.trackerLayersWithMeasurement > 5 && globalTrack.hitPattern.numberOfValidPixelHits > 0 && globalTrack.hitPattern.numberOfValidMuonHits > 0 && numberOfMatchedStations > 1'),
    tight_cut = cms.string('userFloat("TriggerMatchPt") > 50 ')
)


process.allOur2016MuonsPlusMuonsMinus = cms.EDProducer("Zprime2muCombiner",
    cut = cms.string('daughter(0).pdgId() + daughter(1).pdgId() == 0'),
    decay = cms.string('Our2016Leptons:muons@+ Our2016Leptons:muons@-'),
    loose_cut = cms.string('isGlobalMuon && isTrackerMuon && pt > 53 && abs(eta) < 2.4 && abs(dB) < 0.2 && isolationR03.sumPt / innerTrack.pt < 0.10 && globalTrack.hitPattern.trackerLayersWithMeasurement > 5 && globalTrack.hitPattern.numberOfValidPixelHits > 0 && globalTrack.hitPattern.numberOfValidMuonHits > 0 && numberOfMatchedStations > 1'),
    tight_cut = cms.string('userFloat("TriggerMatchPt") > 50 ')
)


process.allOur2016MuonsPlusMuonsPlus = cms.EDProducer("Zprime2muCombiner",
    cut = cms.string('daughter(0).pdgId() + daughter(1).pdgId() == -26'),
    decay = cms.string('Our2016Leptons:muons@+ Our2016Leptons:muons@+'),
    loose_cut = cms.string('isGlobalMuon && isTrackerMuon && pt > 53 && abs(eta) < 2.4 && abs(dB) < 0.2 && isolationR03.sumPt / innerTrack.pt < 0.10 && globalTrack.hitPattern.trackerLayersWithMeasurement > 5 && globalTrack.hitPattern.numberOfValidPixelHits > 0 && globalTrack.hitPattern.numberOfValidMuonHits > 0 && numberOfMatchedStations > 1'),
    tight_cut = cms.string('userFloat("TriggerMatchPt") > 50 ')
)


process.allOur2016MuonsSameSign = cms.EDProducer("Zprime2muCombiner",
    cut = cms.string(''),
    decay = cms.string('Our2016Leptons:muons@- Our2016Leptons:muons@-'),
    loose_cut = cms.string('isGlobalMuon && isTrackerMuon && pt > 53 && abs(eta) < 2.4 && abs(dB) < 0.2 && isolationR03.sumPt / innerTrack.pt < 0.10 && globalTrack.hitPattern.trackerLayersWithMeasurement > 5 && globalTrack.hitPattern.numberOfValidPixelHits > 0 && globalTrack.hitPattern.numberOfValidMuonHits > 0 && numberOfMatchedStations > 1'),
    tight_cut = cms.string('userFloat("TriggerMatchPt") > 50 ')
)


process.allSimpleMuonsAllSigns = cms.EDProducer("Zprime2muCombiner",
    checkCharge = cms.bool(False),
    cut = cms.string(''),
    decay = cms.string('SimpleLeptons:muons@- SimpleLeptons:muons@-'),
    electron_cut_mask = cms.uint32(0),
    loose_cut = cms.string('isGlobalMuon && pt > 20.'),
    tight_cut = cms.string('')
)


process.allSimpleMuonsMinusMuonsMinus = cms.EDProducer("Zprime2muCombiner",
    cut = cms.string('daughter(0).pdgId() + daughter(1).pdgId() == 26'),
    decay = cms.string('SimpleLeptons:muons@- SimpleLeptons:muons@-'),
    electron_cut_mask = cms.uint32(0),
    loose_cut = cms.string('isGlobalMuon && pt > 20.'),
    tight_cut = cms.string('')
)


process.allSimpleMuonsPlusMuonsMinus = cms.EDProducer("Zprime2muCombiner",
    cut = cms.string('daughter(0).pdgId() + daughter(1).pdgId() == 0'),
    decay = cms.string('SimpleLeptons:muons@+ SimpleLeptons:muons@-'),
    electron_cut_mask = cms.uint32(0),
    loose_cut = cms.string('isGlobalMuon && pt > 20.'),
    tight_cut = cms.string('')
)


process.allSimpleMuonsPlusMuonsPlus = cms.EDProducer("Zprime2muCombiner",
    cut = cms.string('daughter(0).pdgId() + daughter(1).pdgId() == -26'),
    decay = cms.string('SimpleLeptons:muons@+ SimpleLeptons:muons@+'),
    electron_cut_mask = cms.uint32(0),
    loose_cut = cms.string('isGlobalMuon && pt > 20.'),
    tight_cut = cms.string('')
)


process.allSimpleMuonsSameSign = cms.EDProducer("Zprime2muCombiner",
    cut = cms.string(''),
    decay = cms.string('SimpleLeptons:muons@- SimpleLeptons:muons@-'),
    electron_cut_mask = cms.uint32(0),
    loose_cut = cms.string('isGlobalMuon && pt > 20.'),
    tight_cut = cms.string('')
)


process.dimuons = cms.EDProducer("Zprime2muCompositeCandidatePicker",
    back_to_back_cos_angle_min = cms.double(-0.9998),
    cut = cms.string(''),
    do_remove_overlap = cms.bool(True),
    dpt_over_pt_max = cms.double(0.3),
    max_candidates = cms.uint32(1),
    sort_by_pt = cms.bool(True),
    src = cms.InputTag("allDimuons"),
    vertex_chi2_max = cms.double(20)
)


process.egmGsfElectronIDs = cms.EDProducer("VersionedGsfElectronIdProducer",
    physicsObjectIDs = cms.VPSet(cms.PSet(
        idDefinition = cms.PSet(
            cutFlow = cms.VPSet(cms.PSet(
                cutName = cms.string('MinPtCut'),
                isIgnored = cms.bool(False),
                minPt = cms.double(35.0),
                needsAdditionalProducts = cms.bool(False)
            ), 
                cms.PSet(
                    allowedEtaRanges = cms.VPSet(cms.PSet(
                        maxEta = cms.double(1.4442),
                        minEta = cms.double(0.0)
                    ), 
                        cms.PSet(
                            maxEta = cms.double(2.5),
                            minEta = cms.double(1.566)
                        )),
                    cutName = cms.string('GsfEleSCEtaMultiRangeCut'),
                    isIgnored = cms.bool(False),
                    needsAdditionalProducts = cms.bool(False),
                    useAbsEta = cms.bool(True)
                ), 
                cms.PSet(
                    barrelCutOff = cms.double(1.479),
                    cutName = cms.string('GsfEleDEtaInSeedCut'),
                    dEtaInSeedCutValueEB = cms.double(0.004),
                    dEtaInSeedCutValueEE = cms.double(0.006),
                    isIgnored = cms.bool(False),
                    needsAdditionalProducts = cms.bool(False)
                ), 
                cms.PSet(
                    barrelCutOff = cms.double(1.479),
                    cutName = cms.string('GsfEleDPhiInCut'),
                    dPhiInCutValueEB = cms.double(0.06),
                    dPhiInCutValueEE = cms.double(0.06),
                    isIgnored = cms.bool(False),
                    needsAdditionalProducts = cms.bool(False)
                ), 
                cms.PSet(
                    barrelCutOff = cms.double(1.479),
                    cutName = cms.string('GsfEleFull5x5SigmaIEtaIEtaCut'),
                    full5x5SigmaIEtaIEtaCutValueEB = cms.double(9999),
                    full5x5SigmaIEtaIEtaCutValueEE = cms.double(0.03),
                    isIgnored = cms.bool(False),
                    needsAdditionalProducts = cms.bool(False)
                ), 
                cms.PSet(
                    cutName = cms.string('GsfEleFull5x5E2x5OverE5x5Cut'),
                    isIgnored = cms.bool(False),
                    minE1x5OverE5x5EB = cms.double(0.83),
                    minE1x5OverE5x5EE = cms.double(-1.0),
                    minE2x5OverE5x5EB = cms.double(0.94),
                    minE2x5OverE5x5EE = cms.double(-1.0),
                    needsAdditionalProducts = cms.bool(False)
                ), 
                cms.PSet(
                    constTermEB = cms.double(1.0),
                    constTermEE = cms.double(5),
                    cutName = cms.string('GsfEleHadronicOverEMLinearCut'),
                    isIgnored = cms.bool(False),
                    needsAdditionalProducts = cms.bool(False),
                    slopeStartEB = cms.double(0.0),
                    slopeStartEE = cms.double(0.0),
                    slopeTermEB = cms.double(0.05),
                    slopeTermEE = cms.double(0.05)
                ), 
                cms.PSet(
                    constTermEB = cms.double(5.0),
                    constTermEE = cms.double(5.0),
                    cutName = cms.string('GsfEleTrkPtIsoCut'),
                    isIgnored = cms.bool(False),
                    needsAdditionalProducts = cms.bool(False),
                    slopeStartEB = cms.double(0.0),
                    slopeStartEE = cms.double(0.0),
                    slopeTermEB = cms.double(0.0),
                    slopeTermEE = cms.double(0.0)
                ), 
                cms.PSet(
                    constTermEB = cms.double(2.0),
                    constTermEE = cms.double(2.5),
                    cutName = cms.string('GsfEleEmHadD1IsoRhoCut'),
                    isIgnored = cms.bool(False),
                    needsAdditionalProducts = cms.bool(True),
                    rho = cms.InputTag("fixedGridRhoFastjetAll"),
                    rhoConstant = cms.double(0.28),
                    slopeStartEB = cms.double(0.0),
                    slopeStartEE = cms.double(50.0),
                    slopeTermEB = cms.double(0.03),
                    slopeTermEE = cms.double(0.03)
                ), 
                cms.PSet(
                    barrelCutOff = cms.double(1.479),
                    cutName = cms.string('GsfEleDxyCut'),
                    dxyCutValueEB = cms.double(0.02),
                    dxyCutValueEE = cms.double(0.05),
                    isIgnored = cms.bool(False),
                    needsAdditionalProducts = cms.bool(True),
                    vertexSrc = cms.InputTag("offlinePrimaryVertices"),
                    vertexSrcMiniAOD = cms.InputTag("offlineSlimmedPrimaryVertices")
                ), 
                cms.PSet(
                    barrelCutOff = cms.double(1.479),
                    cutName = cms.string('GsfEleMissingHitsCut'),
                    isIgnored = cms.bool(False),
                    maxMissingHitsEB = cms.uint32(1),
                    maxMissingHitsEE = cms.uint32(1),
                    needsAdditionalProducts = cms.bool(False)
                ), 
                cms.PSet(
                    barrelCutOff = cms.double(1.479),
                    cutName = cms.string('GsfEleEcalDrivenCut'),
                    ecalDrivenEB = cms.int32(1),
                    ecalDrivenEE = cms.int32(1),
                    isIgnored = cms.bool(False),
                    needsAdditionalProducts = cms.bool(False)
                )),
            idName = cms.string('heepElectronID-HEEPV60')
        ),
        idMD5 = cms.string('df10ac7e3a9c22f63fa7936573beaafb'),
        isPOGApproved = cms.untracked.bool(True)
    )),
    physicsObjectSrc = cms.InputTag("slimmedElectrons")
)


process.electronMVAValueMapProducer = cms.EDProducer("ElectronMVAValueMapProducer",
    mvaConfigurations = cms.VPSet(cms.PSet(
        mvaName = cms.string('ElectronMVAEstimatorRun2Phys14NonTrig'),
        mvaTag = cms.string('25nsV1'),
        weightFileNames = cms.vstring('RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EB1_5_oldscenario2phys14_BDT.weights.xml', 
            'RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EB2_5_oldscenario2phys14_BDT.weights.xml', 
            'RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EE_5_oldscenario2phys14_BDT.weights.xml', 
            'RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EB1_10_oldscenario2phys14_BDT.weights.xml', 
            'RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EB2_10_oldscenario2phys14_BDT.weights.xml', 
            'RecoEgamma/ElectronIdentification/data/PHYS14/EIDmva_EE_10_oldscenario2phys14_BDT.weights.xml')
    ), 
        cms.PSet(
            beamSpot = cms.InputTag("offlineBeamSpot"),
            conversionsAOD = cms.InputTag("allConversions"),
            conversionsMiniAOD = cms.InputTag("reducedEgamma","reducedConversions"),
            mvaName = cms.string('ElectronMVAEstimatorRun2Spring15NonTrig'),
            mvaTag = cms.string('25nsV1'),
            weightFileNames = cms.vstring('RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB1_5_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml', 
                'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB2_5_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml', 
                'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EE_5_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml', 
                'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB1_10_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml', 
                'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB2_10_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml', 
                'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EE_10_oldNonTrigSpring15_ConvVarCwoBoolean_TMVA412_FullStatLowPt_PairNegWeightsGlobal_BDT.weights.xml')
        ), 
        cms.PSet(
            beamSpot = cms.InputTag("offlineBeamSpot"),
            conversionsAOD = cms.InputTag("allConversions"),
            conversionsMiniAOD = cms.InputTag("reducedEgamma","reducedConversions"),
            mvaName = cms.string('ElectronMVAEstimatorRun2Spring15Trig'),
            mvaTag = cms.string('50nsV1'),
            weightFileNames = cms.vstring('RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB1_10_oldTrigSpring15_50ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml', 
                'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB2_10_oldTrigSpring15_50ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml', 
                'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EE_10_oldTrigSpring15_50ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml')
        ), 
        cms.PSet(
            beamSpot = cms.InputTag("offlineBeamSpot"),
            conversionsAOD = cms.InputTag("allConversions"),
            conversionsMiniAOD = cms.InputTag("reducedEgamma","reducedConversions"),
            mvaName = cms.string('ElectronMVAEstimatorRun2Spring15Trig'),
            mvaTag = cms.string('25nsV1'),
            weightFileNames = cms.vstring('RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB1_10_oldTrigSpring15_25ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml', 
                'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EB2_10_oldTrigSpring15_25ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml', 
                'RecoEgamma/ElectronIdentification/data/Spring15/EIDmva_EE_10_oldTrigSpring15_25ns_data_1_VarD_TMVA412_Sig6BkgAll_MG_noSpec_BDT.weights.xml')
        )),
    src = cms.InputTag("gedGsfElectrons"),
    srcMiniAOD = cms.InputTag("slimmedElectrons","","@skipCurrentProcess")
)


process.electronRegressionValueMapProducer = cms.EDProducer("ElectronRegressionValueMapProducer",
    ebReducedRecHitCollection = cms.InputTag("reducedEcalRecHitsEB"),
    ebReducedRecHitCollectionMiniAOD = cms.InputTag("reducedEgamma","reducedEBRecHits"),
    eeReducedRecHitCollection = cms.InputTag("reducedEcalRecHitsEE"),
    eeReducedRecHitCollectionMiniAOD = cms.InputTag("reducedEgamma","reducedEERecHits"),
    esReducedRecHitCollection = cms.InputTag("reducedEcalRecHitsES"),
    esReducedRecHitCollectionMiniAOD = cms.InputTag("reducedEgamma","reducedESRecHits"),
    src = cms.InputTag("gedGsfElectrons"),
    srcMiniAOD = cms.InputTag("slimmedElectrons","","@skipCurrentProcess"),
    useFull5x5 = cms.bool(False)
)


process.leptons = cms.EDProducer("Zprime2muLeptonProducer",
    electron_cuts = cms.string(''),
    electron_muon_veto_dR = cms.double(-1),
    electron_src = cms.InputTag("cleanPatElectrons"),
    electron_srcSecond = cms.InputTag("cleanPatElectrons"),
    muon_cuts = cms.string('isGlobalMuon && isTrackerMuon && pt > 53 && abs(eta) < 2.4 && abs(dB) < 0.2 && isolationR03.sumPt / innerTrack.pt < 0.10 && globalTrack.hitPattern.trackerLayersWithMeasurement > 5 && globalTrack.hitPattern.numberOfValidPixelHits > 0 && globalTrack.hitPattern.numberOfValidMuonHits > 0 && numberOfMatchedStations > 1'),
    muon_photon_match_src = cms.InputTag("muonPhotonMatch"),
    muon_src = cms.InputTag("cleanPatMuonsTriggerMatch"),
    muon_srcSecond = cms.InputTag("cleanPatMuonsTriggerMatch"),
    muon_track_for_momentum = cms.string('TunePNew'),
    muon_track_for_momentum_CSC = cms.string('Inner'),
    trigger_match_max_dR = cms.double(0.2),
    trigger_summary_src = cms.InputTag("hltTriggerSummaryAOD","","HLT")
)


process.leptonsMini = cms.EDProducer("Zprime2muLeptonProducer_miniAOD",
    bits = cms.InputTag("TriggerResults","","HLT"),
    electron_id = cms.InputTag("egmGsfElectronIDs","heepElectronID-HEEPV60"),
    electron_muon_veto_dR = cms.double(-1),
    electron_src = cms.InputTag("slimmedElectrons"),
    muon_cuts = cms.string('isGlobalMuon && isTrackerMuon && pt > 53 && abs(eta) < 2.4 && abs(dB) < 0.2 && isolationR03.sumPt / innerTrack.pt < 0.10 && globalTrack.hitPattern.trackerLayersWithMeasurement > 5 && globalTrack.hitPattern.numberOfValidPixelHits > 0 && globalTrack.hitPattern.numberOfValidMuonHits > 0 && numberOfMatchedStations > 1'),
    muon_photon_match_src = cms.InputTag("muonPhotonMatchMiniAOD"),
    muon_src = cms.InputTag("slimmedMuons"),
    muon_srcSecond = cms.InputTag("slimmedMuons"),
    muon_track_for_momentum = cms.string('TunePNew'),
    muon_track_for_momentum_CSC = cms.string('Inner'),
    prescales = cms.InputTag("patTrigger"),
    trigger_match_max_dR = cms.double(0.2),
    trigger_summary = cms.InputTag("selectedPatTrigger")
)


process.muonPhotonMatch = cms.EDProducer("TrivialDeltaRViewMatcher",
    distMin = cms.double(0.1),
    matched = cms.InputTag("cleanPatPhotons"),
    src = cms.InputTag("cleanPatMuonsTriggerMatch")
)


process.muonPhotonMatchMiniAOD = cms.EDProducer("TrivialDeltaRViewMatcher",
    distMin = cms.double(0.1),
    matched = cms.InputTag("slimmedPhotons"),
    src = cms.InputTag("slimmedMuons")
)


process.prunedMCLeptons = cms.EDProducer("GenParticlePruner",
    select = cms.vstring('drop *', 
        'keep status == 3', 
        '++keep abs(pdgId) == 13 && (status == 1 || status == 8)', 
        '++keep abs(pdgId) == 11 && status == 1', 
        'keep++ pdgId == 23 || pdgId == 32 || pdgId == 39 || pdgId == 5000039'),
    src = cms.InputTag("prunedGenParticles")
)


process.PrescaleToCommon = cms.EDFilter("PrescaleToCommon",
    TriggerResults_src = cms.InputTag("TriggerResults","","HLT2"),
    assume_simulation_has_prescale_1 = cms.bool(True),
    hlt_src = cms.InputTag("TriggerResults","","HLT2"),
    overall_prescale = cms.int32(350),
    trigger_paths = cms.vstring('HLT_Mu27_v1', 
        'HLT_Mu27_v2', 
        'HLT_Mu27_v3', 
        'HLT_Mu27_v4')
)


process.PrescaleToCommonMiniAOD = cms.EDFilter("PrescaleToCommon_miniAOD",
    L1Prescale_max_src = cms.InputTag("patTrigger","l1max","RECO"),
    L1Prescale_min_src = cms.InputTag("patTrigger","l1min","RECO"),
    Prescale_src = cms.InputTag("patTrigger","","RECO"),
    TriggerResults_src = cms.InputTag("TriggerResults","","HLT2"),
    assume_simulation_has_prescale_1 = cms.bool(True),
    hlt_src = cms.InputTag("TriggerResults","","HLT2"),
    overall_prescale = cms.int32(350),
    trigger_paths = cms.vstring('HLT_Mu27_v1', 
        'HLT_Mu27_v2', 
        'HLT_Mu27_v3', 
        'HLT_Mu27_v4')
)


process.beamHaloMiniAOD = cms.EDFilter("METFilterMiniAOD",
    applyfilter = cms.untracked.bool(True),
    debugOn = cms.untracked.bool(False),
    flag = cms.string('Flag_globalTightHalo2016Filter'),
    src = cms.InputTag("TriggerResults","","PAT")
)


process.defaultSelector = cms.EDFilter("METFilterMiniAOD",
    applyfilter = cms.untracked.bool(True),
    debugOn = cms.untracked.bool(False),
    flag = cms.string('Flag_globalTightHalo2016Filter'),
    src = cms.InputTag("TriggerResults","","PAT")
)


process.dileptonPreseletor = cms.EDFilter("DileptonPreselector",
    muons = cms.InputTag("slimmedMuons"),
    nMuons = cms.double(2),
    ptCut = cms.double(40)
)


process.ecalDeadCellPrimitiveMiniAOD = cms.EDFilter("METFilterMiniAOD",
    applyfilter = cms.untracked.bool(True),
    debugOn = cms.untracked.bool(False),
    flag = cms.string('Flag_EcalDeadCellTriggerPrimitiveFilter'),
    src = cms.InputTag("TriggerResults","","PAT")
)


process.eeBadScMiniAOD = cms.EDFilter("METFilterMiniAOD",
    applyfilter = cms.untracked.bool(True),
    debugOn = cms.untracked.bool(False),
    flag = cms.string('Flag_eeBadScFilter'),
    src = cms.InputTag("TriggerResults","","PAT")
)


process.goodDataFilter = cms.EDFilter("HLTHighLevel",
    HLTPaths = cms.vstring('goodDataPrimaryVertexFilter'),
    TriggerResultsTag = cms.InputTag("TriggerResults","","PAT"),
    andOr = cms.bool(False),
    eventSetupPathsKey = cms.string(''),
    throw = cms.bool(True)
)


process.hbheIsoNoiseMiniAOD = cms.EDFilter("METFilterMiniAOD",
    applyfilter = cms.untracked.bool(True),
    debugOn = cms.untracked.bool(False),
    flag = cms.string('Flag_HBHENoiseIsoFilter'),
    src = cms.InputTag("TriggerResults","","PAT")
)


process.hbheNoiseMiniAOD = cms.EDFilter("METFilterMiniAOD",
    applyfilter = cms.untracked.bool(True),
    debugOn = cms.untracked.bool(False),
    flag = cms.string('Flag_HBHENoiseFilter'),
    src = cms.InputTag("TriggerResults","","PAT")
)


process.hltPhysicsDeclared = cms.EDFilter("HLTPhysicsDeclared",
    L1GtReadoutRecordTag = cms.InputTag("gtDigis"),
    invert = cms.bool(False)
)


process.noscraping = cms.EDFilter("FilterOutScraping",
    applyfilter = cms.untracked.bool(True),
    debugOn = cms.untracked.bool(False),
    numtrack = cms.untracked.uint32(10),
    thresh = cms.untracked.double(0.25)
)


process.primaryVertex = cms.EDFilter("GoodVertexFilter",
    maxAbsZ = cms.double(24),
    maxd0 = cms.double(2),
    minimumNDOF = cms.uint32(4),
    vertexCollection = cms.InputTag("offlinePrimaryVertices")
)


process.primaryVertexMiniAOD = cms.EDFilter("METFilterMiniAOD",
    applyfilter = cms.untracked.bool(True),
    debugOn = cms.untracked.bool(False),
    flag = cms.string('Flag_goodVertices'),
    src = cms.InputTag("TriggerResults","","PAT")
)


process.EventCounter = cms.EDAnalyzer("EventCounter",
    genInfoTag = cms.InputTag("generator")
)


process.Our2016MuonsAllSignsHistos = cms.EDAnalyzer("Zprime2muHistosFromPAT",
    beamspot_src = cms.InputTag("offlineBeamSpot"),
    dilepton_src = cms.InputTag("Our2016MuonsAllSigns"),
    hardInteraction = cms.PSet(
        allowFakeResonance = cms.bool(True),
        doingElectrons = cms.bool(False),
        resonanceIds = cms.vint32(32, 23, 39, 5000039),
        shutUp = cms.bool(False),
        src = cms.InputTag("prunedGenParticles")
    ),
    lepton_src = cms.InputTag("Our2016Leptons","muons"),
    leptonsFromDileptons = cms.bool(True),
    useMadgraphWeight = cms.bool(True),
    use_bs_and_pv = cms.bool(True),
    usekFactor = cms.bool(False),
    vertex_src = cms.InputTag("offlineSlimmedPrimaryVertices")
)


process.Our2016MuonsMinusMuonsMinusHistos = cms.EDAnalyzer("Zprime2muHistosFromPAT",
    beamspot_src = cms.InputTag("offlineBeamSpot"),
    dilepton_src = cms.InputTag("Our2016MuonsMinusMuonsMinus"),
    hardInteraction = cms.PSet(
        allowFakeResonance = cms.bool(True),
        doingElectrons = cms.bool(False),
        resonanceIds = cms.vint32(32, 23, 39, 5000039),
        shutUp = cms.bool(False),
        src = cms.InputTag("prunedGenParticles")
    ),
    lepton_src = cms.InputTag("Our2016Leptons","muons"),
    leptonsFromDileptons = cms.bool(True),
    useMadgraphWeight = cms.bool(True),
    use_bs_and_pv = cms.bool(True),
    usekFactor = cms.bool(False),
    vertex_src = cms.InputTag("offlineSlimmedPrimaryVertices")
)


process.Our2016MuonsPlusMuonsMinusHistos = cms.EDAnalyzer("Zprime2muHistosFromPAT",
    beamspot_src = cms.InputTag("offlineBeamSpot"),
    dilepton_src = cms.InputTag("Our2016MuonsPlusMuonsMinus"),
    hardInteraction = cms.PSet(
        allowFakeResonance = cms.bool(True),
        doingElectrons = cms.bool(False),
        resonanceIds = cms.vint32(32, 23, 39, 5000039),
        shutUp = cms.bool(False),
        src = cms.InputTag("prunedGenParticles")
    ),
    lepton_src = cms.InputTag("Our2016Leptons","muons"),
    leptonsFromDileptons = cms.bool(True),
    useMadgraphWeight = cms.bool(True),
    use_bs_and_pv = cms.bool(True),
    usekFactor = cms.bool(False),
    vertex_src = cms.InputTag("offlineSlimmedPrimaryVertices")
)


process.Our2016MuonsPlusMuonsPlusHistos = cms.EDAnalyzer("Zprime2muHistosFromPAT",
    beamspot_src = cms.InputTag("offlineBeamSpot"),
    dilepton_src = cms.InputTag("Our2016MuonsPlusMuonsPlus"),
    hardInteraction = cms.PSet(
        allowFakeResonance = cms.bool(True),
        doingElectrons = cms.bool(False),
        resonanceIds = cms.vint32(32, 23, 39, 5000039),
        shutUp = cms.bool(False),
        src = cms.InputTag("prunedGenParticles")
    ),
    lepton_src = cms.InputTag("Our2016Leptons","muons"),
    leptonsFromDileptons = cms.bool(True),
    useMadgraphWeight = cms.bool(True),
    use_bs_and_pv = cms.bool(True),
    usekFactor = cms.bool(False),
    vertex_src = cms.InputTag("offlineSlimmedPrimaryVertices")
)


process.Our2016MuonsSameSignHistos = cms.EDAnalyzer("Zprime2muHistosFromPAT",
    beamspot_src = cms.InputTag("offlineBeamSpot"),
    dilepton_src = cms.InputTag("Our2016MuonsSameSign"),
    hardInteraction = cms.PSet(
        allowFakeResonance = cms.bool(True),
        doingElectrons = cms.bool(False),
        resonanceIds = cms.vint32(32, 23, 39, 5000039),
        shutUp = cms.bool(False),
        src = cms.InputTag("prunedGenParticles")
    ),
    lepton_src = cms.InputTag("Our2016Leptons","muons"),
    leptonsFromDileptons = cms.bool(True),
    useMadgraphWeight = cms.bool(True),
    use_bs_and_pv = cms.bool(True),
    usekFactor = cms.bool(False),
    vertex_src = cms.InputTag("offlineSlimmedPrimaryVertices")
)


process.SimpleMuonsAllSignsHistos = cms.EDAnalyzer("Zprime2muHistosFromPAT",
    beamspot_src = cms.InputTag("offlineBeamSpot"),
    dilepton_src = cms.InputTag("SimpleMuonsAllSigns"),
    hardInteraction = cms.PSet(
        allowFakeResonance = cms.bool(True),
        doingElectrons = cms.bool(False),
        resonanceIds = cms.vint32(32, 23, 39, 5000039),
        shutUp = cms.bool(False),
        src = cms.InputTag("prunedGenParticles")
    ),
    lepton_src = cms.InputTag("SimpleLeptons","muons"),
    leptonsFromDileptons = cms.bool(True),
    useMadgraphWeight = cms.bool(True),
    use_bs_and_pv = cms.bool(True),
    usekFactor = cms.bool(False),
    vertex_src = cms.InputTag("offlineSlimmedPrimaryVertices")
)


process.SimpleMuonsMinusMuonsMinusHistos = cms.EDAnalyzer("Zprime2muHistosFromPAT",
    beamspot_src = cms.InputTag("offlineBeamSpot"),
    dilepton_src = cms.InputTag("SimpleMuonsMinusMuonsMinus"),
    hardInteraction = cms.PSet(
        allowFakeResonance = cms.bool(True),
        doingElectrons = cms.bool(False),
        resonanceIds = cms.vint32(32, 23, 39, 5000039),
        shutUp = cms.bool(False),
        src = cms.InputTag("prunedGenParticles")
    ),
    lepton_src = cms.InputTag("SimpleLeptons","muons"),
    leptonsFromDileptons = cms.bool(True),
    useMadgraphWeight = cms.bool(True),
    use_bs_and_pv = cms.bool(True),
    usekFactor = cms.bool(False),
    vertex_src = cms.InputTag("offlineSlimmedPrimaryVertices")
)


process.SimpleMuonsPlusMuonsMinusHistos = cms.EDAnalyzer("Zprime2muHistosFromPAT",
    beamspot_src = cms.InputTag("offlineBeamSpot"),
    dilepton_src = cms.InputTag("SimpleMuonsPlusMuonsMinus"),
    hardInteraction = cms.PSet(
        allowFakeResonance = cms.bool(True),
        doingElectrons = cms.bool(False),
        resonanceIds = cms.vint32(32, 23, 39, 5000039),
        shutUp = cms.bool(False),
        src = cms.InputTag("prunedGenParticles")
    ),
    lepton_src = cms.InputTag("SimpleLeptons","muons"),
    leptonsFromDileptons = cms.bool(True),
    useMadgraphWeight = cms.bool(True),
    use_bs_and_pv = cms.bool(True),
    usekFactor = cms.bool(False),
    vertex_src = cms.InputTag("offlineSlimmedPrimaryVertices")
)


process.SimpleMuonsPlusMuonsPlusHistos = cms.EDAnalyzer("Zprime2muHistosFromPAT",
    beamspot_src = cms.InputTag("offlineBeamSpot"),
    dilepton_src = cms.InputTag("SimpleMuonsPlusMuonsPlus"),
    hardInteraction = cms.PSet(
        allowFakeResonance = cms.bool(True),
        doingElectrons = cms.bool(False),
        resonanceIds = cms.vint32(32, 23, 39, 5000039),
        shutUp = cms.bool(False),
        src = cms.InputTag("prunedGenParticles")
    ),
    lepton_src = cms.InputTag("SimpleLeptons","muons"),
    leptonsFromDileptons = cms.bool(True),
    useMadgraphWeight = cms.bool(True),
    use_bs_and_pv = cms.bool(True),
    usekFactor = cms.bool(False),
    vertex_src = cms.InputTag("offlineSlimmedPrimaryVertices")
)


process.SimpleMuonsSameSignHistos = cms.EDAnalyzer("Zprime2muHistosFromPAT",
    beamspot_src = cms.InputTag("offlineBeamSpot"),
    dilepton_src = cms.InputTag("SimpleMuonsSameSign"),
    hardInteraction = cms.PSet(
        allowFakeResonance = cms.bool(True),
        doingElectrons = cms.bool(False),
        resonanceIds = cms.vint32(32, 23, 39, 5000039),
        shutUp = cms.bool(False),
        src = cms.InputTag("prunedGenParticles")
    ),
    lepton_src = cms.InputTag("SimpleLeptons","muons"),
    leptonsFromDileptons = cms.bool(True),
    useMadgraphWeight = cms.bool(True),
    use_bs_and_pv = cms.bool(True),
    usekFactor = cms.bool(False),
    vertex_src = cms.InputTag("offlineSlimmedPrimaryVertices")
)


process.SimpleNtupler = cms.EDAnalyzer("SimpleNtupler_miniAOD",
    TriggerResults_src = cms.InputTag("TriggerResults","","PAT"),
    beamspot_src = cms.InputTag("offlineBeamSpot"),
    dimu_src = cms.InputTag("Our2016MuonsPlusMuonsMinus"),
    genEventInfo = cms.untracked.InputTag("generator"),
    hardInteraction = cms.PSet(
        allowFakeResonance = cms.bool(True),
        doingElectrons = cms.bool(False),
        resonanceIds = cms.vint32(32, 23, 39, 5000039),
        shutUp = cms.bool(False),
        src = cms.InputTag("prunedMCLeptons")
    ),
    jet_src = cms.InputTag("slimmedJets"),
    metFilter = cms.VInputTag(cms.InputTag("Flag_HBHENoiseFilter"), cms.InputTag("Flag_HBHENoiseIsoFilter"), cms.InputTag("Flag_EcalDeadCellTriggerPrimitiveFilter"), cms.InputTag("Flag_eeBadScFilter"), cms.InputTag("Flag_globalTightHalo2016Filter")),
    met_src = cms.InputTag("slimmedMETs"),
    vertices_src = cms.InputTag("offlineSlimmedPrimaryVertices")
)


process.Zprime2muAnalysisSequence_MiniAOD = cms.Sequence(process.muonPhotonMatchMiniAOD+process.leptonsMini+process.allDimuons+process.dimuons)


process.Zprime2muAnalysisSequence = cms.Sequence(process.muonPhotonMatch+process.leptons+process.allDimuons+process.dimuons)


process.egmGsfElectronIDSequence = cms.Sequence(process.electronMVAValueMapProducer+process.egmGsfElectronIDs+process.electronRegressionValueMapProducer)


process.pathSimple = cms.Path(process.EventCounter+process.dileptonPreseletor+process.muonPhotonMatchMiniAOD+process.egmGsfElectronIDSequence+process.SimpleLeptons+process.allSimpleMuonsPlusMuonsMinus+process.SimpleMuonsPlusMuonsMinus+process.SimpleMuonsPlusMuonsMinusHistos+process.allSimpleMuonsPlusMuonsPlus+process.SimpleMuonsPlusMuonsPlus+process.SimpleMuonsPlusMuonsPlusHistos+process.allSimpleMuonsMinusMuonsMinus+process.SimpleMuonsMinusMuonsMinus+process.SimpleMuonsMinusMuonsMinusHistos+process.allSimpleMuonsSameSign+process.SimpleMuonsSameSign+process.SimpleMuonsSameSignHistos+process.allSimpleMuonsAllSigns+process.SimpleMuonsAllSigns+process.SimpleMuonsAllSignsHistos)


process.pathOur2016 = cms.Path(process.primaryVertexMiniAOD+process.EventCounter+process.dileptonPreseletor+process.muonPhotonMatchMiniAOD+process.egmGsfElectronIDSequence+process.Our2016Leptons+process.allOur2016MuonsPlusMuonsMinus+process.Our2016MuonsPlusMuonsMinus+process.Our2016MuonsPlusMuonsMinusHistos+process.allOur2016MuonsPlusMuonsPlus+process.Our2016MuonsPlusMuonsPlus+process.Our2016MuonsPlusMuonsPlusHistos+process.allOur2016MuonsMinusMuonsMinus+process.Our2016MuonsMinusMuonsMinus+process.Our2016MuonsMinusMuonsMinusHistos+process.allOur2016MuonsSameSign+process.Our2016MuonsSameSign+process.Our2016MuonsSameSignHistos+process.allOur2016MuonsAllSigns+process.Our2016MuonsAllSigns+process.Our2016MuonsAllSignsHistos+process.prunedMCLeptons+process.SimpleNtupler)


process.MessageLogger = cms.Service("MessageLogger",
    FrameworkJobReport = cms.untracked.PSet(
        FwkJob = cms.untracked.PSet(
            limit = cms.untracked.int32(10000000),
            optionalPSet = cms.untracked.bool(True)
        ),
        default = cms.untracked.PSet(
            limit = cms.untracked.int32(0)
        ),
        optionalPSet = cms.untracked.bool(True)
    ),
    categories = cms.untracked.vstring('FwkJob', 
        'FwkReport', 
        'FwkSummary', 
        'Root_NoDictionary'),
    cerr = cms.untracked.PSet(
        FwkJob = cms.untracked.PSet(
            limit = cms.untracked.int32(0),
            optionalPSet = cms.untracked.bool(True)
        ),
        FwkReport = cms.untracked.PSet(
            limit = cms.untracked.int32(10000000),
            optionalPSet = cms.untracked.bool(True),
            reportEvery = cms.untracked.int32(1000)
        ),
        FwkSummary = cms.untracked.PSet(
            limit = cms.untracked.int32(10000000),
            optionalPSet = cms.untracked.bool(True),
            reportEvery = cms.untracked.int32(1)
        ),
        INFO = cms.untracked.PSet(
            limit = cms.untracked.int32(0)
        ),
        Root_NoDictionary = cms.untracked.PSet(
            limit = cms.untracked.int32(0),
            optionalPSet = cms.untracked.bool(True)
        ),
        default = cms.untracked.PSet(
            limit = cms.untracked.int32(10000000)
        ),
        noTimeStamps = cms.untracked.bool(False),
        optionalPSet = cms.untracked.bool(True),
        threshold = cms.untracked.string('INFO')
    ),
    cerr_stats = cms.untracked.PSet(
        optionalPSet = cms.untracked.bool(True),
        output = cms.untracked.string('cerr'),
        threshold = cms.untracked.string('WARNING')
    ),
    cout = cms.untracked.PSet(
        placeholder = cms.untracked.bool(True)
    ),
    debugModules = cms.untracked.vstring(),
    debugs = cms.untracked.PSet(
        placeholder = cms.untracked.bool(True)
    ),
    default = cms.untracked.PSet(

    ),
    destinations = cms.untracked.vstring('warnings', 
        'errors', 
        'infos', 
        'debugs', 
        'cout', 
        'cerr'),
    errors = cms.untracked.PSet(
        placeholder = cms.untracked.bool(True)
    ),
    fwkJobReports = cms.untracked.vstring('FrameworkJobReport'),
    infos = cms.untracked.PSet(
        Root_NoDictionary = cms.untracked.PSet(
            limit = cms.untracked.int32(0),
            optionalPSet = cms.untracked.bool(True)
        ),
        optionalPSet = cms.untracked.bool(True),
        placeholder = cms.untracked.bool(True)
    ),
    statistics = cms.untracked.vstring('cerr_stats'),
    suppressDebug = cms.untracked.vstring(),
    suppressInfo = cms.untracked.vstring(),
    suppressWarning = cms.untracked.vstring(),
    warnings = cms.untracked.PSet(
        placeholder = cms.untracked.bool(True)
    )
)


process.RandomNumberGeneratorService = cms.Service("RandomNumberGeneratorService",
    PrescaleToCommon = cms.PSet(
        initialSeed = cms.untracked.uint32(1219)
    ),
    PrescaleToCommonMiniAOD = cms.PSet(
        initialSeed = cms.untracked.uint32(1219)
    )
)


process.TFileService = cms.Service("TFileService",
    fileName = cms.string('zp2mu_histos.root')
)


process.CSCGeometryESModule = cms.ESProducer("CSCGeometryESModule",
    alignmentsLabel = cms.string(''),
    appendToDataLabel = cms.string(''),
    applyAlignment = cms.bool(True),
    debugV = cms.untracked.bool(False),
    useCentreTIOffsets = cms.bool(False),
    useDDD = cms.bool(False),
    useGangedStripsInME1a = cms.bool(True),
    useOnlyWiresInME1a = cms.bool(False),
    useRealWireGeometry = cms.bool(True)
)


process.CaloGeometryBuilder = cms.ESProducer("CaloGeometryBuilder",
    SelectedCalos = cms.vstring('HCAL', 
        'ZDC', 
        'CASTOR', 
        'EcalBarrel', 
        'EcalEndcap', 
        'EcalPreshower', 
        'TOWER')
)


process.CaloTopologyBuilder = cms.ESProducer("CaloTopologyBuilder")


process.CaloTowerGeometryFromDBEP = cms.ESProducer("CaloTowerGeometryFromDBEP",
    applyAlignment = cms.bool(False),
    hcalTopologyConstants = cms.PSet(
        maxDepthHB = cms.int32(2),
        maxDepthHE = cms.int32(3),
        mode = cms.string('HcalTopologyMode::LHC')
    )
)


process.CaloTowerTopologyEP = cms.ESProducer("CaloTowerTopologyEP")


process.CastorDbProducer = cms.ESProducer("CastorDbProducer")


process.CastorGeometryFromDBEP = cms.ESProducer("CastorGeometryFromDBEP",
    applyAlignment = cms.bool(False)
)


process.DTGeometryESModule = cms.ESProducer("DTGeometryESModule",
    alignmentsLabel = cms.string(''),
    appendToDataLabel = cms.string(''),
    applyAlignment = cms.bool(True),
    fromDDD = cms.bool(False)
)


process.EcalBarrelGeometryFromDBEP = cms.ESProducer("EcalBarrelGeometryFromDBEP",
    applyAlignment = cms.bool(True)
)


process.EcalElectronicsMappingBuilder = cms.ESProducer("EcalElectronicsMappingBuilder")


process.EcalEndcapGeometryFromDBEP = cms.ESProducer("EcalEndcapGeometryFromDBEP",
    applyAlignment = cms.bool(True)
)


process.EcalLaserCorrectionService = cms.ESProducer("EcalLaserCorrectionService")


process.EcalPreshowerGeometryFromDBEP = cms.ESProducer("EcalPreshowerGeometryFromDBEP",
    applyAlignment = cms.bool(True)
)


process.EcalTrigTowerConstituentsMapBuilder = cms.ESProducer("EcalTrigTowerConstituentsMapBuilder",
    MapFile = cms.untracked.string('Geometry/EcalMapping/data/EndCap_TTMap.txt')
)


process.GlobalTrackingGeometryESProducer = cms.ESProducer("GlobalTrackingGeometryESProducer")


process.HcalAlignmentEP = cms.ESProducer("HcalAlignmentEP")


process.HcalGeometryFromDBEP = cms.ESProducer("HcalGeometryFromDBEP",
    applyAlignment = cms.bool(True),
    hcalTopologyConstants = cms.PSet(
        maxDepthHB = cms.int32(2),
        maxDepthHE = cms.int32(3),
        mode = cms.string('HcalTopologyMode::LHC')
    )
)


process.MuonDetLayerGeometryESProducer = cms.ESProducer("MuonDetLayerGeometryESProducer")


process.ParabolicParametrizedMagneticFieldProducer = cms.ESProducer("ParametrizedMagneticFieldProducer",
    label = cms.untracked.string('ParabolicMf'),
    parameters = cms.PSet(

    ),
    version = cms.string('Parabolic')
)


process.ParametrizedMagneticFieldProducer = cms.ESProducer("ParametrizedMagneticFieldProducer",
    label = cms.untracked.string('parametrizedField'),
    parameters = cms.PSet(
        BValue = cms.string('3_8T')
    ),
    version = cms.string('OAE_1103l_071212')
)


process.RPCGeometryESModule = cms.ESProducer("RPCGeometryESModule",
    compatibiltyWith11 = cms.untracked.bool(True),
    useDDD = cms.untracked.bool(False)
)


process.SiStripRecHitMatcherESProducer = cms.ESProducer("SiStripRecHitMatcherESProducer",
    ComponentName = cms.string('StandardMatcher'),
    NSigmaInside = cms.double(3.0),
    PreFilter = cms.bool(False)
)


process.StripCPEfromTrackAngleESProducer = cms.ESProducer("StripCPEESProducer",
    ComponentName = cms.string('StripCPEfromTrackAngle'),
    ComponentType = cms.string('StripCPEfromTrackAngle'),
    parameters = cms.PSet(
        mLC_P0 = cms.double(-0.326),
        mLC_P1 = cms.double(0.618),
        mLC_P2 = cms.double(0.3),
        mTEC_P0 = cms.double(-1.885),
        mTEC_P1 = cms.double(0.471),
        mTIB_P0 = cms.double(-0.742),
        mTIB_P1 = cms.double(0.202),
        mTID_P0 = cms.double(-1.427),
        mTID_P1 = cms.double(0.433),
        mTOB_P0 = cms.double(-1.026),
        mTOB_P1 = cms.double(0.253),
        maxChgOneMIP = cms.double(6000.0),
        useLegacyError = cms.bool(False)
    )
)


process.TrackerRecoGeometryESProducer = cms.ESProducer("TrackerRecoGeometryESProducer")


process.TransientTrackBuilderESProducer = cms.ESProducer("TransientTrackBuilderESProducer",
    ComponentName = cms.string('TransientTrackBuilder')
)


process.VolumeBasedMagneticFieldESProducer = cms.ESProducer("VolumeBasedMagneticFieldESProducer",
    cacheLastVolume = cms.untracked.bool(True),
    debugBuilder = cms.untracked.bool(False),
    geometryVersion = cms.int32(120812),
    gridFiles = cms.VPSet(cms.PSet(
        master = cms.int32(0),
        path = cms.string('s[s]_1/grid.[v].bin'),
        sectors = cms.string('0'),
        volumes = cms.string('1001-1010,1012-1027,1030-1033,1036-1041,1044-1049,1052-1057,1060-1063,1066-1071,1074-1077,1080-1083,1130-1133,1138-1360')
    ), 
        cms.PSet(
            master = cms.int32(0),
            path = cms.string('s[s]_2/grid.[v].bin'),
            sectors = cms.string('0'),
            volumes = cms.string('2001-2010,2012-2027,2030-2033,2036-2041,2044-2049,2052-2057,2060-2063,2066-2071,2074-2077,2080-2083,2130-2133,2138-2360')
        ), 
        cms.PSet(
            master = cms.int32(1),
            path = cms.string('s01_1/grid.[v].bin'),
            sectors = cms.string('0'),
            volumes = cms.string('1011,1028-1029,1034-1035,1042-1043,1050-1051,1058-1059,1064-1065,1072-1073,1078-1079,1084-1129,1136-1137')
        ), 
        cms.PSet(
            master = cms.int32(1),
            path = cms.string('s01_2/grid.[v].bin'),
            sectors = cms.string('0'),
            volumes = cms.string('2011,2028-2029,2034-2035,2042-2043,2050-2051,2058-2059,2064-2065,2072-2073,2078-2079,2084-2129,2136-2137')
        ), 
        cms.PSet(
            master = cms.int32(4),
            path = cms.string('s04_1/grid.[v].bin'),
            sectors = cms.string('0'),
            volumes = cms.string('1134-1135')
        ), 
        cms.PSet(
            master = cms.int32(4),
            path = cms.string('s04_2/grid.[v].bin'),
            sectors = cms.string('0'),
            volumes = cms.string('2134-2135')
        )),
    label = cms.untracked.string(''),
    paramLabel = cms.string('parametrizedField'),
    scalingFactors = cms.vdouble(),
    scalingVolumes = cms.vint32(),
    useParametrizedTrackerField = cms.bool(True),
    version = cms.string('grid_120812_3_8t_v7_large')
)


process.ZdcGeometryFromDBEP = cms.ESProducer("ZdcGeometryFromDBEP",
    applyAlignment = cms.bool(False)
)


process.fakeForIdealAlignment = cms.ESProducer("FakeAlignmentProducer",
    appendToDataLabel = cms.string('fakeForIdeal')
)


process.hcalDDDRecConstants = cms.ESProducer("HcalDDDRecConstantsESModule",
    appendToDataLabel = cms.string('')
)


process.hcalDDDSimConstants = cms.ESProducer("HcalDDDSimConstantsESModule",
    appendToDataLabel = cms.string('')
)


process.hcalTopologyIdeal = cms.ESProducer("HcalTopologyIdealEP",
    Exclude = cms.untracked.string(''),
    appendToDataLabel = cms.string('')
)


process.hcal_db_producer = cms.ESProducer("HcalDbProducer",
    dump = cms.untracked.vstring(''),
    file = cms.untracked.string('')
)


process.idealForDigiCSCGeometry = cms.ESProducer("CSCGeometryESModule",
    alignmentsLabel = cms.string('fakeForIdeal'),
    appendToDataLabel = cms.string('idealForDigi'),
    applyAlignment = cms.bool(False),
    debugV = cms.untracked.bool(False),
    useCentreTIOffsets = cms.bool(False),
    useDDD = cms.bool(False),
    useGangedStripsInME1a = cms.bool(True),
    useOnlyWiresInME1a = cms.bool(False),
    useRealWireGeometry = cms.bool(True)
)


process.idealForDigiDTGeometry = cms.ESProducer("DTGeometryESModule",
    alignmentsLabel = cms.string('fakeForIdeal'),
    appendToDataLabel = cms.string('idealForDigi'),
    applyAlignment = cms.bool(False),
    fromDDD = cms.bool(False)
)


process.idealForDigiTrackerGeometry = cms.ESProducer("TrackerDigiGeometryESModule",
    alignmentsLabel = cms.string('fakeForIdeal'),
    appendToDataLabel = cms.string('idealForDigi'),
    applyAlignment = cms.bool(False),
    fromDDD = cms.bool(False)
)


process.siPixelQualityESProducer = cms.ESProducer("SiPixelQualityESProducer",
    ListOfRecordToMerge = cms.VPSet(cms.PSet(
        record = cms.string('SiPixelQualityFromDbRcd'),
        tag = cms.string('')
    ), 
        cms.PSet(
            record = cms.string('SiPixelDetVOffRcd'),
            tag = cms.string('')
        ))
)


process.siStripBackPlaneCorrectionDepESProducer = cms.ESProducer("SiStripBackPlaneCorrectionDepESProducer",
    BackPlaneCorrectionDeconvMode = cms.PSet(
        label = cms.untracked.string('deconvolution'),
        record = cms.string('SiStripBackPlaneCorrectionRcd')
    ),
    BackPlaneCorrectionPeakMode = cms.PSet(
        label = cms.untracked.string('peak'),
        record = cms.string('SiStripBackPlaneCorrectionRcd')
    ),
    LatencyRecord = cms.PSet(
        label = cms.untracked.string(''),
        record = cms.string('SiStripLatencyRcd')
    )
)


process.siStripGainESProducer = cms.ESProducer("SiStripGainESProducer",
    APVGain = cms.VPSet(cms.PSet(
        Label = cms.untracked.string(''),
        NormalizationFactor = cms.untracked.double(1.0),
        Record = cms.string('SiStripApvGainRcd')
    ), 
        cms.PSet(
            Label = cms.untracked.string(''),
            NormalizationFactor = cms.untracked.double(1.0),
            Record = cms.string('SiStripApvGain2Rcd')
        )),
    AutomaticNormalization = cms.bool(False),
    appendToDataLabel = cms.string(''),
    printDebug = cms.untracked.bool(False)
)


process.siStripLorentzAngleDepESProducer = cms.ESProducer("SiStripLorentzAngleDepESProducer",
    LatencyRecord = cms.PSet(
        label = cms.untracked.string(''),
        record = cms.string('SiStripLatencyRcd')
    ),
    LorentzAngleDeconvMode = cms.PSet(
        label = cms.untracked.string('deconvolution'),
        record = cms.string('SiStripLorentzAngleRcd')
    ),
    LorentzAnglePeakMode = cms.PSet(
        label = cms.untracked.string('peak'),
        record = cms.string('SiStripLorentzAngleRcd')
    )
)


process.siStripQualityESProducer = cms.ESProducer("SiStripQualityESProducer",
    ListOfRecordToMerge = cms.VPSet(cms.PSet(
        record = cms.string('SiStripDetVOffRcd'),
        tag = cms.string('')
    ), 
        cms.PSet(
            record = cms.string('SiStripDetCablingRcd'),
            tag = cms.string('')
        ), 
        cms.PSet(
            record = cms.string('RunInfoRcd'),
            tag = cms.string('')
        ), 
        cms.PSet(
            record = cms.string('SiStripBadChannelRcd'),
            tag = cms.string('')
        ), 
        cms.PSet(
            record = cms.string('SiStripBadFiberRcd'),
            tag = cms.string('')
        ), 
        cms.PSet(
            record = cms.string('SiStripBadModuleRcd'),
            tag = cms.string('')
        ), 
        cms.PSet(
            record = cms.string('SiStripBadStripRcd'),
            tag = cms.string('')
        )),
    PrintDebugOutput = cms.bool(False),
    ReduceGranularity = cms.bool(False),
    ThresholdForReducedGranularity = cms.double(0.3),
    UseEmptyRunInfo = cms.bool(False),
    appendToDataLabel = cms.string('')
)


process.sistripconn = cms.ESProducer("SiStripConnectivity")


process.stripCPEESProducer = cms.ESProducer("StripCPEESProducer",
    ComponentName = cms.string('stripCPE'),
    ComponentType = cms.string('SimpleStripCPE'),
    parameters = cms.PSet(

    )
)


process.trackerGeometryDB = cms.ESProducer("TrackerDigiGeometryESModule",
    alignmentsLabel = cms.string(''),
    appendToDataLabel = cms.string(''),
    applyAlignment = cms.bool(True),
    fromDDD = cms.bool(False)
)


process.trackerNumberingGeometryDB = cms.ESProducer("TrackerGeometricDetESModule",
    appendToDataLabel = cms.string(''),
    fromDDD = cms.bool(False)
)


process.trackerTopology = cms.ESProducer("TrackerTopologyEP",
    appendToDataLabel = cms.string('')
)


process.GlobalTag = cms.ESSource("PoolDBESSource",
    DBParameters = cms.PSet(
        authenticationPath = cms.untracked.string(''),
        authenticationSystem = cms.untracked.int32(0),
        messageLevel = cms.untracked.int32(0),
        security = cms.untracked.string('')
    ),
    DumpStat = cms.untracked.bool(False),
    ReconnectEachRun = cms.untracked.bool(False),
    RefreshAlways = cms.untracked.bool(False),
    RefreshEachRun = cms.untracked.bool(False),
    RefreshOpenIOVs = cms.untracked.bool(False),
    connect = cms.string('frontier://FrontierProd/CMS_CONDITIONS'),
    globaltag = cms.string('80X_mcRun2_asymptotic_2016_miniAODv2_v1'),
    pfnPostfix = cms.untracked.string(''),
    pfnPrefix = cms.untracked.string(''),
    snapshotTime = cms.string(''),
    toGet = cms.VPSet()
)


process.eegeom = cms.ESSource("EmptyESSource",
    firstValid = cms.vuint32(1),
    iovIsRunNotTime = cms.bool(True),
    recordName = cms.string('EcalMappingRcd')
)


process.es_hardcode = cms.ESSource("HcalHardcodeCalibrations",
    GainWidthsForTrigPrims = cms.bool(False),
    HERecalibration = cms.bool(False),
    HEreCalibCutoff = cms.double(20.0),
    HFRecalibration = cms.bool(False),
    iLumi = cms.double(-1.0),
    testHFQIE10 = cms.bool(False),
    toGet = cms.untracked.vstring('GainWidths')
)


process.magfield = cms.ESSource("XMLIdealGeometryESSource",
    geomXMLFiles = cms.vstring('Geometry/CMSCommonData/data/normal/cmsextent.xml', 
        'Geometry/CMSCommonData/data/cms.xml', 
        'Geometry/CMSCommonData/data/cmsMagneticField.xml', 
        'MagneticField/GeomBuilder/data/MagneticFieldVolumes_1_v7_large.xml', 
        'MagneticField/GeomBuilder/data/MagneticFieldVolumes_2_v7_large.xml', 
        'Geometry/CMSCommonData/data/materials.xml'),
    rootNodeName = cms.string('cmsMagneticField:MAGF')
)


process.prefer("es_hardcode")

process.prefer("magfield")

