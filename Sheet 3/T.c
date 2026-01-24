#include<stdio.h>
#include <stdlib.h>
int main()
{
    int n,ans;
    scanf("%d",&n);

    int mat[n][n],i,j,sum1=0,sum2=0;
    for(i=0; i<n; i++){
        for(j=0;j<n;j++){
             scanf("%d",&mat[i][j]);

                if(i==j){
                    sum1=sum1+mat[i][j];
                }

                if(i+j==n-1)
                    {sum2=sum2+mat[i][j];
                }
        }
    }

        ans = sum1-sum2;

        printf("%d",abs(ans));

}

