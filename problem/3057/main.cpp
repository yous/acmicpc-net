#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int BASE = 7;
const int MOD = static_cast<int>(1e9) + 7;
vector<int> base_p;

struct Hash {
    vector<int> h;

    Hash(const string& s) : h(s.size()) {
        int sz = s.size();
        int base_sz = base_p.size();
        if (sz > base_sz) {
            base_p.resize(sz);
            for (int i = base_sz; i < sz; i++) {
                if (i == 0) {
                    base_p[i] = 1;
                    continue;
                }
                base_p[i] = 1LL * base_p[i - 1] * BASE % MOD;
            }
        }
        h[0] = s[0];
        for (int i = 1; i < sz; i++) {
            h[i] = (1LL * h[i - 1] * BASE + s[i]) % MOD;
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
    int R, C;
    cin >> R >> C;
    vector<Hash> row_hash;
    vector<Hash> rev_row_hash;
    for (int i = 0; i < R; i++) {
        string row;
        cin >> row;
        row_hash.emplace_back(row);
        reverse(row.begin(), row.end());
        rev_row_hash.emplace_back(row);
    }
    for (int sq_sz = min(R, C); sq_sz >= 2; sq_sz--) {
        for (int y = 0; y <= R - sq_sz; y++) {
            for (int x = 0; x <= C - sq_sz; x++) {
                bool found = true;
                for (int i = 0; i <= sq_sz / 2; i++) {
                    if (row_hash[y + i].value(x, sq_sz) != rev_row_hash[y + sq_sz - i - 1].value(C - x - sq_sz, sq_sz)) {
                        found = false;
                        break;
                    }
                }
                if (found) {
                    cout << sq_sz << "\n";
                    return 0;
                }
            }
        }
    }
    cout << "-1\n";
    return 0;
}
