#include <stdio.h>
#include <stdint.h>

int main (void) {
    uint16_t a = 65280;
    *(((uint8_t*)((&a)+1))-1) += 1;
    printf("a: %d\n", a);
    return 0;
}
