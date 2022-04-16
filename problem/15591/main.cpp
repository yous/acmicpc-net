#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

struct DisjointSet {
    vector<short> group;
    vector<short> cnt;

    DisjointSet(short n) : group(n), cnt(n, 1) {
        for (int i = 0; i < n; i++) {
            group[i] = i;
        }
    }

    short find(short n) {
        short g = group[n];
        if (g == n) {
            return g;
        }
        return group[n] = find(g);
    }

    bool merge(short p, short q) {
        short gp = find(p);
        short gq = find(q);
        if (gp != gq) {
            group[gq] = gp;
            cnt[gp] += cnt[gq];
            return true;
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N, Q;
    cin >> N >> Q;
    vector<tuple<int, short, short>> edges(N - 1);
    for (auto& [r, p, q] : edges) {
        cin >> p >> q >> r;
        p--;
        q--;
    }
    sort(edges.begin(), edges.end());
    vector<tuple<int, short, short>> queries(Q);
    int idx = 0;
    for (auto& [k, v, i] : queries) {
        cin >> k >> v;
        k = -k;
        i = idx;
        idx++;
    }
    sort(queries.begin(), queries.end());
    vector<short> ans(Q);
    DisjointSet ds(N);
    int hi = N - 1;
    for (auto [k, v, idx] : queries) {
        k = -k;
        int lo = lower_bound(edges.begin(), edges.begin() + hi, make_tuple(k, 0, 0)) - edges.begin();
        for (int i = lo; i < hi; i++) {
            auto [r, p, q] = edges[i];
            ds.merge(p, q);
        }
        ans[idx] = ds.cnt[ds.find(v - 1)] - 1;
        hi = lo;
    }
    for (short num : ans) {
        cout << num << "\n";
    }
    return 0;
}
