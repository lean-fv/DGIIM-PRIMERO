<Qucs Schematic 0.0.19>
<Properties>
  <View=-53,-169,1013,738,1,14,88>
  <Grid=10,10,1>
  <DataSet=Practica 3.1 FernandezVLJ.dat>
  <DataDisplay=Practica 3.1 FernandezVLJ.dpl>
  <OpenDisplay=1>
  <Script=Practica 3.1 FernandezVLJ.m>
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
  <GND * 1 280 70 0 0 0 0>
  <C C1 1 360 40 17 -26 0 1 "10 uF" 1 "0" 0 "neutral" 0>
  <Vac V1 1 200 30 18 -26 0 1 "10 V" 1 "1 GHz" 0 "0" 0 "0" 0>
  <.AC AC1 1 370 -140 0 33 0 0 "log" 1 "1 mHz" 1 "1 GHz" 1 "100" 1 "no" 0>
  <R R1 1 260 -30 -26 15 0 0 "1 kOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <VProbe Vc 1 510 -10 28 -31 0 0>
  <Eqn Eqn1 1 570 -130 -23 13 0 0 "T=Vc.v/Vin.v" 1 "TdB=dB(T)" 1 "yes" 0>
  <Eqn Eqn2 1 660 -130 -23 13 0 0 "Ph=phase (Vc.v/Vin.v)" 1 "PhRad=Ph*3.1416/180" 1 "yes" 0>
  <VProbe Vin 1 70 -20 -45 -31 1 2>
</Components>
<Wires>
  <280 70 360 70 "" 0 0 0 "">
  <200 60 200 70 "" 0 0 0 "">
  <200 70 280 70 "" 0 0 0 "">
  <360 -30 360 10 "" 0 0 0 "">
  <290 -30 360 -30 "" 0 0 0 "">
  <200 -30 200 0 "" 0 0 0 "">
  <200 -30 230 -30 "" 0 0 0 "">
  <360 70 520 70 "" 0 0 0 "">
  <520 10 520 70 "" 0 0 0 "">
  <360 10 500 10 "" 0 0 0 "">
  <80 0 200 0 "" 0 0 0 "">
  <60 60 200 60 "" 0 0 0 "">
  <60 0 60 60 "" 0 0 0 "">
</Wires>
<Diagrams>
  <Rect 15 417 341 259 3 #c0c0c0 1 10 1 0 200 1000 1 -40 20 3.59647 1 -1 1 1 315 0 225 "" "" "">
	<"TdB" #0000ff 0 3 0 0 0>
	  <Mkr 7.56463 170 -296 3 0 0>
	  <Mkr 7.56463 170 -296 3 0 0>
  </Rect>
  <Rect 439 424 350 263 3 #c0c0c0 1 10 1 0 200 1000 1 1.43123 1 3.29702 1 -1 1 1 315 0 225 "" "" "">
	<"PhRad" #0000ff 0 3 0 0 0>
	  <Mkr 100000 293 -82 3 0 0>
	  <Mkr 0.811131 145 -294 3 0 0>
  </Rect>
</Diagrams>
<Paintings>
</Paintings>
