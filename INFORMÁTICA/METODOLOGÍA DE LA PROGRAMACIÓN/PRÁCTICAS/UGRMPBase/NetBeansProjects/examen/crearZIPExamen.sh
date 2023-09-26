#!/bin/bash
rm -rf zip/* dist/* build/* doc/html doc/latex
zip -r zip/ExamenLaboratorio.zip * -x nbproject/private/*