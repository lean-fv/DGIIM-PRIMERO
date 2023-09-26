#!/bin/bash

if [ -O $1 ];
	then printf "El archivo $1 es propiedad del usuario.\n"; fi
	
if [ -r $1 ];
	then printf "El usuario tiene permiso de lectura sobre $1.\n"; fi
