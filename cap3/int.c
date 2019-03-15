#include <stdio.h>

int main()
{
  int numero = 13051;
  printf("Decimal usando 'i': %i\n", numero);
  printf("Decimal usando 'd': %d\n", numero);
  printf("Heximal: %x\n", numero);
  printf("Octal: %o\n", numero);

  signed int x = 10;
  printf("El valor inicial de x es %i\n", x);
  x = 50;
  printf("Ahora el valor es %i\n", x);

  printf("El tipo int ocupa %lu bytes = %lu bits\n", sizeof(int), sizeof(int)*8);
  printf("El tipo int puede almacenar %lu\n", 2 ^ (sizeof(int) * 8));

  return 0;
}
