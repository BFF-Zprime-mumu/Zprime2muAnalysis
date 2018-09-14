from os import listdir, mkdir, popen
from os.path import isfile, join, exists
from sampleDict import sampleDict
from ROOT import *


gSystem.CompileMacro("mumu.C", "gOck")
gSystem.Load("mumu_C")

def makePlots(l_sampleDict, lumi):
  chain = TChain('SimpleNtupler/t')
  inFiles = []

  for path in l_sampleDict['path']:
    for inFile in filter(None,popen("ls -u "+path).read().split('\n')):
      if ".root" in inFile and ".root" not in path:
        pathString = path  + inFile
      elif ".root" in path:
        pathString = path


      chain.Add(pathString)

  instance = mumu(chain)

  if not exists("output"):
    mkdir("output")
  instance.Loop("output/%s" % l_sampleDict['outName'],l_sampleDict['xsection'],lumi,l_sampleDict['totalEvents'], "3")#




for sample in sampleDict:
  #print sample, sampleDict[sample]
  makePlots(sampleDict[sample], 35.9)


'''                       //if(bJets.size() < 1 || bJets.size()+non_bJets.size() < 2) continue;//N_jet >= 2, N_bjets >= 1 (Case 1)
                       //if(bJets.size() < 1 || Njet < 2) continue;//N_bjet >= 1, N_jet >= 2
                       //if(bJets.size() != 1 || non_bJets.size() != 0) continue;//N_jet = 1, N_bjet = 1 (Case 2)
                       //if(bJets.size() < 1 || bJets.size()+non_bJets.size() == 2) continue;//N_jet = 2, N_bjet >=1(1or2) (Case 3)
                       //if(bJets.size() < 1 || bJets.size() > 2 || bJets.size()+non_bJets.size() < 3) continue;//N_jet >= 3, N_bjets = 1or2 (Case 4)
                       //if(bJets.size() < 3) continue;//N_jet >=3, N_bjet >= 3 (Case 5)


ncut
njets_ge_2_nbjets_ge_1
njets_e_1_nbjets_e_1 if(bJets.size() != 1 || non_bJets.size() != 0) continue;//N_jet = 1, N_bjet = 1 (Case 2)
njets_e_2_nbjets_e_1_or_2 if(bJets.size() < 1 || bJets.size()+non_bJets.size() == 2) continue;//N_jet = 2, N_bjet >=1(1or2) (Case 3) #wrong
njets_ge_3_nbjets_e_1_or_2 if(bJets.size() < 1 || bJets.size() > 2 || bJets.size()+non_bJets.size() < 3) continue;//N_jet >= 3 and N_bjets = 1or2 (Case 4)
njets_ge_3_nbjets_ge_3 if(bJets.size() < 3) continue;//N_jet >=3 and N_bjet >= 3 (Case 5) 
'''