#include <stdio.h>
#include <stdint.h>

int main(void)
{
    int32_t a = 10;
    int32_t b = 20;
    int32_t c = 0;

    c = a + b;
    c = a - b;
    c = a * b;
    c = a / b;
    c = a % b;
    c = a++;
    c = a--;
    return 0;
}
