#include <stdio.h>
int main() {
    int t, n;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);
        long long fact = 1;
        for (int j = 1; j <= n; j++) {
            fact *= j;
        }
        printf("%lld\n", fact);
    }
    return 0;
}
