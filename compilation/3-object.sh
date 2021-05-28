#/bin/bash
# Transforma asm a codigo objeto
set -e

as -o circulo.o circulo.s
file circulo.o
