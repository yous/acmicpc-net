#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int alpha[26];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    for (char c : s) {
        if (c >= 'a') {
            alpha[c - 'a']++;
        } else {
            alpha[c - 'A']++;
        }
    }
    char ans;
    int max = -1;
    int count = 0;
    for (int i = 0; i < 26; i++) {
        if (alpha[i] > max) {
            max = alpha[i];
            ans = i + 'A';
            count = 1;
        } else if (alpha[i] == max) {
            count++;
        }
    }
    if (count > 1) {
        cout << "?\n";
    } else {
        cout << ans << "\n";
    }
    return 0;
}
