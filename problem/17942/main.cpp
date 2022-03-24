#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<int> K(N);
    for (int& num : K) {
        cin >> num;
    }
    int R;
    cin >> R;
    vector<vector<pair<int, int>>> graph(N);
    for (int i = 0; i < R; i++) {
        int A, B, D;
        cin >> A >> B >> D;
        graph[A - 1].emplace_back(B - 1, D);
    }
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < N; i++) {
        pq.emplace(-K[i], i);
    }
    vector<bool> visited(N);
    int ans = 0;
    int cnt = 0;
    while (!pq.empty()) {
        auto [k, a] = pq.top();
        k = -k;
        pq.pop();
        if (visited[a]) {
            continue;
        }
        visited[a] = true;
        ans = max(ans, k);
        cnt++;
        if (cnt == M) {
            cout << ans << "\n";
            return 0;
        }
        for (auto [b, d] : graph[a]) {
            if (!visited[b]) {
                K[b] -= d;
                pq.emplace(-K[b], b);
            }
        }
    }
    return 0;
}
