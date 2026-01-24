#include<stdio.h>
#include<string.h>
int main()
{
    char str1[1001],str2[1001];
    scanf("%s %s",&str1,&str2);
    int x=strlen(str1);
    int y=strlen(str2);
    printf("%d %d\n",x,y);
    printf("%s %s",str1,str2);
}

