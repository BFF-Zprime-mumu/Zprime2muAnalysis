import FWCore.ParameterSet.Config as cms

dileptonPreseletor = cms.EDFilter("DileptonPreselector",
	muons = cms.InputTag("slimmedMuons"),
	nMuons = cms.double(0),
	ptCut = cms.double(40),	

)
