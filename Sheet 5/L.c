#include<stdio.h>
void call()
{
    int N;
    scanf("%d",&N); //5
    int numa[N],numb[N],i,j;
    for(i=1;i<=N;i++){
    for(i=0; i<N; i++)
    {

        scanf("%d",&numa[i]);
    }
        for(i=0; i<N; i++)
    {

        scanf("%d",&numb[i]);
    }
        for(i=0; i<N; i++)
    {

        printf("%d ",numb[i]);
    }
        for(i=0; i<N; i++)
    {

        printf("%d ",numa[i]);
    }

    }

}

int main(){
    call();
    return 0;
}
