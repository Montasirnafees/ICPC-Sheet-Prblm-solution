#include<stdio.h>
#include<string.h>
int main()
{
    char F1[100],S1[100],F2[100],S2[100];
    scanf("%c %c",&F1,&S1);
    scanf("%c %c",&F2,&S2);
    int x=strcmp(S1,S2);
    if(x==0){
        printf("ARE Brothers");
    }
    else{printf("NOT");}

}
