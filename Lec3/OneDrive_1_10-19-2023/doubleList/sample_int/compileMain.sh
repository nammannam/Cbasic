#!/bin/sh
gcc -c ./data_t.c
gcc -c ./dllist.c
gcc -c ./llmain.c
gcc -o test data_t.o dllist.o llmain.o