# include <stdio.h>
# include <stdlib.h>

unsigned short word = 0x1234; /* el tipo de dato short en C utiliza
dos bytes para almacenar los datos */
unsigned char * p = (unsigned char *) &word; /* el tipo de dato char
emplea un byte para almacenar un dato (12h 34h)*/

int main(){
    if ( p[0] == 0x12 ){
        printf ("máquina Big Endian\n");
        printf ("el número 0x1234 se almacena como:\n 0x12 0x34\n");
    }else{
        printf("máquina Little Endian\n");
        printf ("el número 0x1234 se almacena como:\n 0x34 0x12\n");
    }
    //system("pause");
    return 0;
}
