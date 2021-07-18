#include <stdio.h>
#include <stdlib.h>

int main(void){

    FILE *inFile = fopen("./test.txt","a+");   
    if (inFile == NULL){
        perror("open file fails: ");
    }

    fprintf(inFile, "hola mundo");

    return(EXIT_SUCCESS);
}

