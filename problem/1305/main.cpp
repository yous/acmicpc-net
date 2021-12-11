#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int BASE = 29;
const int MOD = static_cast<int>(1e9) + 7;

struct Hash {
    vector<int> h, base_p;

    Hash(const string& s) : h(s.size()), base_p(s.size()) {
        int sz = s.size();
        h[0] = s[0];
        base_p[0] = 1;
        for (int i = 1; i < sz; i++) {
            h[i] = (1LL * h[i - 1] * BASE + s[i]) % MOD;
            base_p[i] = 1LL * base_p[i - 1] * BASE % MOD;
        }
    }

    int value(int idx, int len) {
        if (idx == 0) {
            return h[len - 1];
        }
        return (h[idx + len - 1] - 1LL * h[idx - 1] * base_p[len] % MOD + MOD) % MOD;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int L;
    cin >> L;
    string S;
    cin >> S;
    Hash S_hash(S);
    for (int len = 1; len <= L; len++) {
        bool matched = true;
        int rem = L - len;
        for (int i = len; i * 2 <= L; i *= 2) {
            if (S_hash.value(0, i) != S_hash.value(i, i)) {
                matched = false;
                break;
            }
            rem = L - i * 2;
        }
        if (!matched) {
            continue;
        }
        if (rem == 0) {
            cout << len << "\n";
            return 0;
        }
        if (S_hash.value(0, rem) == S_hash.value(L - rem, rem)) {
            cout << len << "\n";
            return 0;
        }
    }
    cout << L << "\n";
    return 0;
}
