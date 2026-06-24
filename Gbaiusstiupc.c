#include <stdio.h>

int main()
{
    int n, count = 0;
    int note[] = {100, 20, 10, 5, 1};

    scanf("%d", &n);

    for(int i = 0; i < 5; i++) {
        count += n / note[i];
        n = n % note[i];
    }

    printf("%d", count);
    return 0;
}
