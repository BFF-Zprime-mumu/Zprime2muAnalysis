
//This is a method for background sample ntuple production on di-electron channel and e-mu channel.

cmsrel CMSSW_8_0_25

cd CMSSW_8_0_25/src

cmsenv

git clone git@github.com:hyeahyun/test.git

mv Zprime2muAnalysis/SUSYBSMAnalysis SUSYBSMAnalysis

scram b -j 16

cd ../..

scram p -n CMSSW_8025_emu CMSSW_8_0_25

cd CMSSW_8025_emu/src

cmsenv

git cms-merge-topic Sam-Harper:HEEPV70VID

cp -r your_path_for_SUSYBSMAnalysis_Zprime2muAnalysis/SUSYBSMAnalysis .

scram b -j 16

cd SUSYBSMAnalysis/Zprime2muAnalysis/test/DataMCSpectraComparison

//DY Dataset: /DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext2-v1/MINIAODSIM

//TTbar Dataset: /TTTo2L2Nu_TuneCUETP8M2_ttHtranche3_13TeV-powheg-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM

//Changing the sample pile path in the histosSimplified.py file.

//After modifying storageSite in crabConfig.py and crabConfig_TT.py, submit crab job

//DY sample

crab submit -c crabConfig.py

//TTbar sample

crab submit -c crabConfig_TT.py

//In the generated ntuple files, the tree for the di-muon channel is SimpleNtupler/t and the tree for the e-mu channel is SimpleNtuplerEmu/t.
