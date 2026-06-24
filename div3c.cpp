#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int num[n];
        for(int i=0;i<n;i++) {
            cin>>num[i];
        }
        int num6[n], num2[n], num3[n], na[n];
        int c6 = 0, c2 = 0, c3 = 0, ca = 0;

        for (int i=0;i<n;i++) {
            int x=num[i];

            if (x % 6 == 0) {
                num6[c6] = x;
                c6++;
            }
            else if (x % 2 == 0) {
                num2[c2] = x;
                c2++;
            }
            else if (x % 3 == 0) {
                num3[c3] = x;
                c3++;
            }
            else {
                na[ca] = x;
                ca++;
            }
        }

        for(int i=0;i<c6;i++){
            cout << num6[i] << " ";
        }
        for(int i=0;i<c3;i++){
            cout << num3[i] << " ";
        }
        for(int i=0;i<ca;i++){
            cout << na[i] << " ";
        }
        for(int i=0;i<c2;i++){
            cout << num2[i] << " ";
        }

        cout << endl;
    }
    return 0;
}
