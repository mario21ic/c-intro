#include <stdio.h>
#include <limits.h>

int main()
{
  printf("El tipo char ocupa %lu bytes = %lu bits \n", sizeof(char), sizeof(char)*8);
  printf("El tipo char puede almacenar %lu\n", 2 ^ (sizeof(char) * 8));
  printf("Bits que ocupa un caracter %d\n", CHAR_BIT);
 
  char numero;
  char *punt;
  numero = 43;
  punt = &numero;

  printf("La variable numero se almacena en la posicion de memoria %p y su valor es %d\n", (void *) &numero, numero);
  printf("El puntero punt se almacena en la posicion de memoria %p, su valor es %p y contenido es %d\n", (void *) &punt, punt, *punt);

  *punt = 30;
  printf("El puntero punt se almacena en la posicion de memoria %p, su valor es %p y contenido es %d\n", (void *) &punt, punt, *punt);
  

  return 0;
}
