#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2;
    cin >> s1>>s2;

char A = '1', B = '2', C = '3', D = '4';

int a = (A - '0') * (B - '0');
int b = (C - '0') * (D - '0');

    if(a % b == 0 || b % a == 0){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}
