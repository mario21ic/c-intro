#!/bin/bash
set -e

echo "## As"
as -o hello.o hello.S
file hello.o

echo "## Ld"
ld -s -o hello hello.o
file hello
