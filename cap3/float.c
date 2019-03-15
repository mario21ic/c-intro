#include <stdio.h>

int main()
{
  // valores entre 3,4E38 y 3,4E-38
  float num = 4060.80;
  printf("El valor de num es: %f\n", num);
  printf("El valor de num es: %e\n", num);

  printf("El tipo float ocupa %lu bytes = %lu bits\n", sizeof(float), sizeof(float)*8);
  printf("El tipo float puede almacenar %lu\n", 2 ^ (sizeof(float) * 8));

  return 0;
}
