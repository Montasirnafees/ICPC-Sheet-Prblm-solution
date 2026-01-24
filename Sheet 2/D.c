#include<stdio.h>
int main()
{
    int pass=1999,pass1;
    while(1)
    {

        scanf("%d",&pass1);

        if(pass==pass1)
        {
            printf("Correct");
            break;
        }
        else
        {
            printf("Wrong\n");
        }
    }
    return 0;
}
