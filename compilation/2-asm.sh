#!/bin/bash
# Transforma codigo C en lenguage asm
set -e

gcc -S circulo.c
head circulo.s
file circulo.s
