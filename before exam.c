#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    char str[201];
    scanf("%s",str);
    int x=strlen(str),count=0;
    for(int i=0;i<x;i++){
        if(str[i]>='A' && str[i]<='Z'){
            count++;
        }
    }
    if(count>=x-1){
         str[0] = toupper(str[0]);

    for (int i = 1; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
        printf("%s",str);
    }
    else printf("%s",str);

}
