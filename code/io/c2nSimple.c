#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

int main(void)
{
    char *endptr;
    long val;    
    char *number = " -2892 test";

    errno = 0;
    val = strtol(number, &endptr, 10);    
    if(errno == 0 && *number != 0 && number != endptr){
        printf("strtol return: %ld\n",val);
    }
    else{
        printf("strtol fails\n");
    }

    exit(EXIT_SUCCESS);
}