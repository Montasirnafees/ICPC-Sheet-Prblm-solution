#include <stdio.h>
int main()
{
    int test, num, even = 0, odd = 0, pos = 0, neg = 0;

    scanf("%d", &test);

    for (int i = 0; i < test; i++) {
        scanf("%d", &num);

        if (num % 2 == 0)
            even++;
        else
            odd++;

        if (num > 0)
            pos++;
        else if (num < 0)
            neg++;
    }

    printf("Even: %d\n", even);
    printf("Odd: %d\n", odd);
    printf("Positive: %d\n", pos);
    printf("Negative: %d\n", neg);

    return 0;
}
