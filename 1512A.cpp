#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int a;
        cin>>a;
        int arr[a];
        for(int i=0;i<a;i++){
            cin>>arr[i];
        }
    for(int i = 0; i < a; i++)
    {
        int count = 0;
        for(int j = 0; j < a; j++)
        {
            if(arr[i] == arr[j])
                count++;
        }

        if(count == 1)
        {
            cout << i+1 << endl;
            break;
        }
    }
}
}

