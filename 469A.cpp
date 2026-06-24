#include<bits/stdc++.h>
using namespace std;
int main()
{
    int target,freq[101]={0};
    cin>>target;
    int a;
    cin>>a;
    for(int i=0;i<a;i++){
        int x;
        cin>>x;
        freq[x]=1;
    }
    int b;
    cin>>b;
    for(int i=0;i<b;i++){
        int x;
        cin>>x;
        freq[x]=1;
    }
    for(int i=1;i<=target;i++){
        if(freq[i]==0){
            cout<<"Oh, my keyboard!";
            return 0;
        }
    }
    cout<<"I become the guy.";


}
