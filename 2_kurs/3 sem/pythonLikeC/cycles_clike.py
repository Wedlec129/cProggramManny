"""
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
"""

def facto(a):
    result = 1
    while a > 0:
        result *= a
        a -= 1  # в python нет операций ++ и --
    return result


def main():
    for i in range(10):
        print("{}! = {}".format(i, facto(i)))


if __name__ == '__main__':
    main()
