#!/bin/bash
set -e

# check .o objects inside libc.a
#ar -t /usr/lib/x86_64-linux-gnu/libc.a

gcc -static -o circuloSta circulo.c
ldd circuloSta
