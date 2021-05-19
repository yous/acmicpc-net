#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

string S;
int alpha[26];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> S;
    for (int i = 0; i < 26; i++) {
        alpha[i] = -1;
    }
    int index = 0;
    for (char c : S) {
        if (alpha[c - 'a'] == -1) {
            alpha[c - 'a'] = index;
        }
        index++;
    }
    for (int i = 0; i < 26; i++) {
        cout << alpha[i];
        if (i < 25) {
            cout << " ";
        } else {
            cout << "\n";
        }
    }
    return 0;
}
