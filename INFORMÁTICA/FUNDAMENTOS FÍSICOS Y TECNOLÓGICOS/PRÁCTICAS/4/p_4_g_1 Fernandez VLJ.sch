<Qucs Schematic 0.0.19>
<Properties>
  <View=0,-170,929,1511,1,0,1110>
  <Grid=10,10,1>
  <DataSet=p_4_g_1 Fernandez VLJ.dat>
  <DataDisplay=p_4_g_1 Fernandez VLJ.dpl>
  <OpenDisplay=1>
  <Script=p_4_g_1 Fernandez VLJ.m>
  <RunScript=0>
  <showFrame=0>
  <FrameText0=Title>
  <FrameText1=Drawn By:>
  <FrameText2=Date:>
  <FrameText3=Revision:>
</Properties>
<Symbol>
</Symbol>
<Components>
  <Vdc V1 1 210 300 18 -26 0 1 "2.5 V" 1>
  <Diode D1 1 380 280 15 -26 0 1 "1e-15 A" 1 "1" 1 "10 fF" 1 "0.5" 0 "0.7 V" 0 "0.5" 0 "0.0 fF" 0 "0.0" 0 "2.0" 0 "0.0 Ohm" 0 "0.0 ps" 0 "0" 0 "0.0" 0 "1.0" 0 "1.0" 0 "0" 0 "1 mA" 0 "26.85" 0 "3.0" 0 "1.11" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "26.85" 0 "1.0" 0 "normal" 0>
  <VProbe Vd 1 520 270 -16 28 0 3>
  <.DC DC1 1 430 90 0 33 0 0 "26.85" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "no" 0 "150" 0 "no" 0 "none" 0 "CroutLU" 0>
  <GND * 1 280 330 0 0 0 0>
  <VProbe Vr 1 320 90 28 -31 0 0>
  <R R1 1 320 170 -26 15 0 0 "1 kOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "US" 0>
  <IProbe Pr1 1 380 200 -35 -26 0 3>
  <_MOSFET T1 1 430 820 8 -26 0 0 "nfet" 0 "1.0 V" 1 "2e-5" 1 "0.0" 0 "0.6 V" 0 "0.0" 1 "0.0 Ohm" 0 "0.0 Ohm" 0 "0.0 Ohm" 0 "1e-14 A" 0 "1.0" 0 "1 um" 0 "1 um" 0 "0.0" 0 "0.1 um" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0 F" 0 "0.0 F" 0 "0.8 V" 0 "0.5" 0 "0.5" 0 "0.0" 0 "0.33" 0 "0.0 ps" 0 "0.0" 0 "0.0" 0 "1" 0 "600.0" 0 "0.0" 0 "1" 0 "1" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0 m" 0 "0.0 m" 0 "0.0" 0 "1.0" 0 "1.0" 0 "26.85" 0 "26.85" 0>
  <GND * 1 430 890 0 0 0 0>
  <R RG 1 330 820 -26 15 0 0 "50 kOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "US" 0>
  <GND * 1 430 550 0 0 0 2>
  <R RD 1 430 640 15 -26 0 1 "50 kOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "US" 0>
  <IProbe IG 1 260 820 -26 16 0 0>
  <VProbe VDS 1 570 830 -16 28 0 3>
  <Vdc V2 1 140 850 18 -26 0 1 "10 V" 1>
  <GND * 1 140 890 0 0 0 0>
  <Vdc VDD 1 430 580 -68 -14 0 3 "10 V" 1>
  <VProbe VGS 1 300 920 22 -16 1 0>
  <_MOSFET T2 1 460 1370 8 -26 0 0 "nfet" 0 "1.0 V" 1 "2e-5" 1 "0.0" 0 "0.6 V" 0 "0.0" 1 "0.0 Ohm" 0 "0.0 Ohm" 0 "0.0 Ohm" 0 "1e-14 A" 0 "1.0" 0 "1 um" 0 "1 um" 0 "0.0" 0 "0.1 um" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0 F" 0 "0.0 F" 0 "0.8 V" 0 "0.5" 0 "0.5" 0 "0.0" 0 "0.33" 0 "0.0 ps" 0 "0.0" 0 "0.0" 0 "1" 0 "600.0" 0 "0.0" 0 "1" 0 "1" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0 m" 0 "0.0 m" 0 "0.0" 0 "1.0" 0 "1.0" 0 "26.85" 0 "26.85" 0>
  <GND * 1 460 1440 0 0 0 0>
  <GND * 1 460 1100 0 0 0 2>
  <R RD1 1 460 1190 15 -26 0 1 "50 kOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "US" 0>
  <VProbe VDS1 1 600 1380 -16 28 0 3>
  <Vdc Vi 1 460 1130 -68 -14 0 3 "8 V" 1>
  <IProbe ID 1 430 730 -35 -26 0 3>
  <IProbe ID1 1 460 1270 -35 -26 0 3>
