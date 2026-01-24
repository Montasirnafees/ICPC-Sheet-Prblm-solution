#include<stdio.h>
void check(int i,int n){
if(i<=n){
    printf("I love Recursion\n");
    check(i+1,n);
}
}
int main()
{
    int n;
    scanf("%d",&n);
    check(1,n);
}
