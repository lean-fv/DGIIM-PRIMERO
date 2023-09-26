#!/bin/bash
make
valgrind --leak-check=full dist/Debug/GNU-Linux/`ls dist/Debug/GNU-Linux/`