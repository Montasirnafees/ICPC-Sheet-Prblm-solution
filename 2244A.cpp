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
        int count=0,mx=0;
        char ch[n];
        for(int i=0; i<n; i++)
        {
            cin>>ch[i];
        }
        for(int i=0; i<n; i++)
        {
            if(ch[i]=='#')
                count++;

            else count=0;

        if(count>mx)

                mx = count;
        }

            cout<<(mx+1)/2<<endl;
        }
    }

