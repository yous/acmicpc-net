#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

const int INF = 1e9;
int N, M;
vector<vector<pair<int, int>>> ADJ;
vector<pair<int, int>> dist;

void spfa(int st, int ed) {
    queue<int> qu;
    vector<bool> in_q(N + 1);
    dist[st] = {0, -1};
    in_q[st] = true;
    qu.push(st);
    while (!qu.empty()) {
        int u = qu.front();
        qu.pop();
        in_q[u] = false;
        for (auto [v, w] : ADJ[u]) {
            if (dist[u].first + w < dist[v].first) {
                dist[v] = {dist[u].first + w, u};
                if (!in_q[v]) {
                    in_q[v] = true;
                    qu.push(v);
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    ADJ.resize(N + 1);
    dist.resize(N + 1, {INF, -1});
    for (int i = 0; i < M; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        ADJ[a].emplace_back(b, w);
    }
    int st, ed;
    cin >> st >> ed;
    spfa(st, ed);
    cout << dist[ed].first << "\n";
    stack<int> track;
    int cur = ed;
    while (cur != st) {
        track.push(cur);
        cur = dist[cur].second;
    }
    cout << track.size() + 1 << "\n";
    cout << st;
    while (!track.empty()) {
        cout << " " << track.top();
        track.pop();
    }
    cout << "\n";
    return 0;
}
