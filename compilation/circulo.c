/* Circulo.c: calcula el área de un círculo.
   Ejemplo para mostrar etapas de compilación.
*/

//#include <stdio.h>

#include "header.c"

#define PI 3.1416

void main()
{
  float area, radio;

  radio = 10;
  printf("### Circulo ###\n");

  printf("%s%f\n", "ABC: ", ABC);
  printf("%s%f\n", "PI: ", PI);

  area = PI * (radio * radio);
  printf("%s%f\n\n", "Area de circulo radio 10: ", area);
}
