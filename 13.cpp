#include<bits/stdc++.h>
using namespace std;

int main()
{
// while(cin >> n && n != 0)
    int n;
    while(cin >> n && n != 0){
            int sum=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            sum+=i*j;
        }
    }
    cout<<sum<<endl;
}


}
