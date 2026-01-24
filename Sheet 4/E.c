#include<stdio.h>
#include<string.h>
int main()
{
    char str1[1000001];
    scanf("%s",&str1);
    int sum=0,i;
    int x=strlen(str1);
    for(i=0; i<x; i++)
    {
        sum = sum+(str1[i]-'0');
    }
    printf("%d",sum);
}

