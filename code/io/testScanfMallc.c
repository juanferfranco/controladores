#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){

    char *strPtr;
    // [^\n]: lee mientras no encuentres el enter
    int n = scanf("%m[^\n]",&strPtr);
    if(n == 1){
        printf("String length: %ld\n", strlen(strPtr));
        free(strPtr);
    }
    else{
        printf("scanf fails\n");
    }
    return(EXIT_SUCCESS);
}