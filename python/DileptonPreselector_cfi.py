import FWCore.ParameterSet.Config as cms

dileptonPreseletor = cms.EDFilter("DileptonPreselector",
	muons = cms.InputTag("slimmedMuons"),
	nMuons = cms.double(1),
	ptCut = cms.double(40),	

)
