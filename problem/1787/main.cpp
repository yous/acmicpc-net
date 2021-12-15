#include <algorithm>
#include <iostream>
#include <set>
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
    int N;
    cin >> N;
    string S;
    cin >> S;
    Hash S_hash = Hash(S);
    vector<pair<int, int>> lengths;
    for (int i = 0; i < N - 1; i++) {
        int lo = i + 1;
        int hi = min((i + 1) * 2, N) - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (S_hash.value(0, mid - i) == S_hash.value(i + 1, mid - i)) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        int end = lo;
        if (end > i + 1) {
            lengths.emplace_back(i + 1, i + 1);
            lengths.emplace_back(end, -(i + 1));
        }
    }
    sort(lengths.begin(), lengths.end());
    long long ans = 0;
    set<int> se;
    auto it = lengths.begin();
    for (int i = 1; i < N; i++) {
        while (it != lengths.end() && it->first == i) {
            if (it->second < 0) {
                se.erase(-it->second);
            } else {
                se.emplace(it->second);
            }
            it++;
        }
        if (!se.empty()) {
            ans += *se.rbegin();
        }
    }
    cout << ans << "\n";
    return 0;
}
