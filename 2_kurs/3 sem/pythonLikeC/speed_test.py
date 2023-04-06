INT_MAX = 2147483647
counter_of_27 = 0
current = 0
while current < INT_MAX:
    if current % 27 == 0:
        counter_of_27 += 1
    current += 1
print("Answer: {}".format(counter_of_27))
