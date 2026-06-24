#include<bits/stdc++.h>
using namespace std;
int main() {
    long long a, b, c, d;
    int result,result = 1;
    cin >> a >> b >> c >> d;

    result = (result * (a % 100)) % 100;
    result = (result * (b % 100)) % 100;
    result = (result * (c % 100)) % 100;
    result = (result * (d % 100)) % 100;

    if(result < 10)
        cout << "0";

    cout << result << endl;

    return 0;
}
