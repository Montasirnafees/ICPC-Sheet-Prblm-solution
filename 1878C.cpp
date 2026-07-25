#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,l;
        cin>>n>>k>>x;
        int num[n];
        for(int i=0;i<n;i++)
        {
            cin>>num[i];
        }
        for(int i=n;i>=1;i++)
        {
            sum+=num[i];
            count++;
            if(sum>=x)
                break;
        }

    }
}
