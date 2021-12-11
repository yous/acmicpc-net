#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int BASE = 29;
const int MOD = static_cast<int>(1e9) + 7;

struct Hash {
    vector<int> h, p;

    Hash(const string& s) : h(s.size()), p(s.size()) {
        int sz = s.size();
        h[0] = s[0];
        p[0] = 1;
        for (int i = 1; i < sz; i++) {
            h[i] = (1LL * h[i - 1] * BASE + s[i]) % MOD;
            p[i] = 1LL * p[i - 1] * BASE % MOD;
        }
    }

    int value(int idx, int len) {
        if (idx == 0) {
            return h[len - 1];
        }
        return (h[idx + len - 1] - 1LL * h[idx - 1] * p[len] % MOD + MOD) % MOD;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string S, K;
    cin >> S >> K;
    int S_sz = S.size();
    int alpha_sz = 0;
    for (int i = 0; i < S_sz; i++) {
        if (S[i] < '0' || S[i] > '9') {
            S[alpha_sz] = S[i];
            alpha_sz++;
        }
    }
    S.resize(alpha_sz);
    S_sz = alpha_sz;
    int K_sz = K.size();
    int K_val = Hash(K).value(0, K_sz);
    Hash S_hash = Hash(S);
    bool found = false;
    for (int i = 0; i < S_sz - K_sz + 1; i++) {
        if (S_hash.value(i, K_sz) == K_val) {
            cout << "1\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "0\n";
    }
    return 0;
}
