#include <stdio.h>
#include <string.h>
#include <stdint.h>

int main(void)
{
    char age[4];
    printf("How old are you? ");
    if (fgets(age, 4, stdin) != NULL)
    {
        age[strlen(age) -1 ] = 0;
        printf("I am %s years old\n", age);
    }
    for(uint8_t i = 0; i < strlen(age);i++){
        printf("age[%d]: %c\n",i,age[i]);
    }
}
