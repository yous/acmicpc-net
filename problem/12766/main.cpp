#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const long long INF = 4e18;
vector<int> dist;
vector<int> dist_rev;
vector<long long> dist_sum;
vector<long long> prefix_sum;
vector<long long> prev_cache;
vector<long long> cur_cache;

void dijkstra(short st, vector<vector<pair<short, short>>>& graph, vector<int>& dist) {
    priority_queue<pair<int, short>> pq;
    dist[st] = 0;
    pq.emplace(0, st);
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        d = -d;
        pq.pop();
        if (dist[u] < d) {
            continue;
        }
        for (auto [v, w] : graph[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.emplace(-(d + w), v);
            }
        }
    }
}

long long cost(int l, int r) {
    return (prefix_sum[r + 1] - prefix_sum[l]) * (r - l);
}

void solve(int l, int r, int optl, int optr) {
    if (l > r) {
        return;
    }
    int mid = (l + r) / 2;
    pair<long long, int> opt = {INF, -1};
    for (int i = optl, ed = min(optr, mid); i <= ed; i++) {
        opt = min(opt, {(i > 0 ? prev_cache[i - 1] : 0) + cost(i, mid), i});
    }
    cur_cache[mid] = opt.first;
    solve(l, mid - 1, optl, opt.second);
    solve(mid + 1, r, opt.second, optr);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N, B, S;
    int R;
    cin >> N >> B >> S >> R;
    vector<vector<pair<short, short>>> graph(N);
    vector<vector<pair<short, short>>> graph_rev(N);
    for (int i = 0; i < R; i++) {
        short u, v, l;
        cin >> u >> v >> l;
        graph[u - 1].emplace_back(v - 1, l);
        graph_rev[v - 1].emplace_back(u - 1, l);
    }
    dist.resize(N, 1e9);
    dist_rev.resize(N, 1e9);
    dijkstra(B, graph, dist);
    dijkstra(B, graph_rev, dist_rev);
    dist_sum.resize(B);
    for (int i = 0; i < B; i++) {
        dist_sum[i] = dist[i] + dist_rev[i];
    }
    sort(dist_sum.begin(), dist_sum.end());
    prefix_sum.resize(B + 1);
    long long sum = 0;
    for (int i = 0; i < B; i++) {
        sum += dist_sum[i];
        prefix_sum[i + 1] = sum;
    }
    prev_cache.resize(B);
    cur_cache.resize(B);
    for (int i = 0; i < B; i++) {
        prev_cache[i] = cost(0, i);
    }
    for (int i = 1; i < S; i++) {
        solve(0, B - 1, 0, B - 1);
        swap(prev_cache, cur_cache);
    }
    cout << prev_cache[B - 1] << "\n";
    return 0;
}
