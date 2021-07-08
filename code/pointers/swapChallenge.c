#include <stdio.h>
#include <stdint.h>

void swap(int *a, int *b);

int x;
int y;

int main(void){

    x = 1;
    y = 2;
    printf("El valor de x es: %d\n", x);
    printf("El valor de y es: %d\n", y);
    
    swap(&x,&y);
    
    printf("El valor de x es: %d\n", x);
    printf("El valor de y es: %d\n", y); 

    return 0;
}


void swap(int *a, int *b){
    
    int tmp = *a; // tmp = x

    *a = *b; // x = y 
    *b = tmp; // y = tmp
}

