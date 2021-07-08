#include <stdio.h>
#include <stdint.h>

int main(void){

    char text[] = "hola C";

    printf("%s\n",text);

    *text = 'H';

    printf("%s\n",text);
}

