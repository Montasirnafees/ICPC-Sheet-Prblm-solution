#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int num[n+5],i,count=0,min;
    for(i=0; i<n; i++)
    {
        scanf("%d",&num[i]);
    }
    min = num[0];
    for (int i = 0; i < n; i++)
    {
        if (min > num[i])
        {
            min = num[i];
        }
    }
    count = 0;
    for (i = 0; i < n; i++)
    {
        if (num[i] == min)
        {
            count++;
        }
    }
    if(count%2==0)
    {
        printf("Unlucky");
    }
    else
    {
        printf("Lucky");
    }
}

