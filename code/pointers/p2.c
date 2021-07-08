#include <stdio.h>
#include <stdint.h>

int main(void){

    uint32_t var;
    uint32_t *pvar = &var;

    printf("var'address: %p\n", &var);
    printf("pvar'address: %p\n", &pvar);
    printf("pvar content: %p\n", pvar);
    return 0;
}
