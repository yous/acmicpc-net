#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct DisjointSet {
    int N;
    vector<int> group;
    vector<int> cnt;
    vector<int> sum;

    DisjointSet(int n) : N(n), group(n), cnt(n, 1), sum(n) {
        for (int i = 0; i < N; i++) {
            group[i] = i;
        }
    }

    int find(int n) {
        int g = group[n];
        if (g == n) {
            return g;
        }
        return group[g] = find(g);
    }

    bool merge(int p, int q) {
        int gp = find(p);
        int gq = find(q);
        if (gp != gq) {
            group[gp] = gq;
            cnt[gq] += cnt[gp];
            sum[gq] += sum[gp];
            return true;
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N;
    int M;
    short K;
    cin >> N >> M >> K;
    DisjointSet ds(N);
    for (auto& num : ds.sum) {
        cin >> num;
    }
    for (int i = 0; i < M; i++) {
        short a, b;
        cin >> a >> b;
        ds.merge(a - 1, b - 1);
    }
    vector<pair<int, int>> groups;
    for (int i = 0; i < N; i++) {
        if (ds.group[i] != i) {
            continue;
        }
        if (ds.cnt[i] >= K) {
            continue;
        }
        groups.emplace_back(ds.cnt[i], ds.sum[i]);
    }
    vector<int> cache(K, 0);
    for (auto [cnt, sum] : groups) {
        for (int k = K - 1; k >= 1; k--) {
            if (cnt <= k) {
                cache[k] = max(cache[k], cache[k - cnt] + sum);
            }
        }
    }
    cout << cache[K - 1] << "\n";
    return 0;
}
