#!/bin/bash

python runTrees.py -i /afs/cern.ch/work/h/hyeahyun/public/background/ZZ_TuneCUETP8M1_13TeV-pythia8/180802_085945/0000/ -t SimpleNtupler/t -o ZZ_TuneCUETP8M1_13TeV-pythia8.root
python runTrees.py -i /afs/cern.ch/work/h/hyeahyun/public/background/TTTo2L2Nu_TuneCUETP8M2_ttHtranche3_13TeV-powheg-pythia8/180802_083858/0000/ -t SimpleNtupler/t -o TTTo2L2Nu_TuneCUETP8M2_ttHtranche3_13TeV-powheg.root
python runTrees.py -i /afs/cern.ch/work/h/hyeahyun/public/background/TTTo2L2Nu_TuneCUETP8M2_ttHtranche3_13TeV-powheg-pythia8/180802_083858/0001/ -t SimpleNtupler/t -o TTTo2L2Nu_TuneCUETP8M2_ttHtranche3_13TeV-powheg_1.root
python runTrees.py -i /afs/cern.ch/work/h/hyeahyun/public/background/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/180802_083321/0000/ -t SimpleNtupler/t -o DYJetsToLL_M-50_TuneCUETP8M1_13TeV.root
python runTrees.py -i /afs/cern.ch/work/h/hyeahyun/public/background/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/180802_083321/0001/ -t SimpleNtupler/t -o DYJetsToLL_M-50_TuneCUETP8M1_13TeV_1.root
python runTrees.py -i /afs/cern.ch/work/h/hyeahyun/public/background/WWTo2L2Nu_13TeV-powheg/180802_085237/0000/ -t SimpleNtupler/t -o WWTo2L2Nu_13TeV-powheg.root
python runTrees.py -i /afs/cern.ch/work/h/hyeahyun/public/background/ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/180802_084720/0000/ -t SimpleNtupler/t -o ST_tW_top_5f_inclusiveDecays_13TeV-powheg.root
python runTrees.py -i /afs/cern.ch/work/h/hyeahyun/public/background/ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/180802_084322/0000/ -t SimpleNtupler/t -o ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg.root
python runTrees.py -i /afs/cern.ch/work/h/hyeahyun/public/background/WZ_TuneCUETP8M1_13TeV-pythia8/180802_085635/0000/ -t SimpleNtupler/t -o WZ_TuneCUETP8M1_13TeV-pythia8.root


python runTrees.py -i  /afs/cern.ch/work/h/hyeahyun/public/signal/zp200.root -t SimpleNtupler/t -o zp200.root
python runTrees.py -i  /afs/cern.ch/work/h/hyeahyun/public/signal/zp350.root -t SimpleNtupler/t -o zp350.root
python runTrees.py -i  /afs/cern.ch/work/h/hyeahyun/public/signal/zp500.root -t SimpleNtupler/t -o zp500.root