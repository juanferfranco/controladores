#include <stdio.h>
#include <stdint.h>

int main(void){

    uint32_t var = 10;
    uint32_t *pvar = &var;

    printf("var content: %d\n", *pvar);
    *pvar = 20;
    printf("var content: %d\n", var);

    return 0;
}