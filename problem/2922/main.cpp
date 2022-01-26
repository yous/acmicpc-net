#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

string S;
int S_sz;

bool is_vowel(char ch) {
    return ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
}

long long solve(int idx, int vowel, bool has_l) {
    if (vowel == 3 || vowel == -3) {
        return 0;
    }
    while (idx < S_sz && S[idx] != '_') {
        if (S[idx] == 'L') {
            has_l = true;
        }
        if (is_vowel(S[idx])) {
            vowel = (vowel > 0) ? vowel + 1 : 1;
        } else {
            vowel = (vowel < 0) ? vowel - 1 : -1;
        }
        if (vowel == 3 || vowel == -3) {
            return 0;
        }
        idx++;
    }
    if (idx == S_sz) {
        return has_l;
    }
    long long ans = 0;
    if (vowel > 0) {
        ans += solve(idx + 1, vowel + 1, has_l) * 5;
        ans += solve(idx + 1, -1, true);
        ans += solve(idx + 1, -1, has_l) * 20;
    } else {
        ans += solve(idx + 1, 1, has_l) * 5;
        ans += solve(idx + 1, vowel - 1, true);
        ans += solve(idx + 1, vowel - 1, has_l) * 20;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> S;
    S_sz = S.size();
    cout << solve(0, 0, false) << "\n";
    return 0;
}
