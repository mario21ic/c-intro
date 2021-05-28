#!/bin/bash
set -e

rm -rf build/
mkdir -p build/{static,shared}

gcc -c main.c -o build/main.o

# Create the object files for the static library (without -fPIC)
gcc -c mylib/add.c -o build/static/add.o
gcc -c mylib/answer.c -o build/static/answer.o

# Create object files for shared libraries need to be compiled as position independent
# code (-fPIC) because they are mapped to any position in the address space.
gcc -c -fPIC mylib/add.c -o build/shared/add.o
gcc -c -fPIC mylib/answer.c -o build/shared/answer.o

echo "# Create Static library"
ar rcs build/static/libmylib.a build/static/add.o build/static/answer.o
ar -t build/static/libmylib.a

echo "# Link statically"
# The -L flag indicates (a non standard) directory where the libraries can be found.
# The -l flag indicates the name of the library. Note, that it assumes the library to start with lib and end with .o (so lib and .o must not be specified)
gcc build/main.o -Lbuild/static -lmylib -o build/statically-linked

echo "# Running"
ldd build/statically-linked
./build/statically-linked


echo "# Create Shared library"
#  In order to create a shared library, position independent code
#  must be generated. This can be achieved with `-fPIC` flag when
#  c-files are compiled.
#
#  If the object files are created without -fPIC (such as when the static object files are produces), then
#      gcc -shared build/static/add.o build/static/answer.o -o build/shared/libtq84.so
#  produces this error:
#     /usr/build/ld: build/tq84.o: relocation R_X86_64_PC32 against symbol `gSummand' can not be used when making a shared object; recompile with -fPIC
#
gcc -shared build/shared/add.o build/shared/answer.o -o build/shared/libmylib.so

echo "# Link dynamically"
# Note the order:
#   -ltq84-shared needs to be placed AFTER main.c
gcc  build/main.o -Lbuild/shared -lmylib -o build/use-shared-library

echo "# Running"
ldd build/use-shared-library
export LD_LIBRARY_PATH=$PWD/build/shared
./build/use-shared-library
