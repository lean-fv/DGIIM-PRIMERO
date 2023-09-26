#1.- Liste el contenido del directorio /etc/ a un archivo de nombre ejercicio1.

ls -l /etc/ > ejercicio1;

#2.- Añada la ruta del directorio actual al archivo ejercicio1.

pwd >> ejercicio1;

#3.- Haciendo uso de los comandos de ejecución condicional de órdenes,comprueba si existe el archivo sample.txt en el directorio /root/. En caso afirmativo, haciendo uso de la orden echo, muestra "file found". En caso negativo, muestra "file not found".

ls /root/sample.txt && echo “file found” || echo “file not found”;
