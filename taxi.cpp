#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int num[n],ocount=0,twcount=0,tcount=0,fcount=0,count=0;
    for(int i=0; i<n; i++)
    {
        cin>>num[i];
    }
    sort(num,num+n);
    for(int i=0; i<n; i++)
    {
        if(num[i]==4)
        {
            fcount++;
        }
        else if(num[i]==3)
        {
            tcount++;
        }
        else if(num[i]==2)
        {
            twcount++;
        }
        else ocount++;
    }
    count=fcount;
    if(tcount<twcount)
    {
        count+=tcount;
        ocount=ocount-tcount;
        tcount=0;
    }
    else if(tcount>=ocount)
    {
        count+=ocount;
        tcount=tcount-ocount;
        ocount=0;
    }
    if(tcount>0)
    {
        count+=tcount;
        tcount=0;
    }
    if(twcount>0)
    {
        count+=twcount/2;
        twcount=twcount%2;
    }
        int left = ocount + (twcount*2); // 1 1 2 -> 1 2 group multiply 2;1111
    if(left<=4 && left>0){
        count+=1;
    }else if(left%4 !=0){
        count+= (left/4)+1; /// 1 1 1 1 1 2  2 2 2 2 --> 16 %4=0 --> 4 15 %4 --> 3 + 1
    }else{
        count+= left/4;
    }

    cout<<count<<endl;
}
