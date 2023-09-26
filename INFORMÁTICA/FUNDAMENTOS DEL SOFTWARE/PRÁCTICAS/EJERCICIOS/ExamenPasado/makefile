#makefile examen pasado
CC=g++
I_DIR=./include


juegoAsteroides: juego.o asteroide.o colision.o mover.o mostrarpanel.o
	$(CC) -o $@ $^

juego.o asteroide.o colision.o mover.o: juego.cpp asteroide.cpp colision.cpp mover.cpp mostrarpanel.cpp
	$(CC) -c -I$(I_DIR) $^

clean:
	rm *.o juegoAsteroides
