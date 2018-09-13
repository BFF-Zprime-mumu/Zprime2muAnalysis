from os import listdir, mkdir, popen
from os.path import isfile, join, exists
from sampleDict import sampleDict
from ROOT import *

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
  instance.Loop("output/%s" % l_sampleDict['outName'],l_sampleDict['xsection'],lumi,l_sampleDict['totalEvents'])#


gSystem.Load("mumu_C")

for sample in sampleDict:
  #print sample, sampleDict[sample]
  makePlots(sampleDict[sample], 35.9)
