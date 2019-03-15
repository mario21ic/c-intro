#include <stdio.h>

int main()
{
  long num = 13051;
  printf("El valor de num es: %ld\n", num);

  printf("El tipo long ocupa %lu bytes = %lu bits\n", sizeof(long), sizeof(long)*8);
  printf("El tipo long puede almacenar %lu\n", 2 ^ (sizeof(long) * 8));

  return 0;
}
