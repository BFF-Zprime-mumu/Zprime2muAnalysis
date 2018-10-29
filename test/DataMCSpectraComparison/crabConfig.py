from CRABClient.UserUtilities import config

config = config()

config.section_('General')
config.General.workArea = 'crab_projects/'
config.General.transferOutputs = True
config.General.transferLogs = True

config.section_('JobType')
config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'histosSimplified.py'
#confog.JobType.outputFiles = ['outfileName.root']

config.section_('Data')
#T2_~ '/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/RunIISummer16MiniAODv2-BS2016_BSandPUSummer16_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v2/MINIAODSIM'
#just N/A : /DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/RunIIFall15DR75-Asympt25nsFlat10to30RawReco_HCALDebug_75X_mcRun2_asymptotic_v8-v1/DQMIO
config.Data.inputDBS = 'global'
#config.Data.inputDataset = '/SingleMuon/Run2016F-23Sep2016-v1/MINIAOD'
config.Data.inputDataset = '/SingleMuon/Run2016G-23Sep2016-v1/MINIAOD'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 1
#config.Data.totalUnits = 10
config.Data.outLFNDirBase =  '/store/user/rymuelle/zPrime/data'
config.Data.lumiMask = 'Cert_271036-284044_13TeV_23Sep2016ReReco_Collisions16_JSON.txt'

config.section_('User')

config.section_('Site')
config.Data.publication = False
config.Site.storageSite = 'T3_US_FNALLPC'
