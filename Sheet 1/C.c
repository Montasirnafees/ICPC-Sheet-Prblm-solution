#include<stdio.h>
int main()
{
    int num1,num2;
    scanf("%d %d",&num1,&num2);
    int sum=(num1+num2);
    printf("%d + %d = %d\n",num1,num2,sum);
    long long multiplication=(long long)num1*num2;
    printf("%d * %d = %lld\n",num1,num2,multiplication);
    int substraction=(num1-num2);
    printf("%d - %d = %d\n",num1,num2,substraction);
}
