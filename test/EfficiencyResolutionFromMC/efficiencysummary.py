from SUSYBSMAnalysis.Zprime2muAnalysis.roottools import *
set_zp2mu_style()

ps = plot_saver('plots/ourvsvbtfeff')
cname = 'c0'

################################################################################

acc_f = ROOT.TFile('plots/trigeffvsmassmctruth/Acceptance_totals.root')
acc21_f = ROOT.TFile('plots/trigeffvsmassmctruth_vbtf/Acceptance_totals.root')

acc = acc_f.Get(cname).FindObject('Graph')
acc21 = acc21_f.Get(cname).FindObject('Graph')

acc.SetLineColor(ROOT.kRed)
acc21.SetLineColor(ROOT.kBlue)
acc.SetTitle('')
acc.GetXaxis().SetTitle('vector boson pole mass (GeV)')
acc.GetYaxis().SetTitle('acceptance')
acc.GetYaxis().SetTitleOffset(1.2)
acc.GetYaxis().SetRangeUser(0.18, 0.96)
for i,h in enumerate([acc, acc21]):
    h.SetMarkerStyle(20+i)
    h.SetMarkerSize(0.9)
    h.SetMarkerColor(h.GetLineColor())

ps.c.cd()
acc.Draw('APL')
acc21.Draw('PL same')

lg = ROOT.TLegend(0.38, 0.143, 0.86, 0.316)
lg.AddEntry(acc,   'both muons | #eta| < 2.4, p_{T} > 35 GeV', 'LPE')
lg.AddEntry(acc21, 'both muons | #eta| < 2.1, p_{T} > 35 GeV', 'LPE')
lg.Draw()

ps.save('Acceptance', log=False)

################################################################################

our_f = ROOT.TFile('plots/trigeffvsmassmctruth/RecoWrtAcc_totals.root')
vbtf_f = ROOT.TFile('plots/trigeffvsmassmctruth_vbtf/RecoWrtAcc_totals.root')

our = our_f.Get(cname).FindObject('Graph')
vbtf = vbtf_f.Get(cname).FindObject('Graph')

ox,oy,vx,vy = ROOT.Double(),ROOT.Double(),ROOT.Double(),ROOT.Double()
ratio = our.Clone('ratio')
print '%10s%10s%10s%10s' % ('pole mass', 'our', 'vbtf', 'ratio')
for i in xrange(our.GetN()):
    our.GetPoint(i, ox, oy)
    vbtf.GetPoint(i, vx, vy)
    print '%10i%10.3f%10.3f%10.3f' % (int(ox), oy, vy, vy/oy)
    ratio.SetPoint(i, ox, vy/oy)

our.SetTitle('')
our.GetXaxis().SetTitle('vector boson pole mass (GeV)')
our.GetYaxis().SetTitle('trigger+reco+selection efficiency wrt acceptance')
our.GetYaxis().SetTitleOffset(1.2)
our.GetYaxis().SetRangeUser(0.855, 1)

our.SetLineColor(ROOT.kRed)
vbtf.SetLineColor(ROOT.kBlue)
ratio.SetLineColor(ROOT.kGreen+2)

for i,h in enumerate([our,vbtf,ratio]):
    h.SetMarkerStyle(20+i)
    h.SetMarkerSize(0.9)
    h.SetMarkerColor(h.GetLineColor())

ps.c.cd()
our.Draw('APL')
vbtf.Draw('PL same')
ratio.Draw('PL same')

lg = ROOT.TLegend(0.20, 0.13, 0.86, 0.29)
lg.AddEntry(our,   'efficiency w/ Our selection (acc:   #left|#eta#right| < 2.4, p_{T} > 35 GeV)', 'LPE')
lg.AddEntry(vbtf,  'efficiency w/ VBTF selection (acc:   #left|#eta#right| < 2.1, p_{T} > 35 GeV)', 'LPE')
lg.AddEntry(ratio, 'ratio VBTF/Ours', 'LPE')
lg.Draw()

ps.save('RecoWrtAcc', log=False)

################################################################################

def get_z0(g):
    g.GetPoint(0, ox, oy)
    assert(abs(ox - 90.5) < 0.1)
    return float(oy)
our_z0 = get_z0(our)
vbtf_z0 = get_z0(vbtf)

our_ratio_to_z0 = our.Clone('our_ratio_to_z0')
vbtf_ratio_to_z0 = our.Clone('vbtf_ratio_to_z0')
for i in xrange(our.GetN()):
    our.GetPoint(i, ox, oy)
    vbtf.GetPoint(i, vx, vy)
    our_ratio_to_z0.SetPoint(i, ox, our_z0/oy)
    vbtf_ratio_to_z0.SetPoint(i, vx, vbtf_z0/vy)
    if i != 0:
        pass # ignore correct errors for now
for h in [our_ratio_to_z0, our_ratio_to_z0]:
    h.SetPointEYlow(0,0)
    h.SetPointEYhigh(0,0)

our_ratio_to_z0.SetLineColor(ROOT.kRed)
vbtf_ratio_to_z0.SetLineColor(ROOT.kBlue)

for i,h in enumerate([our_ratio_to_z0, vbtf_ratio_to_z0]):
    h.SetMarkerStyle(20+i)
    h.SetMarkerSize(0.9)
    h.SetMarkerColor(h.GetLineColor())

our_ratio_to_z0.GetXaxis().SetTitle('vector boson pole mass (GeV)')
our_ratio_to_z0.GetYaxis().SetTitle("ratio efficiency(Z0)/efficiency(Z')")
our_ratio_to_z0.GetYaxis().SetTitleOffset(1.3)
our_ratio_to_z0.GetYaxis().SetRangeUser(0.99, 1.015)
our_ratio_to_z0.Draw('APL')
vbtf_ratio_to_z0.Draw('PL same')

lg = ROOT.TLegend(0.55, 0.14, 0.87, 0.27)
lg.AddEntry(our_ratio_to_z0,  'Our selection', 'LPE')
lg.AddEntry(vbtf_ratio_to_z0, 'VBTF selection', 'LPE')
lg.Draw()

ps.save('LowToHighMass', log=False)
