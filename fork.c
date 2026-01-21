#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    fork();
    fork();
    fork();
    printf("hello\n");
    printf("hello\n");
    printf("hello\n");
    printf("hello\n");
    printf("hello\n");
    printf("hello\n");
    return 0;
}

// Output 

// hello
// hello
// hello
// hello
// hello
// hello
// hello
// hello
