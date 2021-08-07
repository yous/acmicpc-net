#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M, R;
vector<int> items;
vector<vector<pair<int, int>>> ADJ;

int solve(int u, int m, vector<int>& dist) {
    if (dist[u] > m) {
        return 0;
    }
    int res;
    if (dist[u] == -1) {
        res = items[u];
    } else {
        res = 0;
    }
    dist[u] = m;
    for (auto [v, w] : ADJ[u]) {
        if (w <= m && m - w >= dist[v]) {
            res += solve(v, m - w, dist);
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> R;
    items.resize(N);
    ADJ.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> items[i];
    }
    for (int i = 0; i < R; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        ADJ[a - 1].emplace_back(b - 1, l);
        ADJ[b - 1].emplace_back(a - 1, l);
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        vector<int> dist(N, -1);
        ans = max(ans, solve(i, M, dist));
    }
    cout << ans << "\n";
    return 0;
}
