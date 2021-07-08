#include <stdio.h>
#include <stdint.h>

int main(void){

    char a;
    int b;
    float c;
    void (*d)(void); 

    printf("a'address: %p\n", &a);
    printf("b'address: %p\n", &b);
    printf("c'address: %p\n", &c);
    printf("d'address: %p\n", &d);

    return 0;
}