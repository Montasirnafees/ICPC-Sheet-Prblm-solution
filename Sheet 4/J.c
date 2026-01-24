#include<stdio.h>
#include<string.h>


int main()
{
    char str[10000001],c;
    int count=0,i;
fgets(str, sizeof(str), stdin);
    for(c='a';c<='z';c++){
        count =0;
        for(i=0;str[i]!=0;i++){
            if(str[i]==c)
                count++;
        }
        if(count>0){
            printf("%c : %d\n",c,count);
        }
    }

}
