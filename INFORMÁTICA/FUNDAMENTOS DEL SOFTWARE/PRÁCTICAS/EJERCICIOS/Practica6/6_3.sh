#!/bin/bash

#6_3.sh
#echo `ps -u $USER -o cmd --sort=-%mem --no-headers | head -1`;

#O BIEN:
echo `ps -u $USER -o cmd --sort=-size | head -2 | tail -1`;
