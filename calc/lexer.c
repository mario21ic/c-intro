#include <stdio.h>
#include "lexer.h"

size_t caracteres_leidos = 0;

enum token lexer(void) {
    char c;
    while((c = getc(stdin)) != EOF) {
        caracteres_leidos++;
        putc(c, stdout);
    }
    return fin_de_archivo;
}
