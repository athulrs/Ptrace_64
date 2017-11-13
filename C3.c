#include <stdio.h>
int main()
{
    printf("child3 starts...\n");
    asm("pushq %rdi\n\t"
        "movl  $143, %rdi\n\t"
        "L1: cmpq $245, %rdi\n\t"
        "jne L1\n\t"
        "popq %rdi\n\t");
    printf("child3 outside loop...\n");
}