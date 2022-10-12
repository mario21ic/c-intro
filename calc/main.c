#include <stdio.h>
#include "lexer.h"

int main(void) {
    lexer();
    printf("Se leyeron %ld caracteres\n", caracteres_leidos);

    return 0;
}

