#include <stdio.h>

int facto (int a) {
    int result = 1;
    while (a > 0) {
        result *= a;
        a--;
    }
    return result;
}

int main() {
    for (int i = 0; i < 10; i++) {
        printf("%d! = %d\n", i, facto(i));
    }
    return 0;
}
