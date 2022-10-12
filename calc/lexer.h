#ifndef _LEXER_
#define _LEXER_

enum token {numero, suma, resta, multiplicacion, division, modulo, potencia, parentesis_izq, parentesis_der, fin_de_archivo};

typedef enum token token_t;
extern size_t caracteres_leidos;
extern enum token lexer(void);

#endif
