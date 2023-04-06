#include <stdio.h>
#include <limits.h>

int main () {
    long counter_of_27 = 0;
    long current = 0;
    while (current < (long)INT_MAX) if (current++ % 27 == 0) counter_of_27++;
    printf("Answer: %ld\n", counter_of_27);
    return 0;
}
