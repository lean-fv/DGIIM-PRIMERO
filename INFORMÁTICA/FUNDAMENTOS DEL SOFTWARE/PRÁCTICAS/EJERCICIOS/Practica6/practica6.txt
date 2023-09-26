Contesta a cada una de las siguientes cuestiones:

1- Usa uno de los guiones que tienes y ejecútalo en background. Indica el comando para realizar este punto.

./6_4.sh &


2. Indica el número de proceso asignado. ¿Qué comando has usado?

ps -ef |grep "6_4.sh"

PID=5643

3. ¿Cómo matarías a dicho proceso antes de que finalice?

kill -s STOP 5643

4. Indica una alternativa para mostrar la información más completa de todos los procesos que se están ejecutando en el sistema (no solo los tuyos).

ps -lA
