
sampleDict = {}

runDataEmu = False
if runDataEmu:
	sampleDict['2016G_SingleMu_eMu'] ={
	"path":["/store/user/rymuelle/zPrime/data/eMu/SingleMuon/crab_20190216_191749/190217_011842/0000/",
	"/store/user/rymuelle/zPrime/data/eMu/SingleMuon/crab_20190216_191749/190217_011842/0001/"],
	"xsection": -1,
	"totalEvents": -1,
	"outName":"2016G_SingleMu.root"}


runDataMu = False
if runDataMu:
	sampleDict['2016G_SingleMu'] ={
	"path":["/store/user/rymuelle/zPrime/data/SingleMuon/crab_20181029_025505/181029_075532/0000/",
	"/store/user/rymuelle/zPrime/data/SingleMuon/crab_20181029_025505/181029_075532/0001/"],
	"xsection": -1,
	"totalEvents": -1,
	"outName":"2016G_SingleMu.root"}
	
	
	sampleDict['2016B_SingleMu'] ={
	"path":["/store/user/rymuelle/zPrime/data/SingleMuon/crab_20190103_172734/190103_232823/0000/",
	"/store/user/rymuelle/zPrime/data/SingleMuon/crab_20190103_172734/190103_232823/0001/"],
	"xsection": -1,
	"totalEvents": -1,
	"outName":"2016B_SingleMu.root"}
	
	sampleDict['2016C_SingleMu'] ={
	"path":["/store/user/rymuelle/zPrime/data/SingleMuon/crab_20190103_174725/190103_234743/0000/"],
	"xsection": -1,
	"totalEvents": -1,
	"outName":"2016C_SingleMu.root"}
	
	
	sampleDict['2016D_SingleMu'] ={
	"path":["/store/user/rymuelle/zPrime/data/SingleMuon/crab_20190103_180847/190104_000906/0000/",
	"/store/user/rymuelle/zPrime/data/SingleMuon/crab_20190103_180847/190104_000906/0001/"],
	"xsection": -1,
	"totalEvents": -1,
	"outName":"2016D_SingleMu.root"}
	
	sampleDict['2016F_SingleMu'] ={
	"path":["/store/user/rymuelle/zPrime/data/SingleMuon/crab_20181029_020212/181029_070241/0000/"],
	"xsection": -1,
	"totalEvents": -1,
	"outName":"2016F_SingleMu_probably.root"}
	
	sampleDict['2016E_SingleMu'] ={
	"path":["/store/user/rymuelle/zPrime/data/SingleMuon/crab_20190103_190016/190104_010035/0000/"],
	"xsection": -1,
	"totalEvents": -1,
	"outName":"2016E_SingleMu.root"}


runDataE = False
if runDataE:
	sampleDict['2016F_singleElectron'] ={
	"path":["/store/user/rymuelle/zPrime/data/SingleElectron/crab_20181031_191318/181101_001337/0000/",
	"/store/user/rymuelle/zPrime/data/SingleElectron/crab_20181031_191318/181101_001337/0001/",],
	"xsection": -1,
	"totalEvents": -1,
	"outName":"2016F_singleElectron_new.root"}
	
	#
	sampleDict['2016G_SingleElectron'] ={
	"path":["/store/user/rymuelle/zPrime/data/SingleElectron/crab_20181031_191318/181101_001337/0000/",
	"/store/user/rymuelle/zPrime/data/SingleElectron/crab_20181031_191318/181101_001337/0001/"],
	"xsection": -1,
	"totalEvents": -1,
	"outName":"2016G_SingleElectron.root"}
	
	#
	sampleDict['2016D_SingleElectron'] ={
	"path":["/store/user/rymuelle/zPrime/data/SingleElectron/crab_20190130_135435/190130_195456/0000/",
	"/store/user/rymuelle/zPrime/data/SingleElectron/crab_20190130_135435/190130_195456/0001/"],
	"xsection": -1,
	"totalEvents": -1,
	"outName":"2016D_SingleElectron.root"}
	
	
	#
	sampleDict['2016C_SingleElectron'] ={
	"path":["/store/user/rymuelle/zPrime/data/C/SingleElectron/crab_20190130_135945/190130_200004/0000/",
	"/store/user/rymuelle/zPrime/data/C/SingleElectron/crab_20190130_135945/190130_200004/0001/"],
	"xsection": -1,
	"totalEvents": -1,
	"outName":"2016C_SingleElectron.root"}
	
	#
	sampleDict['2016B_SingleElectron'] ={
	"path":["/store/user/rymuelle/zPrime/data/B/SingleElectron/crab_20190130_140208/190130_200234/0000/",
	"/store/user/rymuelle/zPrime/data/B/SingleElectron/crab_20190130_140208/190130_200234/0001/",
	"/store/user/rymuelle/zPrime/data/B/SingleElectron/crab_20190130_140208/190130_200234/0002/"],
	"xsection": -1,
	"totalEvents": -1,
	"outName":"2016B_SingleElectron.root"}
	
	#
	sampleDict['2016E_SingleElectron'] ={
	"path":["/store/user/rymuelle/zPrime/data/SingleElectron/crab_20190130_134220/190130_194256/0000/",
	"/store/user/rymuelle/zPrime/data/SingleElectron/crab_20190130_134220/190130_194256/0001/"],
	"xsection": -1,
	"totalEvents": -1,
	"outName":"2016E_SingleElectron.root"}


