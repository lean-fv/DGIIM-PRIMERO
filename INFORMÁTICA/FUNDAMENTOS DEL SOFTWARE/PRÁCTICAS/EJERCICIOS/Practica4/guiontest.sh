#!/bin/bash
#guiontest.sh
condicion_1=`test -f $1 -a -x $1 && echo "true" || echo "false"`
condicion_2=`test -h $1 && echo "true" || echo "false"`

echo "El archivo $1 es plano y se tiene permiso de ejecución sobre él: $condicion_1"
echo "El archivo $1 es un enlace simbólico: $condicion_1"
