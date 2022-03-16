#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

struct DisjointSet {
    vector<short> group;

    DisjointSet(short n) : group(n) {
        iota(group.begin(), group.end(), 0);
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
            return true;
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N;
    cin >> N;
    int M;
    cin >> M;
    priority_queue<tuple<short, short, short>> pq;
    for (int i = 0; i < M; i++) {
        short a, b, c;
        cin >> a >> b >> c;
        pq.emplace(-c, a - 1, b - 1);
    }
    DisjointSet ds(N);
    int ans = 0;
    int cnt = 0;
    while (cnt < N - 1) {
        auto [c, a, b] = pq.top();
        c = -c;
        pq.pop();
        if (ds.merge(a, b)) {
            ans += c;
            cnt++;
        }
    }
    cout << ans << "\n";
    return 0;
}