runZp = True
if runZp:
	sampleDict['zp200_2016'] ={
	"path":["/store/user/rymuelle/zPrime/sample/zp_official_2016_200GeV.root"],
	"xsection": 0.28805 * 1000,
	"totalEvents": 100000,
	"outName":"zp200_2016_new.root"}
	
	sampleDict['zp350_2016'] ={
	"path":["/store/user/rymuelle/zPrime/sample/zp_official_2016_350GeV.root"],
	"xsection": 0.03101 * 1000,
	"totalEvents": 100000,
	"outName":"zp350_2016_new.root"}
	
	sampleDict['zp500_2016'] ={
	"path":["/store/user/rymuelle/zPrime/sample/zp_official_2016_500GeV.root"],
	"xsection": 0.006454 * 1000,
	"totalEvents": 100000,
	"outName":"zp500_2016_new.root"}

runMC = False
if runMC:
	sampleDict['ZZ_TuneCUETP8M1_13TeV'] ={
	"path":["/store/user/rymuelle/zPrime/backgrounds/ZZ_TuneCUETP8M1_13TeV-pythia8/180802_085945/0000/"],
	"xsection": 10.16 * 1000,
	"totalEvents": 990064,
	"outName":"ZZ_TuneCUETP8M1_13TeV_new.root"}


	#DY sample:
	sampleDict['DYJetsToLL_M_IS'] ={
	"path":["/store/user/rmueller/zPrime/DY_with_weights_and_IS/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_20190121_174950/190121_235033/0000/"],
	"xsection": 5765.4 * 1000,
	"totalEvents": 122055388,
	"outName":"DYJetsToLL_M_IS_new.root"}
	
	sampleDict['TTTo2L2Nu_TuneCUETP8M2_ttHtranche3_13TeV'] ={
	"path":["/store/user/rymuelle/zPrime/TT_with_weights_and_IS/TTTo2L2Nu_TuneCUETP8M2_ttHtranche3_13TeV-powheg-pythia8/crab_20190125_140029/190125_200105/0000/",
	"/store/user/rymuelle/zPrime/TT_with_weights_and_IS/TTTo2L2Nu_TuneCUETP8M2_ttHtranche3_13TeV-powheg-pythia8/crab_20190125_140029/190125_200105/0001/"],
	"xsection":87.31 * 1000,
	"totalEvents":79092400,
	"outName": "TTTo2L2Nu_TuneCUETP8M2_ttHtranche3_13TeV_M_IS_without_wegiths_new.root"}
	
	sampleDict['WWTo2L2Nu_13TeV'] ={
	"path":["/store/user/rymuelle/zPrime/backgrounds/WWTo2L2Nu_13TeV-powheg/180802_085237/0000/"],
	"xsection": 10.48 * 1000,
	"totalEvents": 1999000,
	"outName":"WWTo2L2Nu_13TeV_new.root"}
	
	sampleDict['ST_tW_top_5f_inclusiveDecays_13TeV'] ={
	"path":["/store/user/rymuelle/zPrime/backgrounds/ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/180802_084720/0000/"],
	"xsection": 38.09 * 1000,
	"totalEvents": 6952830,
	"outName":"ST_tW_top_5f_inclusiveDecays_13TeV_new.root"}
	
	sampleDict['ST_tW_antitop_5f_inclusiveDecays_13TeV'] ={
	"path":["/store/user/rymuelle/zPrime/backgrounds/ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/180802_084322/0000/"],
	"xsection": 38.06 * 1000,
	"totalEvents": 6933094,
	"outName":"ST_tW_antitop_5f_inclusiveDecays_13TeV_new.root"}
	
	sampleDict['WZ_TuneCUETP8M1_13TeV'] ={
	"path":["/store/user/rymuelle/zPrime/backgrounds/WZ_TuneCUETP8M1_13TeV-pythia8/180802_085635/0000/"],
	"xsection": 23.43 * 1000,
	"totalEvents": 1000000,
	"outName":"WZ_TuneCUETP8M1_13TeV_new.root"}
	