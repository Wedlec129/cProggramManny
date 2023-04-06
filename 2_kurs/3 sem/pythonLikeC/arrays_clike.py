import random

array_size = 20
array_of_ints = []

for i in range(array_size):
    array_of_ints.append(random.randint(0, 99))

for i in range(array_size):
    print("array[{}]:\t{}".format(i, array_of_ints[i]))

for i in range(array_size):
    for j in range(30):
        rand_index = random.randint(0, array_size-1)
        temp = array_of_ints[i]
        array_of_ints[i] = array_of_ints[rand_index]
        array_of_ints[rand_index] = temp

print("---")
for i in range(array_size):
    print("array[{}]:\t{}".format(i, array_of_ints[i]))
