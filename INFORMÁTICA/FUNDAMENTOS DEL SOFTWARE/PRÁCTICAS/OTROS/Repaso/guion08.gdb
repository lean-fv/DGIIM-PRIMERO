# Nombre archivo: guion08.gdb
# Uso: g++ -g mainsesion09a.cpp -o mainsesion09; gdb -x guion08.gdb mainsesion09a
# Fecha:	25/05/2022 
# Autor:	Leandro Jorge Fernández Vega 
# Versión:	1.0 
# Descripción: Guión de depuración del ejercicio de repaso de la sesión 8. El código proporcionado es idéntico al del fichero mainsesion09a.cpp.

break 46
break 47 if i==50
break 50

run

#Punto de ruptura 46: int main (void){}
print final2
continue

#Punto de ruptura 47: int main (void){for (i = 0; i < 100; i ++){}}
print final2
print i
continue

#Punto de ruptura 50: int main (void){}
set variable final2=cuenta(1000)
print final2

q
y
