#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        char s1[101];
        scanf("%s",s1);
        int x=strlen(s1);
        if(x<=10){
            printf("%s\n",s1);
        }
        else{printf("%c%d%c\n",s1[0],x-2,s1[x-1]);}
    }
}
