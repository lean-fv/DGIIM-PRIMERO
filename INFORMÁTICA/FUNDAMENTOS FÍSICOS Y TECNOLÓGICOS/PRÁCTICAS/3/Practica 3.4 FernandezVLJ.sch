<Qucs Schematic 0.0.19>
<Properties>
  <View=0,151,920,1021,1,0,198>
  <Grid=10,10,1>
  <DataSet=Practica 3.4 FernandezVLJ.dat>
  <DataDisplay=Practica 3.4 FernandezVLJ.dpl>
  <OpenDisplay=1>
  <Script=Practica 3.4 FernandezVLJ.m>
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
  <.AC AC1 1 450 180 0 33 0 0 "log" 1 "1 mHz" 1 "1 GHz" 1 "100" 1 "no" 0>
  <GND * 1 230 450 0 0 0 0>
  <L L1 1 370 390 -26 10 0 0 "3.183 mH" 1 "" 0>
  <Vac V1 1 180 380 18 -26 0 1 "10 V" 1 "1 GHz" 0 "0" 0 "0" 0>
  <R R1 1 280 330 -26 -39 1 0 "1 kOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <VProbe Vc 1 630 380 -16 28 0 3>
  <Eqn Eqn1 1 640 190 -23 13 0 0 "T=Vc.v/Vin.v" 1 "TdB=dB(T)" 1 "yes" 0>
  <Eqn Eqn2 1 730 190 -23 13 0 0 "Ph=phase (Vc.v/Vin.v)" 1 "PhRad=Ph*3.1416/180" 1 "yes" 0>
  <C C1 1 470 380 17 -26 0 1 "79.5 nF" 1 "0" 0 "neutral" 0>
  <VProbe Vin 1 70 330 -45 -31 1 2>
</Components>
<Wires>
  <310 330 340 330 "" 0 0 0 "">
  <230 450 400 450 "" 0 0 0 "">
  <340 330 340 390 "" 0 0 0 "">
  <400 390 400 450 "" 0 0 0 "">
  <470 330 470 350 "" 0 0 0 "">
  <340 330 470 330 "" 0 0 0 "">
  <400 450 470 450 "" 0 0 0 "">
  <470 410 470 450 "" 0 0 0 "">
  <180 450 230 450 "" 0 0 0 "">
  <180 410 180 450 "" 0 0 0 "">
  <180 330 180 350 "" 0 0 0 "">
  <180 330 250 330 "" 0 0 0 "">
  <610 350 610 370 "" 0 0 0 "">
  <470 350 610 350 "" 0 0 0 "">
  <610 390 610 410 "" 0 0 0 "">
  <470 410 610 410 "" 0 0 0 "">
  <80 350 180 350 "" 0 0 0 "">
  <60 350 60 410 "" 0 0 0 "">
  <60 410 180 410 "" 0 0 0 "">
</Wires>
<Diagrams>
  <Rect 82 749 298 219 3 #c0c0c0 1 10 1 0 2000 10000 1 -169.378 100 15.3978 1 -1 1 1 315 0 225 "" "" "">
	<"TdB" #0000ff 0 3 0 0 0>
	  <Mkr 10722.7 235 -261 3 0 0>
  </Rect>
  <Rect 420 756 472 226 3 #c0c0c0 1 10 0 100 1 1e+06 1 -2 1 2 1 -1 0.5 1 315 0 225 "" "" "">
	<"PhRad" #0000ff 0 3 0 0 0>
	  <Mkr 3511.19 297 -197 3 0 0>
	  <Mkr 32745.5 300 35 3 0 0>
  </Rect>
</Diagrams>
<Paintings>
</Paintings>
