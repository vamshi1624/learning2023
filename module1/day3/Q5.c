#include <stdio.h>
#include <math.h>

int main() {
    int num;
    printf("Enter a 4-digit number: ");
    scanf("%d", &num);
    num = abs(num);

    int max= 0;

    for (int i = 0; i < 4; i++) {
        int temp = num / (int)pow(10, i + 1) * (int)pow(10, i) + num % (int)pow(10, i);

        if (temp > max) {
            max = temp;
        }
    }

    printf("The largest number: %d\n", max);

    return 0;
}