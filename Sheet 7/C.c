#include<stdio.h>
void call(int i)
{
    if(i>=1)
    {
        printf("%d",i);
        if(i>1)
        {
            printf(" ");
        }
call(i-1);
    }
}


int main()
{
    int n;
    scanf("%d",&n);
    call(n);
}
