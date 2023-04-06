#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
    srand(time(NULL)); // начальное заполнение генератора случайных чисел

    const int array_size = 20;
    int array_of_ints[array_size]; // массив статического размера

    for (int i = 0; i < array_size; i++) {
        array_of_ints[i] = rand() % 100; // заполнение массива случайными числами от 0 до 99
    }

    for (int i = 0; i < array_size; i++) printf("array[%d]:\t%d\n", i, array_of_ints[i]);

    for (int i = 0; i < array_size; i++) {
        for (int j = 0; j < 30; j++) { // меняет местами i-й эл-т массива со случайным 30 раз
            int rand_index = rand() % array_size;
            int temp = array_of_ints[i];
            array_of_ints[i] = array_of_ints[rand_index];
            array_of_ints[rand_index] = temp;
        }
    }

    puts("---");
    for (int i = 0; i < array_size; i++) printf("array[%d]:\t%d\n", i, array_of_ints[i]);

    return 0;
}
