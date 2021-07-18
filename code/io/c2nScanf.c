#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(void)
{
    int val;    
    char number[40];

    printf("Enter an integer number: ");
    if (fgets(number, 40, stdin) != NULL)
    {
        number[strlen(number) -1 ] = 0;
        printf("The string to convert is %s\n", number);
    }

    errno = 0;
    int successItems = sscanf(number,"%d",&val);
    if(successItems == 1){
        printf("val: %d\n", val);
    }
    else{
        printf("sscanf fails\n");
    }

    exit(EXIT_SUCCESS);
}