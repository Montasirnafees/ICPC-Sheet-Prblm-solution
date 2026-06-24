#include<bits/stdc++.h>
using namespace std;
int main() {
    char word[100];
    cin>>word;
    int freq[26] = {0};
    for(int i = 0; word[i] != '\0'; i++) {
        freq[word[i] - 'A']++;
    }
    int first = 0;
    for(int i = 0; i < 26; i++) {
        if(freq[i] != 0) {
            first = freq[i];
            break;
        }
    }
    bool ok = true;
    for(int i = 0; i < 26; i++) {
        if(freq[i] != 0 && freq[i] != first) {
            ok = false;
            break;
        }
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}

