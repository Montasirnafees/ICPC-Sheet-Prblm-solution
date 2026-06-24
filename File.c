#include<stdio.h>
int main()
{
    FILE *nafees = fopen("porena.txt","r");
    if(nafees==NULL){
        printf("File banano hoy nai");
    }
    else printf("File hoise");
    fclose(nafees);
}
