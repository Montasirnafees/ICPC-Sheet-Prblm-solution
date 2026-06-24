#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr,arr + n);
    while(q--) {
        int a;
        cin >> a;

        int s = 0, e = n - 1;
        int ans = -1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (arr[mid] == a) {
                ans = mid;
                break;
            }
            else if (arr[mid] < a) {
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
        }

        if (ans != -1)
            cout << "found"<<endl;
        else
            cout << "not found"<<endl;
    }

    return 0;
}
