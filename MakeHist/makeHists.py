from os import listdir, mkdir, popen
from os.path import isfile, join, exists
from sampleDict import sampleDict
from ROOT import *
import json


gSystem.CompileMacro("mumu.C", "gOck")
gSystem.Load("mumu_C")

def makePlots(l_sampleDict, lumi, cutString, treeString):
  chain = TChain('{}/t'.format(tree))
  inFiles = []

  for path in l_sampleDict['path']:

    print "ok"
    prefix = ""
    filePrefix = ""
    if '/store/' in path:
      prefix = "eos root://cmseos.fnal.gov "
      filePrefix = "root://cmseos.fnal.gov/"

    print prefix+"ls -u "+path


    #files = ["zp2mu_histos_1.root","zp2mu_histos_10.root","zp2mu_histos_100.root","zp2mu_histos_101.root","zp2mu_histos_102.root","zp2mu_histos_103.root","zp2mu_histos_104.root","zp2mu_histos_105.root","zp2mu_histos_106.root","zp2mu_histos_107.root","zp2mu_histos_108.root","zp2mu_histos_109.root","zp2mu_histos_11.root","zp2mu_histos_111.root","zp2mu_histos_112.root","zp2mu_histos_113.root","zp2mu_histos_114.root","zp2mu_histos_115.root","zp2mu_histos_116.root","zp2mu_histos_117.root","zp2mu_histos_118.root","zp2mu_histos_119.root","zp2mu_histos_12.root","zp2mu_histos_120.root","zp2mu_histos_121.root","zp2mu_histos_122.root","zp2mu_histos_123.root","zp2mu_histos_124.root","zp2mu_histos_125.root","zp2mu_histos_126.root","zp2mu_histos_127.root","zp2mu_histos_128.root","zp2mu_histos_129.root","zp2mu_histos_13.root","zp2mu_histos_130.root","zp2mu_histos_131.root","zp2mu_histos_132.root","zp2mu_histos_133.root","zp2mu_histos_134.root","zp2mu_histos_135.root","zp2mu_histos_136.root","zp2mu_histos_137.root","zp2mu_histos_138.root","zp2mu_histos_139.root","zp2mu_histos_14.root","zp2mu_histos_140.root","zp2mu_histos_141.root","zp2mu_histos_142.root","zp2mu_histos_143.root","zp2mu_histos_144.root","zp2mu_histos_145.root","zp2mu_histos_146.root","zp2mu_histos_15.root","zp2mu_histos_16.root","zp2mu_histos_17.root","zp2mu_histos_18.root","zp2mu_histos_19.root","zp2mu_histos_2.root","zp2mu_histos_20.root","zp2mu_histos_21.root","zp2mu_histos_22.root","zp2mu_histos_23.root","zp2mu_histos_24.root","zp2mu_histos_26.root","zp2mu_histos_27.root","zp2mu_histos_28.root","zp2mu_histos_29.root","zp2mu_histos_3.root","zp2mu_histos_30.root","zp2mu_histos_31.root","zp2mu_histos_32.root","zp2mu_histos_33.root","zp2mu_histos_34.root","zp2mu_histos_35.root","zp2mu_histos_36.root","zp2mu_histos_37.root","zp2mu_histos_38.root","zp2mu_histos_39.root","zp2mu_histos_4.root","zp2mu_histos_40.root","zp2mu_histos_41.root","zp2mu_histos_42.root","zp2mu_histos_43.root","zp2mu_histos_44.root","zp2mu_histos_45.root","zp2mu_histos_47.root","zp2mu_histos_48.root","zp2mu_histos_49.root","zp2mu_histos_5.root","zp2mu_histos_50.root","zp2mu_histos_51.root","zp2mu_histos_52.root","zp2mu_histos_53.root","zp2mu_histos_54.root","zp2mu_histos_55.root","zp2mu_histos_56.root","zp2mu_histos_57.root","zp2mu_histos_58.root","zp2mu_histos_59.root","zp2mu_histos_6.root","zp2mu_histos_60.root","zp2mu_histos_61.root","zp2mu_histos_62.root","zp2mu_histos_63.root","zp2mu_histos_64.root","zp2mu_histos_65.root","zp2mu_histos_66.root","zp2mu_histos_67.root","zp2mu_histos_68.root","zp2mu_histos_69.root","zp2mu_histos_7.root","zp2mu_histos_70.root","zp2mu_histos_71.root","zp2mu_histos_72.root","zp2mu_histos_73.root","zp2mu_histos_74.root","zp2mu_histos_75.root","zp2mu_histos_76.root","zp2mu_histos_77.root","zp2mu_histos_78.root","zp2mu_histos_79.root","zp2mu_histos_8.root","zp2mu_histos_80.root","zp2mu_histos_81.root","zp2mu_histos_82.root","zp2mu_histos_83.root","zp2mu_histos_84.root","zp2mu_histos_85.root","zp2mu_histos_86.root","zp2mu_histos_87.root","zp2mu_histos_88.root","zp2mu_histos_89.root","zp2mu_histos_9.root","zp2mu_histos_90.root","zp2mu_histos_91.root","zp2mu_histos_92.root","zp2mu_histos_93.root","zp2mu_histos_94.root","zp2mu_histos_95.root","zp2mu_histos_96.root","zp2mu_histos_98.root"]


    for inFile in filter(None,popen(prefix+"ls -u "+path).read().split('\n')):
      print "infile", inFile
      if ".root" in inFile and ".root" not in path:
        pathString = path  + inFile
      elif ".root" in path:
        pathString = path
      else:
        continue

      chain.Add(filePrefix+pathString)


  instance = mumu(chain)

  if not exists("output"):
    mkdir("output")
  cutFlow = instance.Loop("output/{0}_{2}_{1}".format(cutString,l_sampleDict['outName'],treeString),l_sampleDict['xsection'],lumi,l_sampleDict['totalEvents'], cutString)#
  #return [cutFlow[0],cutFlow[1],cutFlow[2],cutFlow[3],cutFlow[4],cutFlow[5],cutFlow[6],cutFlow[7]]


cutStrings = [
"b=1_j=0",
"b=1,2_b+j=2",
"b=0_b+j=2",
"b=0_j=1"
]


#treeName = ["SimpleNtuplerDiEle","SimpleNtupler", ""]
treeName = ["SimpleNtupler"]

#treeName = ["SimpleNtuplerEmu"]
#treeName = ["SimpleNtuplerDiEle"]

cutFlow = {}

for cutString in cutStrings:
  cutFlow[cutString] = {}
  for tree in treeName:
    cutFlow[cutString][tree] = {}
    for sample in sampleDict:
      print sample, tree, sampleDict[sample]['outName']
      #cutFlow[cutString][tree][sample] = makePlots(sampleDict[sample], 35.9, cutString, tree)
      makePlots(sampleDict[sample], 35.9, cutString, tree)

with open('cutflow.json','w') as fp:
  json.dump(cutFlow, fp, indent=4)

