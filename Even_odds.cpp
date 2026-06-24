#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,q;
    cin>>n>>q;
    int num[n];
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    while(q--){
        int a;
        cin>>a;
        bool found = false;
        for(int i = 0; i < n; i++){
            if(num[i] == a){
                found=true;
                break;
            }
        }
        if(found) cout<<"found"<<'\n';
        else cout<<"not found"<<'\n';
    }
}

