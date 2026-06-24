#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
         int n;
    cin>>n;
    char ch[n];
    for(int i=0;i<n;i++){
        cin>>ch[i];
    }
    int sum = 0,value=0;

    for(int i=0;i<n;i++){

    if(ch[i] == '(')
        value = 1;
    else if(ch[i] == ')')
    value = -1;
    sum += value;
    }
    if(sum==0){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
}
}
