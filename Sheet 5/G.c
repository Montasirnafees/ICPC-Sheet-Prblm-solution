#include<stdio.h>
void call()
{
    int N;
    scanf("%d",&N); //5
    int num[N],i;
    for(i=0; i<N; i++)
    {
        scanf("%d",&num[i]);//7 6 5  1 9
    }
    int max=num[0],min=num[0];
    for(i=0; i<N; i++){
        if(max<num[i]) //cond check
        {
            max=num[i];
        }
        if(min>num[i])
        {
            min=num[i];
        }
    }
      printf("%d %d",min,max);


}

int main(){
    call();
    return 0;
}
