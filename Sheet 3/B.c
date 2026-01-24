#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int num[n],i;
    for(i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    int p;
    scanf("%d",&p);
    for(i=0;i<n;i++){
        if(p==num[i]){
            printf("%d",i);
            return 0;}
        }
        printf("-1");

}
