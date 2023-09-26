<Qucs Schematic 0.0.19>
<Properties>
  <View=-53,-59,849,662,1,0,150>
  <Grid=10,10,1>
  <DataSet=Practica 3.2.2 FernandezVLJ.dat>
  <DataDisplay=Practica 3.2.2 FernandezVLJ.dpl>
  <OpenDisplay=1>
  <Script=Practica 3.2.2 FernandezVLJ.m>
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
  <GND * 1 330 260 0 0 0 0>
  <C C1 1 410 230 17 -26 0 1 "10 uF" 1 "0" 0 "neutral" 0>
  <Vac V1 1 250 220 18 -26 0 1 "10 V" 1 "1 GHz" 0 "0" 0 "0" 0>
  <R R1 1 310 160 -26 15 0 0 "1 kOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <VProbe Vc1 1 310 90 28 -31 0 0>
  <.AC AC1 1 430 -30 0 33 0 0 "log" 1 "1 mHz" 1 "1 GHz" 1 "100" 1 "no" 0>
  <Eqn Eqn1 1 610 -20 -23 13 0 0 "T=Vc1.v/Vin1.v" 1 "TdB=dB(T)" 1 "yes" 0>
  <Eqn Eqn2 1 700 -20 -23 13 0 0 "Ph=phase (Vc1.v/Vin1.v)" 1 "PhRad=Ph*3.1416/180" 1 "yes" 0>
  <VProbe Vin1 1 120 170 -52 -31 1 2>
</Components>
<Wires>
  <330 260 410 260 "" 0 0 0 "">
  <250 250 250 260 "" 0 0 0 "">
  <250 260 330 260 "" 0 0 0 "">
  <410 160 410 200 "" 0 0 0 "">
  <340 160 410 160 "" 0 0 0 "">
  <250 160 250 190 "" 0 0 0 "">
  <250 160 280 160 "" 0 0 0 "">
  <130 190 250 190 "" 0 0 0 "">
  <110 250 250 250 "" 0 0 0 "">
  <110 190 110 250 "" 0 0 0 "">
  <280 110 300 110 "" 0 0 0 "">
  <280 110 280 160 "" 0 0 0 "">
  <320 110 340 110 "" 0 0 0 "">
  <340 110 340 160 "" 0 0 0 "">
</Wires>
<Diagrams>
  <Rect 37 510 313 161 3 #c0c0c0 1 10 1 0 2e+08 1e+09 1 -100 50 8.40364 1 -1 1 1 315 0 225 "" "" "">
	<"TdB" #0000ff 0 3 0 0 0>
	  <Mkr 53.367 183 -208 3 0 0>
  </Rect>
  <Rect 430 520 358 164 3 #c0c0c0 1 10 1 0 2e+08 1e+09 1 -3.29867 1 -1.41379 1 -1 1 1 315 0 225 "" "" "">
	<"PhRad" #0000ff 0 3 0 0 0>
	  <Mkr 0.811131 147 -206 3 0 0>
	  <Mkr 123.285 212 -85 3 0 0>
  </Rect>
</Diagrams>
<Paintings>
</Paintings>
