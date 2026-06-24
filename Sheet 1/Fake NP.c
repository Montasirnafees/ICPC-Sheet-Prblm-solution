#include<stdio.h>
int main()
{
    int l,t;
    scanf("%d %d",&l,&t);
    int diff=t-l;
    if(diff%2==0){
        printf("2");
    }
    else printf("3");
}
