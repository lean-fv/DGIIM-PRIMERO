<Qucs Schematic 0.0.19>
<Properties>
  <View=126,-166,809,410,1,0,0>
  <Grid=10,10,1>
  <DataSet=practica1.dat>
  <DataDisplay=practica1.dpl>
  <OpenDisplay=1>
  <Script=practica1.m>
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
  <VProbe Pr2 1 340 140 28 -31 0 0>
  <Vdc V1 1 180 240 18 -26 0 1 "10 V" 1>
  <VProbe Pr3 1 700 250 28 -31 0 0>
  <GND * 1 370 360 0 0 0 0>
  <R R1 1 340 210 -26 15 0 0 "2200 Ohm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "US" 0>
  <R R2 1 570 270 15 -26 0 1 "4700 Ohm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "US" 0>
  <.DC DC1 1 480 120 0 33 0 0 "26.85" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "no" 0 "150" 0 "no" 0 "none" 0 "CroutLU" 0>
  <IProbe Pr1 1 240 210 -26 16 0 0>
</Components>
<Wires>
  <370 210 570 210 "" 0 0 0 "">
  <180 270 180 340 "" 0 0 0 "">
  <570 210 570 240 "" 0 0 0 "">
  <180 340 370 340 "" 0 0 0 "">
  <570 300 570 340 "" 0 0 0 "">
  <640 270 690 270 "" 0 0 0 "">
  <640 240 640 270 "" 0 0 0 "">
  <570 240 640 240 "" 0 0 0 "">
  <710 270 710 300 "" 0 0 0 "">
  <570 300 710 300 "" 0 0 0 "">
  <370 160 370 210 "" 0 0 0 "">
  <350 160 370 160 "" 0 0 0 "">
  <310 160 310 210 "" 0 0 0 "">
  <310 160 330 160 "" 0 0 0 "">
  <370 340 570 340 "" 0 0 0 "">
  <370 340 370 360 "" 0 0 0 "">
  <270 210 310 210 "" 0 0 0 "">
  <180 210 210 210 "" 0 0 0 "">
</Wires>
<Diagrams>
  <Time 250 60 300 200 3 #c0c0c0 1 00 1 0 1 1 1 0 1 1 1 0 1 1 315 0 225 "" "" "">
	<"Pr1.I" #00ffff 0 3 0 0 0>
	<"Pr2.V" #ffff00 0 3 0 0 0>
	<"Pr3.V" #777777 0 3 0 0 0>
	<"V1.I" #00ff00 0 3 0 0 0>
  </Time>
</Diagrams>
<Paintings>
</Paintings>
