#!/bin/bash
# Interpreta las directicas al preprocesador
set -e

gcc -E circulo.c > circulo.pp
#cpp circulo.c > circulo.pp
cat circulo.pp

