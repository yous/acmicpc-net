#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;
int T;
int N, M;
vector<vector<pair<int, int>>> ADJ;
int cache[1000];

int solve(int u, int s, int root) {
    int& ans = cache[u];
    if (ans < INF) {
        return ans;
    }
    if (ADJ[u].size() == 1) {
        return ans = root;
    }
    ans = 0;
    for (auto [v, w] : ADJ[u]) {
        if (v == s) {
            continue;
        }
        ans += solve(v, u, w);
    }
    ans = min(ans, root);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T-- > 0) {
        cin >> N >> M;
        ADJ.clear();
        ADJ.resize(N);
        fill(cache, cache + N, INF);
        for (int i = 0; i < M; i++) {
            int a, b, d;
            cin >> a >> b >> d;
            ADJ[a - 1].emplace_back(b - 1, d);
            ADJ[b - 1].emplace_back(a - 1, d);
        }
        int ans = 0;
        for (auto [v, w] : ADJ[0]) {
            ans += solve(v, 0, w);
        }
        cout << ans << "\n";
    }
    return 0;
}
