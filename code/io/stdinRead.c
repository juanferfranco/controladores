#include <stdio.h>
#include <string.h>

int main(void)
{
    char name[40];
    printf("What is your name? ");
    if (fgets(name, 40, stdin) != NULL)
    {
        name[strlen(name) -1 ] = 0;
        printf("Hello %s!\n", name);
    }
}
