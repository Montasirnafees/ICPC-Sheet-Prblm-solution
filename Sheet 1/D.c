#include<stdio.h>
int main()
{
    int num1,num2,num3,num4;
    scanf("%d %d %d %d",&num1,&num2,&num3,&num4);

    long long diff=(long long) num1*num2-(long long)num3*num4;
    printf("Difference = %lld",diff);

}
