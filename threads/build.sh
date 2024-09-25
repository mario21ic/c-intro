#!/bin/bash

gcc -pthread main.c
gcc -o print_numbers threads/print_numbers.c -lpthread
