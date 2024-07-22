#include "stdio.h"
#include "stdlib.h"
int main(int argc, char** argv)
{
    asm("sub $0x20,%rsp\n\t" // assembly code!
        "movabs $0x77202c6f6c6c6548,%rax\n\t"
        "mov    %rax,(%rsp)\n\t"
        "movl   $0x646c726f, 0x8(%rsp)\n\t"
        "movw   $0x21, 0xc(%rsp)\n\t"
        "movb   $0x0,0xd(%rsp)\n\t"
        "leaq    (%rsp),%rax\n\t"
        "mov    %rax,%rdi\n\t"
        "call  __Z6myputsPc\n\t"
        "add    $0x20, %rsp\n\t");
    return EXIT_SUCCESS;
}