#!/bin/bash
set -e

gcc -dynamic -o circuloDyn circulo.c
ldd circuloDyn
