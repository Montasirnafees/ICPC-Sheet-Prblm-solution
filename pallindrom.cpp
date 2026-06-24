#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int num[n];
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }

    int temp[n];
    for(int i = 0; i < n; i++){
        temp[i] = num[i];
    }

    reverse(num, num + n);

    bool ok = true;

    for(int i = 0; i < n; i++){
        if(num[i] != temp[i]){
            ok = false;
            break;
        }
    }

    if(ok)
        cout << "YES"<<endl;
    else
        cout << "NO"<<endl;

    return 0;
}
