#include<stdio.h>
int  add(int n,double sum,double mean)
{
    //3
    double num[n];
    for(int i=0; i<n; i++)
    {
        scanf("%lf",&num[i]);//6 8 4
    }

    for(int i=0; i<n; i++)
    {
        sum = sum+num[i];

    }
    mean = sum/n;
    printf("%.7lf",mean);
    return 0;
}
int main()
{
    int n;
    scanf("%d",&n);
    double sum=0,mean=0;

    add(n,sum,mean);
}
