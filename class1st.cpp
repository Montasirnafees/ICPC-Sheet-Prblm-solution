#include<bits/stdc++.h>
using namespace std;
int main()
{
    int num[4];
    for(int i=0;i<4;i++)
    {
        cin>>num[i];
    }
    int Max = *max_element(num,num+4);
    for(int i=0;i<4;i++)
    {
      if(num[i]!= Max)
      {
          cout<<Max-num[i]<<" ";
      }
    }
    return 0;
}
