#include <stdio.h>

int main() {
    int n, i, num, max;
    scanf("%d", &n);
    scanf("%d", &num);
    max = num;

    for(i = 1; i < n; i++) {
        scanf("%d", &num);
        if(num > max) {
            max = num;
    }

    printf("%d\n", max);

    return 0;
}
