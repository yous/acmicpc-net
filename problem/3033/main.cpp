#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

const int MOD = static_cast<int>(1e9) + 7;

template <int BASE>
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
    int lo = 1;
    int hi = L - 1;
    Hash<29> hash1(S);
    Hash<1187> hash2(S);
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        unordered_set<long long> hash_set;
        bool found = false;
        for (int i = 0; i <= L - mid; i++) {
            long long hash_val = 1LL * hash1.value(i, mid) * MOD + hash2.value(i, mid);
            if (hash_set.find(hash_val) == hash_set.end()) {
                hash_set.insert(hash_val);
            } else {
                found = true;
                break;
            }
        }
        if (found) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << lo - 1 << "\n";
    return 0;
}
