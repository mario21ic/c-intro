#include <stdio.h>

int main()
{
  // valores entre 1,7E308 y 1,7E-307
  double numero = 10.30;
  printf("El valor de num es: %f\n", numero);

  printf("El tipo double ocupa %lu bytes = %lu bits\n", sizeof(double), sizeof(double)*8);
  printf("El tipo double puede almacenar %lu\n", 2 ^ (sizeof(double) * 8));

  return 0;
}
