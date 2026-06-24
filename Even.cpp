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
        int count1=0,count2=0;
        for( i=0;i<n;i+=2){
            if(num[i]%2!=0){
                count1++;
            }
        }
         for( i=1;i<n;i+=2){
            if(num[i]%2==0){
                count2++;
            }
        }

        if(count1 != count2){
            cout<<"-1"<<endl;
        }
        else {cout<<count1<<endl;
        }
    }
    return 0;
}