</Components>
<Wires>
  <210 330 280 330 "" 0 0 0 "">
  <380 310 380 330 "" 0 0 0 "">
  <500 250 500 260 "" 0 0 0 "">
  <380 250 500 250 "" 0 0 0 "">
  <380 310 500 310 "" 0 0 0 "">
  <500 280 500 310 "" 0 0 0 "">
  <210 170 210 270 "" 0 0 0 "">
  <290 110 310 110 "" 0 0 0 "">
  <290 110 290 170 "" 0 0 0 "">
  <330 110 350 110 "" 0 0 0 "">
  <350 110 350 170 "" 0 0 0 "">
  <210 170 290 170 "" 0 0 0 "">
  <280 330 380 330 "" 0 0 0 "">
  <380 230 380 240 "" 0 0 0 "">
  <380 240 380 250 "" 0 0 0 "">
  <350 170 380 170 "" 0 0 0 "">
  <430 850 430 870 "" 0 0 0 "">
  <290 820 300 820 "" 0 0 0 "">
  <360 820 400 820 "" 0 0 0 "">
  <550 790 550 820 "" 0 0 0 "">
  <430 790 550 790 "" 0 0 0 "">
  <550 840 550 850 "" 0 0 0 "">
  <430 850 550 850 "" 0 0 0 "">
  <210 900 290 900 "" 0 0 0 "">
  <210 820 230 820 "" 0 0 0 "">
  <210 820 210 900 "" 0 0 0 "">
  <310 870 310 900 "" 0 0 0 "">
  <430 870 430 890 "" 0 0 0 "">
  <310 870 430 870 "" 0 0 0 "">
  <140 820 210 820 "" 0 0 0 "">
  <140 880 140 890 "" 0 0 0 "">
  <580 1340 580 1370 "" 0 0 0 "">
  <460 1340 580 1340 "" 0 0 0 "">
  <580 1390 580 1400 "" 0 0 0 "">
  <460 1400 580 1400 "" 0 0 0 "">
  <460 1400 460 1440 "" 0 0 0 "">
  <430 1320 430 1370 "" 0 0 0 "">
  <460 1320 460 1340 "" 0 0 0 "">
  <430 1320 460 1320 "" 0 0 0 "">
  <430 760 430 790 "" 0 0 0 "">
  <430 670 430 700 "" 0 0 0 "">
  <460 1300 460 1320 "" 0 0 0 "">
  <460 1220 460 1240 "" 0 0 0 "">
</Wires>
<Diagrams>
  <Tab 70 50 300 200 3 #c0c0c0 1 00 1 0 1 1 1 0 1 1 1 0 1 1 315 0 225 "" "" "">
	<"Vr.V" #0000ff 0 3 0 0 0>
	<"Vd.V" #0000ff 0 3 0 0 0>
	<"Pr1.I" #0000ff 0 3 0 0 0>
  </Tab>
  <Tab 30 580 300 200 3 #c0c0c0 1 00 1 0 1 1 1 0 1 1 1 0 1 1 315 0 225 "" "" "">
	<"VDS.V" #0000ff 0 3 1 0 0>
	<"VGS.V" #0000ff 0 3 1 0 0>
	<"ID.I" #0000ff 0 3 1 0 0>
	<"IG.I" #0000ff 0 3 1 0 0>
  </Tab>
  <Tab 50 1240 300 200 3 #c0c0c0 1 00 1 0 1 1 1 0 1 1 1 0 1 1 315 0 225 "" "" "">
	<"ID1.I" #0000ff 0 3 1 0 0>
	<"VDS1.V" #0000ff 0 3 1 0 0>
  </Tab>
</Diagrams>
<Paintings>
</Paintings>
