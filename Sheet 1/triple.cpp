#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int num[n];
        for(int i=1;i<n;i++){
            scanf("%d",&num[i]);
        }
        sort(num,num+n);

        int count = 1;
        int ans = -1;
        for(int i=1;i<n;i++){
            if(num[i]==num[i-1]){
                count++;

            if(count>=3){
                ans=num[i];
                break;
            }
            }
            else count=1;
        }
        cout<<ans<<endl;
}
}

