#include <stdio.h>

int main()
{
#ifdef DEBUG
    printf("I am a programmer, I can't climb trees!!!\n");
#endif

    for (int i = 0; i <= 3; i++) {
        printf("Hello GCC!!!\n");
    }

    return 0;
}


// gcc debug.c -o debug -D DEBUG