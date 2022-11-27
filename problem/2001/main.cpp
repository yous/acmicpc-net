#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N, M, K;
    cin >> N >> M >> K;
    vector<bool> has_jewel(N);
    vector<short> jewels;
    for (int i = 0; i < K; i++) {
        short num;
        cin >> num;
        has_jewel[num - 1] = true;
        jewels.emplace_back(num - 1);
    }
    vector<vector<short>> dist(N, vector<short>(N, -1));
    for (int i = 0; i < M; i++) {
        short a, b, c;
        cin >> a >> b >> c;
        dist[a - 1][b - 1] = c;
        dist[b - 1][a - 1] = c;
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            if (dist[i][k] == -1) {
                continue;
            }
            for (int j = 0; j < N; j++) {
                dist[i][j] = max(dist[i][j], min(dist[i][k], dist[k][j]));
            }
        }
    }
    short ans = 0;
    queue<int> qu;
    set<int> visited;
    for (int i = 0; i < K; i++) {
        if (jewels[i] == 0) {
            continue;
        }
        int num = (1 << i) * N + jewels[i];
        qu.emplace(num);
        visited.emplace(num);
    }
    short step = 1;
    while (!qu.empty()) {
        auto sz = qu.size();
        while (sz-- > 0) {
            auto num = qu.front();
            int mask = num / N;
            short u = num % N;
            qu.pop();
            ans = max(ans, min(step, dist[u][0]));
            for (int i = 0; i < K; i++) {
                if (jewels[i] == 0 || jewels[i] == u) {
                    continue;
                }
                if ((mask & (1 << i)) != 0) {
                    continue;
                }
                if (dist[u][jewels[i]] < step) {
                    continue;
                }
                int new_num = (mask | (1 << i)) * N + jewels[i];
                auto it = visited.lower_bound(new_num);
                if (it != visited.end() && *it == new_num) {
                    continue;
                } else {
                    qu.emplace(new_num);
                    visited.emplace_hint(it, new_num);
                }
            }
        }
        step++;
    }
    if (has_jewel[0]) {
        ans++;
    }
    cout << ans << "\n";
    return 0;
}
