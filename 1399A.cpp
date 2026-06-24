#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,i;
        cin>>n;
        int num[n];

        for(i=0;i<n;i++){
            cin>>num[i];
        }
        sort(num,num+n);
        int mx=*max_element(num,num+n);
        int mn=*min_element(num,num+n);
        if((mx-mn)<=1){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
}
