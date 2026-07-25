#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,pow=1;
        cin>>n;
        vector<int> v;
        while(n>0)
        {
            if(n%10>0)
            {
                v.push_back((n%10)*pow);
            }
            n = n/10;
            pow *= 10;
        }
        cout<<v.size()<<endl;
        for(auto num : v){
            cout<<num<<" ";
        }
        cout<<endl;
    }
}
