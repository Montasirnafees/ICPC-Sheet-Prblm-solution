#include<stdio.h>
void call(){
    int t,i;
    scanf("%d",&t);
    while(t--){
    int n;
    char ch;
    scanf("%d %c",&n,&ch);
    for(i=1;i<=n;i++){
        printf("%c ",ch);
    }
    printf("\n");
    }
}

int main()
{
    call();
}
