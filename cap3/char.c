#include <stdio.h>

int main()
{
  // valores entre -128 a 127
  char letra_negativa = -128;
  printf("La letra es: %c y su valor ASCII es: %i\n", letra_negativa, letra_negativa);

  char letra = 'A';
  printf("La letra es: %c y su valor ASCII es: %i\n", letra, letra);
  letra = letra + 1;
  printf("Ahora es: %c y su valor ASCII es: %i\n", letra, letra);

  // valores entre 0 a 255
  unsigned char letra_unsigned = 255;
  printf("La letra es: %c y su valor ASCII es: %i\n", letra_unsigned, letra_unsigned);

  printf("El tipo char ocupa %lu bytes = %lu bits \n", sizeof(char), sizeof(char)*8);
  printf("El tipo char puede almacenar %lu\n", 2 ^ (sizeof(char) * 8));

  return 0;
}
