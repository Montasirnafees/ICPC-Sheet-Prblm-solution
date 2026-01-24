#include<stdio.h>
void add()
{
    int n,i;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        printf("%d",i);
        if(i!=n)
        {
            printf(" ");
        }
    }

}
int main()
{
    add();
    return 0;
}
