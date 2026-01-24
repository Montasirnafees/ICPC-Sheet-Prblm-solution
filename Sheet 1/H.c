#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,c,d,e;
    scanf("%d %d",&a,&b);
    c= ceil(1.0*a/b);
    d=floor(a/b);
    e=round((double)a/b);
    printf("floor %d / %d = %d\n",a,b,d);
    printf("ceil %d / %d = %d\n",a,b,c);
    printf("round %d / %d = %d\n",a,b,e);
}
