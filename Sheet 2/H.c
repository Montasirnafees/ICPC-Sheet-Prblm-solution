#include<stdio.h>
#include<math.h>
int main()
{
    int number,count = 0;
    scanf("%d",&number);

    if (number<=1){
        count = 1;
    }
    else{ for (int i=2; i<=sqrt(number); i++)
        {
            if (number%i==0){
                count =1;
                break;}
        }
    }

    if (count==0){
        printf("YES",number);
    }
    else{
        printf("NO",number);

    }
    getchar();
}
