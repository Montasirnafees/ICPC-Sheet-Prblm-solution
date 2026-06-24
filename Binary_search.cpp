#include<bits/stdc++.h>
using namespace std;
//#define found cout<<"found"<<endl;
//#define not_found cout<<"not found"<<endl;
int main()
{
    int a,b;
    cin>>a>>b;
    int num[a];
    for(int i=0;i<a;i++){
        cin>>num[i];
    }
    while(b--){
        int x;
        cin>>x;
        bool found=false;
        for(int i=0;i<a;i++){
                if(num[i]==x){
                        found=true;
                  break;
                }
        }
       if(found) cout<<"found"<<endl;
        else cout<<"not found"<<endl;
        }
    }

