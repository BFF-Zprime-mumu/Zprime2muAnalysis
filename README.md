
cmsrel CMSSW_8_0_20

cd CMSSW_8_0_20/src

cmsenv

git clone git@github.com:BFF-Zprime-mumu/Zprime2muAnalysis.git

mv Zprime2muAnalysis/SUSYBSMAnalysis SUSYBSMAnalysis

scram b -j 4

cd SUSYBSMAnalysis/Zprime2muAnalysis/test/DataMCSpectraComparison

// After changing the sample pile path in the histosSimplified.py file,

cmsRun histosSimplified.py

// The zp2mu_histos.root file is created.
