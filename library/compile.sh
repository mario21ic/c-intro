#!/bin/bash
set -e

rm -rf build/
mkdir -p build/{static,shared}

echo "### Objects"
gcc -c main.c -o build/main.o

# Create the object files for the static library (without -fPIC)
gcc -c mylib/add.c -o build/static/add.o
gcc -c mylib/answer.c -o build/static/answer.o

# Create object files for shared libraries need to be compiled as position independent
# code (-fPIC) because they are mapped to any position in the address space.
gcc -c -fPIC mylib/add.c -o build/shared/add.o
gcc -c -fPIC mylib/answer.c -o build/shared/answer.o

echo ""
echo "### Create Static library"
ar rcs build/static/libmylib.a build/static/add.o build/static/answer.o
ar -t build/static/libmylib.a

echo "# Link statically"
# The -L flag indicates (a non standard) directory where the libraries can be found.
# The -l flag indicates the name of the library. Note, that it assumes the library to start with lib and end with .o (so lib and .o must not be specified)
gcc build/main.o -Lbuild/static -lmylib -o build/statically-linked

echo "# Running"
ldd build/statically-linked
./build/statically-linked


echo ""
echo "### Create Shared library"
#  In order to create a shared library, position independent code
#  must be generated. This can be achieved with `-fPIC` flag when
#  c-files are compiled.
#
#  If the object files are created without -fPIC (such as when the static object files are produces), then
#      gcc -shared build/static/add.o build/static/answer.o -o build/shared/libmylib.so
#  produces this error:
#     /usr/build/ld: build/mylib.o: relocation R_X86_64_PC32 against symbol `gSummand' can not be used when making a shared object; recompile with -fPIC
#
gcc -shared build/shared/add.o build/shared/answer.o -o build/shared/libmylib.so
objdump -T build/shared/libmylib.so | grep text
#nm -D build/shared/libmylib.so

echo "# Link dynamically"
# Note the order:
#   -lmylib-shared needs to be placed AFTER main.c
gcc build/main.o -Lbuild/shared -lmylib -o build/use-shared-library

echo "# Running"
export LD_LIBRARY_PATH=$PWD/build/shared
echo "LD_LIBRARY_PATH="$LD_LIBRARY_PATH
ldd build/use-shared-library
./build/use-shared-library


echo ""
echo "### Create Dynamic loader"
gcc main-dynamic.c -ldl -o build/dynamic-library-loader

echo "# Running"
export LD_LIBRARY_PATH=$PWD/build/shared
echo "LD_LIBRARY_PATH="$LD_LIBRARY_PATH
./build/dynamic-library-loader


echo ""
echo "### Create Soname"
gcc -shared build/shared/add.o build/shared/answer.o -Wl,-soname,libmyLibSoname.so.1 -o build/shared/libmyLibSoname.so.1.0.1
objdump -p build/shared/libmyLibSoname.so.1.0.1
ln -s libmyLibSoname.so.1.0.1 build/shared/libmyLibSoname.so

echo "# Link"
gcc -Lbuild/shared build/main.o -lmyLibSoname -o build/use-shared-library-soname
# Alterntatively
# gcc -Lbin  src/main.c -ltq84Soname -o bin/use-shared-library-soname

echo "# Installing"
ldconfig -v -n $PWD/build/shared

echo "# Running"
./build/use-shared-library-soname


echo ""
echo "### Difference between -fPIC and without it"
objdump --disassemble build/shared/add.o | sed -n '/<add>/,/^$/p'
objdump --disassemble build/static/add.o | sed -n '/<add>/,/^$/p'
#readelf --relocs build/shared/add.o
#readelf --relocs build/static/add.o


echo ""
echo "### Debug mode"
#
#  Use LD_DEBUG
#    set it to libs to display library search paths
#
LD_DEBUG=libs build/use-shared-library

#
#  Setting LD_DEBUG to files to display progress for input files
#
LD_DEBUG=files build/use-shared-library

#
#  Setting LD_DEBUG to reloc to display relocation processing
#
LD_DEBUG=reloc build/use-shared-library

LD_DEBUG=symbols build/use-shared-library

echo ""
echo "### List symbols in object files"
echo "## add.o"
nm build/static/add.o
echo "## libmyLibSoname.so"
nm build/shared/libmyLibSoname.so
echo "## statically-linked"
nm build/statically-linked
echo "## dynamic-library-loader"
nm build/dynamic-library-loader
