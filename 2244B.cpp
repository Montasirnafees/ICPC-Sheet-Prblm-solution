#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int sum1=0,sum2=0;
        int num[n];
        for(int i=0;i<n;i++)
        {
            cin>>num[i];
        }
        sort(num,num+n);
        for(int i=0;i<n-1;i+=2)
        {
            sum1+=num[i];
        }
        for(int i=1;i<n-1;i+=2)
        {
            sum2+=num[i];
        }
        if(sum1<sum2)
        {
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
}
