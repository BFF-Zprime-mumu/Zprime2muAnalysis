from os import listdir, mkdir, popen
from os.path import isfile, join, exists
from sampleDict import sampleDict
from ROOT import *
import json


gSystem.CompileMacro("mumu.C", "gOck")
gSystem.Load("mumu_C")

def makePlots(l_sampleDict, lumi, cutString, treeString):
  chain = TChain('{0}/t'.format(tree))
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
  cutFlow = instance.Loop("output/{0}_{2}_{1}".format(cutString,l_sampleDict['outName'],treeString),l_sampleDict['xsection'],lumi,l_sampleDict['totalEvents'], cutString)#
  return [cutFlow[0],cutFlow[1],cutFlow[2],cutFlow[3]]


cutStrings = ["b=1_j=0",
"b=1,2_b+j=2",
"2"]

#cutStrings = ["1",
#"2",
#"3",
#"4",
#"5",
#""]

treeName = ["SimpleNtuplerDiEle","SimpleNtupler"]
cutFlow = {}

for cutString in cutStrings:
  cutFlow[cutString] = {}
  for tree in treeName:
    cutFlow[cutString][tree] = {}
    for sample in sampleDict:
      print sample, tree, sampleDict[sample]['outName']
      cutFlow[cutString][tree][sample] = makePlots(sampleDict[sample], 35.9, cutString, tree)

with open('cutflow.json','w') as fp:
  json.dump(cutFlow, fp, indent=4)

