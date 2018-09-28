import json


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
            print cutflow[cut][ttree][sample]
            if sample in backgrounds:
                ABCD[cut][ttree][0] = ABCD[cut][ttree][0] +  cutflow[cut][ttree][sample][3]
            else:
                if sample == "zp200":
                    ABCD[cut][ttree][1] = ABCD[cut][ttree][1] +  cutflow[cut][ttree][sample][3]
                if sample == "zp500":
                    ABCD[cut][ttree][2] = ABCD[cut][ttree][2] +  cutflow[cut][ttree][sample][3]
                if sample == "zp500":
                    ABCD[cut][ttree][3] = ABCD[cut][ttree][3] +  cutflow[cut][ttree][sample][3]


print "background"
print "ttree\t", cuts[0], "\t", cuts[1], "\t", cuts[2]

for ttree in ABCD[cuts[0]]:
    print ttree,"\t", ABCD[cuts[0]][ttree][0], "\t", ABCD[cuts[1]][ttree][0], "\t", ABCD[cuts[2]][ttree][0]

print "zp200"
print "ttree\t", cuts[0], "\t", cuts[1], "\t", cuts[2]

for ttree in ABCD[cuts[0]]:
    print ttree,"\t", ABCD[cuts[0]][ttree][1], "\t", ABCD[cuts[1]][ttree][1], "\t", ABCD[cuts[2]][ttree][1]

print "zp350"
print "ttree\t", cuts[0], "\t", cuts[1], "\t", cuts[2]

for ttree in ABCD[cuts[0]]:
    print ttree,"\t", ABCD[cuts[0]][ttree][2], "\t", ABCD[cuts[1]][ttree][2], "\t", ABCD[cuts[2]][ttree][2]

print "zp500"
print "ttree\t", cuts[0], "\t", cuts[1], "\t", cuts[2]

for ttree in ABCD[cuts[0]]:
    print ttree,"\t", ABCD[cuts[0]][ttree][3], "\t", ABCD[cuts[1]][ttree][3], "\t", ABCD[cuts[2]][ttree][3]

