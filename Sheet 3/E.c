#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    scanf("%d",&n);
    int num1[n],num[n];
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&num[i]);
        num1[i] = num[i];
    }

    for(int j=1; j<n; j++)
    {
        for(int i=1; i<n; i++)
        {
            if(num1[i]>num1[i+1])
            {
                int x=num1[i];
                num1[i]=num1[i+1];
                num1[i+1]=x;
            }
        }
    }
    int min=num1[1];

    for(int i=1; i<n; i++)
    {
        if(num[i]==min)
        {
            printf("%d %d",min,i);
            break;
        }
    }

}
