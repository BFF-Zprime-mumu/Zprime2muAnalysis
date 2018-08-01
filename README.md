# Compilation instructions

## Setup CMSSW_8_0_29
It is required for latest JEC

```bash
cmsrel CMSSW_8_0_29
cd CMSSW_8_0_29/src
cmsenv
```

## Setup electron HEEP ID
Follow the [official instructions](https://twiki.cern.ch/twiki/bin/view/CMS/HEEPElectronIdentificationRun2#Instructions_to_check_out_HEEPV7)
```bash
git cms-merge-topic Sam-Harper:HEEPV70VID_8010_ReducedCheckout  #brings in HEEP V70 into VID
git cms-merge-topic ikrav:egm_id_80X_v3 #for other E/gamma IDs in VID if you wish to have them
git cms-merge-topic Sam-Harper:PackedCandNoPuppi #only necessary to run HEEP V70 on AOD (it will crash if this is not present looking for puppi candidates
mkdir -p ../external/slc6_amd64_gcc530/data/RecoEgamma/ElectronIdentification/ #we need this for the mva weights which runs in VID regardless if you need it or not
git clone git@github.com:cms-data/RecoEgamma-ElectronIdentification
../external/slc6_amd64_gcc530/data/RecoEgamma/ElectronIdentification/data #we need this for the mva weights which runs in VID regardless if you need it or not
```

## Get BFF-Zprime-mumu code
```bash
mkdir SUSYBSMAnalysis && cd SUSYBSMAnalysis/
git clone git@github.com:BFF-Zprime-mumu/Zprime2muAnalysis.git
#if required, checkout the non-default branch by running cd Zprime2muAnalysis && git checkout <branch name> && cd ../
cd ../
```
## Compile
```bash
scram b clean
scram b -j 16
```

# Running test jobs locally
```bash
cd SUSYBSMAnalysis/Zprime2muAnalysis/test/DataMCSpectraComparison
#modify the number of events to process to some small quantity, e.g. 100
cmsRun histosSimplified.py
```

# Running the code for grid production of miniAOD and ntuples

```bash
cd SUSYBSMAnalysis/Zprime2muAnalysis/test/DataMCSpectraComparison

#DY Dataset: /DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext2-v1/MINIAODSIM
#TTbar Dataset: /TTTo2L2Nu_TuneCUETP8M2_ttHtranche3_13TeV-powheg-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM
#Changing the sample pile path in the histosSimplified.py file.
#After modifying storageSite in crabConfig.py and crabConfig_TT.py, submit crab job
#DY sample

crab submit -c crabConfig.py

#TTbar sample

crab submit -c crabConfig_TT.py

#In the generated ntuple files, the tree for the di-muon channel is SimpleNtupler/t and the tree for the e-mu channel is SimpleNtuplerEmu/t.
```

# Producing the plots
TBD
