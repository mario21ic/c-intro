#include <stdio.h>
#include "lexer.h"

int main(void) {
    lexer();
    printf("\nSe leyeron %ld caracteres\n", caracteres_leidos);

    return 0;
}

