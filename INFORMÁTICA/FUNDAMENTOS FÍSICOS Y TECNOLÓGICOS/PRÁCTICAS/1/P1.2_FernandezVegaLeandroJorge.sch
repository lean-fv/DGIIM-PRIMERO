<Qucs Schematic 0.0.19>
<Properties>
  <View=0,-411,800,355,1,0,0>
  <Grid=10,10,1>
  <DataSet=P1.2_FernandezVegaLeandroJorge.dat>
  <DataDisplay=P1.2_FernandezVegaLeandroJorge.dpl>
  <OpenDisplay=1>
  <Script=P1.2_FernandezVegaLeandroJorge.m>
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
  <Idc I1 1 150 150 18 -26 0 1 "10 mA" 1>
  <IProbe Pr4 1 410 10 -26 16 0 0>
  <IProbe Pr5 1 410 210 -26 16 0 0>
  <VProbe Pr2 1 350 140 28 -31 0 0>
  <VProbe Pr3 1 350 -60 28 -31 0 0>
  <.DC DC1 1 500 40 0 33 0 0 "26.85" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "no" 0 "150" 0 "no" 0 "none" 0 "CroutLU" 0>
  <GND * 1 350 310 0 0 0 0>
  <R R1 1 350 10 -26 15 0 0 "2200 Ohm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "US" 0>
  <R R2 1 350 210 -26 15 0 0 "4700 Ohm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "US" 0>
</Components>
<Wires>
  <260 120 260 210 "" 0 0 0 "">
  <260 210 320 210 "" 0 0 0 "">
  <440 120 440 210 "" 0 0 0 "">
  <440 120 570 120 "" 0 0 0 "">
  <570 120 570 310 "" 0 0 0 "">
  <150 310 350 310 "" 0 0 0 "">
  <150 180 150 310 "" 0 0 0 "">
  <150 120 260 120 "" 0 0 0 "">
  <440 10 440 120 "" 0 0 0 "">
  <260 10 260 120 "" 0 0 0 "">
  <260 10 320 10 "" 0 0 0 "">
  <320 -40 340 -40 "" 0 0 0 "">
  <320 -40 320 10 "" 0 0 0 "">
  <360 -40 380 -40 "" 0 0 0 "">
  <380 -40 380 10 "" 0 0 0 "">
  <320 160 340 160 "" 0 0 0 "">
  <320 160 320 210 "" 0 0 0 "">
  <360 160 380 160 "" 0 0 0 "">
  <380 160 380 210 "" 0 0 0 "">
  <350 310 570 310 "" 0 0 0 "">
</Wires>
<Diagrams>
  <Time 60 -120 300 200 3 #c0c0c0 1 00 1 0 1 1 1 0 1 1 1 0 1 1 315 0 225 "" "" "">
	<"Pr2.V" #0000ff 0 3 0 0 0>
	<"Pr3.V" #ff0000 0 3 0 0 0>
	<"Pr4.I" #ff00ff 0 3 0 0 0>
	<"Pr5.I" #00ff00 0 3 0 0 0>
  </Time>
</Diagrams>
<Paintings>
</Paintings>
