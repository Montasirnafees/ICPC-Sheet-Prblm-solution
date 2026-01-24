#include<stdio.h>
int main()
{
    long long num,sum;
    scanf("%ld",&num);
    sum = num*(num+1)/2;
    printf("%lld",sum);
    return 0;
}
