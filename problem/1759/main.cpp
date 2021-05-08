#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L;
int C;
char chars[15];

void solve(int index, int vowel, int consonant, string& str) {
    if (index == C) {
        if (vowel + consonant == L && vowel >= 1 && consonant >= 2) {
            cout << str << "\n";
        }
        return;
    }
    str.push_back(chars[index]);
    switch (chars[index]) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            solve(index + 1, vowel + 1, consonant, str);
            break;
        default:
            solve(index + 1, vowel, consonant + 1, str);
            break;
    }
    str.pop_back();
    solve(index + 1, vowel, consonant, str);
}

int main() {
    int i;
    cin >> L >> C;
    for (i = 0; i < C; i++) {
        cin >> chars[i];
    }
    sort(&chars[0], &chars[C]);
    string s = "";
    solve(0, 0, 0, s);
    return 0;
}
