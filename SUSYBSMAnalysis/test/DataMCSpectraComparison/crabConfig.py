from CRABClient.UserUtilities import config

config = config()

config.section_('General')
#config.General.requestName = 'DY_sample'
config.General.workArea = 'crab_projects/DY_sample'
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
config.Data.inputDataset = '/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext2-v1/MINIAODSIM'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 1
#config.Data.totalUnits = 10
#config.Data.outLFNDirBase =  '/store/user/hgass66/crab'

config.section_('User')

config.section_('Site')
config.Site.storageSite = 'T2_KR_KNU'
