#include<stdio.h>
#include<string.h>
int main()
{
    char str1[1001],str2[1001];
    scanf("%s %s",&str1,&str2);
    int x=strcmp(str1,str2);
    if(x==0){
        printf("%s",str1);
    }
    else if(x==-1){
        printf("%s",str1);
    }
    else if(x==1){
        printf("%s",str2);
    }
}

