#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        string temp = s;
        sort(s.begin(), s.end());
        if(s == temp){
            cout << "YES"<<endl;
        }
        else{
            cout << "NO"<<endl;
        }
    }
}
