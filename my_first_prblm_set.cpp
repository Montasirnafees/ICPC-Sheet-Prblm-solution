#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        long long l,t;
        cin >>l>>t;
        long long cost = l * 120;
        if (t < cost) {
            cout << "NOT ENOUGH MONEY " << (cost - t) << "\n";
        }
        else {
            long long trips = (l + 1) / 2;
            long long total_hours = (trips - 1) * 2;
            long long start_hour = 10 - total_hours;
            start_hour = (start_hour % 24 + 24) % 24;

            if (start_hour < 10) cout << "YES 0" << start_hour << ":00\n";
            else cout << "YES " << start_hour << ":00\n";
        }
    }

    return 0;
}
