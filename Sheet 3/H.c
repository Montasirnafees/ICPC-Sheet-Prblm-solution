#include<stdio.h>
int main()
{
    int n,i,j;
    scanf("%d",&n);
    int num[n];
    for(i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    for(j=0;j<n-1;j++){
        for(i=0;i<n-1;i++){
            if(num[i]>num[i+1]){
                int x=num[i];
                num[i]=num[i+1];
                num[i+1]=x;
            }
        }
    }
    for (i = 0; i < n; i++) {
    printf("%d ", num[i]);
}


}
