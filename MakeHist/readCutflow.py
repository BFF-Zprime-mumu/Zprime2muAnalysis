import json
import numpy as np


with open('cutflow.json', 'r') as fp:
    cutflow = json.load(fp)

backgrounds = [
"WWTo2L2Nu_13TeV",
"ST_tW_antitop_5f_inclusiveDecays_13TeV",
"TTTo2L2Nu_TuneCUETP8M2_ttHtranche3_13TeV",
"ST_tW_top_5f_inclusiveDecays_13TeV",
"WZ_TuneCUETP8M1_13TeV",
"ZZ_TuneCUETP8M1_13TeV",
"DYJetsToLL_M",
]

ABCD = {}
cuts = []
ttrees = []

for cut in cutflow:
    cuts.append(cut)
    ABCD[cut] = {}
    for ttree in cutflow[cut]:
        ttrees.append(ttree)
        ABCD[cut][ttree] = [0,0,0,0]
        for sample in cutflow[cut][ttree]:
            #print cutflow[cut][ttree][sample]
            if sample in backgrounds:
                ABCD[cut][ttree][0] = ABCD[cut][ttree][0] +  cutflow[cut][ttree][sample][3]
            else:
                if sample == "zp200":
                    ABCD[cut][ttree][1] = ABCD[cut][ttree][1] +  cutflow[cut][ttree][sample][3]
                if sample == "zp500":
                    ABCD[cut][ttree][2] = ABCD[cut][ttree][2] +  cutflow[cut][ttree][sample][3]
                if sample == "zp500":
                    ABCD[cut][ttree][3] = ABCD[cut][ttree][3] +  cutflow[cut][ttree][sample][3]

for ttree in ttrees:
    for cut in cuts:
        if cut == "2": continue
        print cut, ttree

        cutFlowTable = []

        for sample in cutflow[cut][ttree]:

            l_cutflow = cutflow[cut][ttree][sample]
            nEvents = l_cutflow[0]
            #print cut, ttree, sample
            if nEvents !=0: 
                nEvents = 1
                cutFlowTable.append([ sample, l_cutflow[0]/nEvents, l_cutflow[1]/nEvents, l_cutflow[2]/nEvents, l_cutflow[3]/nEvents])
        cutFlowTable = sorted(cutFlowTable, key= lambda cutFlowTable: cutFlowTable[0])
        for cutflowRow in  cutFlowTable:
            print cutflowRow[0], ",\t", cutflowRow[1], cutflowRow[1]/cutflowRow[1], ",\t", cutflowRow[2], cutflowRow[2]/cutflowRow[1], ",\t", cutflowRow[3], cutflowRow[3]/cutflowRow[1], ",\t", cutflowRow[4], cutflowRow[4]/cutflowRow[1]

