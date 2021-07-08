#include <stdio.h>
#include <stdint.h>


int main(void){

    uint32_t arr[4] = {1,2,3,4};

    // 1. ¿Qué es el nombre de arreglo?
    // arr: es un puntero al primer elemento del arreglo.
    // El primer elemento es de tipo uint32_t
    // --> arr será la dirección de ese primer uint32_t, es decir,
    // arr es de tipo uint32_t *

    uint32_t *pvar = arr;

    printf("pvar: %p\n", pvar);
    printf("arr: %p\n", arr);

    // 2. ¿Qué es la dirección de un arreglo? 

    uint32_t (*pvar2)[4] =   &arr;

    printf("pvar: %p\n", pvar);
    printf("pvar2: %p\n", pvar2);

    printf("pvar + 1: %p\n", pvar+1);
    printf("pvar2 + 1: %p\n", pvar2+1);

    // 3. ¿Cómo accedo a los elementos de un arreglo con un puntero?

    printf("arr[0]: %d\n", arr[0]);

    printf("arr[0]: %d\n", *pvar);
    printf("arr[1]: %d\n", *(pvar + 1) );
    printf("arr[2]: %d\n", *(pvar + 2) );
    printf("arr[3]: %d\n", *(pvar + 3) );


}


