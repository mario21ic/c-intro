#!/bin/bash
set -e

#gcc -o main-arm64 main.c

echo "## ARM"
aarch64-linux-gnu-gcc --static -o main-arm64 main.c
file main-arm64

echo ""

echo "## AMD64"
x86_64-linux-gnu-gcc  --static -o main-amd64 main.c
file main-amd64
