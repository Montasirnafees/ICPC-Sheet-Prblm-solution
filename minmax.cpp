#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int minind = 0, maxind = 0;
    for(int i = 1; i < n; i++){
        if(arr[i] < arr[minind])
            minind = i;

        if(arr[i] > arr[maxind])
            maxind = i;
    }
    swap(arr[minind], arr[maxind]);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
