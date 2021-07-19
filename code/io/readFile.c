#include <stdio.h>
#include <stdlib.h>

int main(void){

    FILE *inFile = fopen("./test.txt","r");   
    if (inFile == NULL){
        perror("open file fails: ");
        return(EXIT_FAILURE);
    }

    char buffer[64];
    char *status =  NULL;

    do{
        status = fgets(buffer, sizeof(buffer),inFile);
        if(status != NULL){
            printf("%s",buffer);
        }
    }while (status !=NULL);
    printf("\n");

    fclose(inFile);

    return(EXIT_SUCCESS);
}
