/*#include<stdio.h>
int main()
{
    int a,b,c;
    printf("Enter three numbers:");
    scanf("%d %d %d",&a,&b,&c);

    int max = a;
    if(b>max)
        max = b;
    if(c>max)
        max = c;
    printf("The maximum number is: %d",max);
}

#include<stdio.h>
int main()
{
    int a,b,c,max = 0;
    printf("Enter three numbers:");
    scanf("%d %d %d",&a,&b,&c);
    if(a>b && a>c)
        max = a;
    else if(b>a && b>c)
        max = b;
    else max = c;
    printf("The maximum number is: %d",max);
}
*/
#include<stdio.h>
int main()
{
    int a,b,c,max = 0;
    printf("Enter three numbers:");
    scanf("%d %d %d",&a,&b,&c);
    if(a >= b)
    {
        if(a >= c)
            printf("The maximum number is: %d",a);
        else
            printf("The maximum number is: %d",c);
    }
    else
    {
        if(b >= c)
            printf("The maximum number is: %d",b);
        else
            printf("The maximum number is: %d",c);
    }

    return 0;
}
