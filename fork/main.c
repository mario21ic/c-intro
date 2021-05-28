#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
  
    // make two process which run same
    // program after this instruction
    fork();
    //fork();
    //fork();
    // n=3 => total_number_process = 2^n
    // 2^3 = 8 printfs
    //printf("Hello world!\n");

    // child process because return value zero
    if (fork() == 0)
        printf("Hello from Child!\n");
    // parent process because return value non-zero.
    else
        printf("Hello from Parent!\n");
    return 0;
}
