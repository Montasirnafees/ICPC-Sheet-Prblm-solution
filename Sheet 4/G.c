#include<stdio.h>
#include<string.h>
int main()
{
    char str1[100001];
    scanf("%s",&str1);
    int i, x=strlen(str1);
    for(i=0;i<x;i++){
        if(str1[i]>='a'&& str1[i]<='z'){
            printf("%c",str1[i]-32);
        }
        else if(str1[i]>='A'&& str1[i]<='Z'){
            printf("%c",str1[i]+32);
        }
        else{printf(" ");}
        }
}

