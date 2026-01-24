#include<stdio.h>
void call()
{
    int N;
    scanf("%d",&N);
    int num[N],i,count=0;
    for(i=0; i<N; i++)
    {
        scanf("%d",&num[i]);
    }
    for(i=0; i<N; i++)
    {
        if(num[i]!=0)
        {
            printf("%d ",num[i]);
        }
        if(num[i]==0)
        {
            count++;
        }
    }


    for(i=0; i<count; i++)
    {
        printf("0 ",i);
    }

}


int main()
{
    call();
    return 0;
}

