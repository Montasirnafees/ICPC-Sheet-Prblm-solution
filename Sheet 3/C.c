#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    long long a[n],i;
    for(i=0;i<n;i++){
        scanf("%lld",&a[i]);

        if(a[i]==0){
            printf("0 ");
        }
        else if(a[i]<0){
            printf("2 ");
        }

        else{printf("1 ");}
    }

}
