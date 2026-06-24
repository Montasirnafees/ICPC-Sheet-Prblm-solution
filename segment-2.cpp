#include<bits/stdc++.h>
using namespace std;
int main()
{
    int count=1;
    string s;
    cin>> s;
    sort(s.begin(),s.end());
    int x = s.size();
    for(int i=0;i<x-1;i++){
        if(s[i]!=s[i+1]){
            count++;
        }
    }
    if(count%2==0){
        cout<<"CHAT WITH HER!";
    }
    else cout<<"IGNORE HIM!";

}
