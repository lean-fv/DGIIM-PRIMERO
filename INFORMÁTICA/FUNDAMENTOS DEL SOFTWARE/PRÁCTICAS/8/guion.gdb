# Nombre archivo: guion.gdb
# Uso: g++ -g  mainsesion09a.cpp -o mainsesion09a; gdb -x guion.gdb mainsesion09a
# Fecha:	25/05/2022 
# Autor:	Leandro Jorge Fernández Vega 
# Versión:	1.0 
# Descripción: Guión de depuración del fichero mainsesion09a.cpp.


break 15
break 29
break 42
break 47

run

#Punto de ruptura 42: int main (void){}
p/x $pc
p/x $sp
info locals
continue

#Punto de ruptura 29: Función int multiplica (int x, int y){for (i = 0; i < x; i ++)}
p/x $pc
p/x $sp
info locals
continue

p/x $pc
p/x $sp
info locals
continue

p/x $pc
p/x $sp
info locals
continue

#Punto de ruptura 47: int main (void){for (i = 0; i < 100; i ++)}
p/x $pc
p/x $sp
display final1
display final2
continue

#Punto de ruptura 15: Función int cuenta (int y){}
p/x $pc
p/x $sp
info locals
continue

#Punto de ruptura 47: int main (void){for (i = 0; i < 100; i ++)}
p/x $pc
p/x $sp
continue

#Punto de ruptura 15: Función int cuenta (int y){}
p/x $pc
p/x $sp
info locals
continue

#Punto de ruptura 47: int main (void){for (i = 0; i < 100; i ++)}
p/x $pc
x/i $pc
p/x $sp
x/i $sp
disassemble


delete breakpoints 2 3 4

q
y



