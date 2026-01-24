#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int num[n],i;
    for(i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    for(i=0;i<n;i++){
        if(num[i]<=10){
            printf("A[%d] = %d\n",i,num[i]);
        }
    }

}
