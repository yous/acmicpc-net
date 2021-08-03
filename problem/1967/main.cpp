#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<pair<int, int>>> tree;
vector<int> dist;

int dfs(int u, int s, int w) {
    int ans = u;
    dist[u] = w;
    for (auto [v, nw] : tree[u]) {
        if (s == -1 || v != s) {
            int new_ans = dfs(v, u, w + nw);
            if (dist[ans] < dist[new_ans]) {
                ans = new_ans;
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    tree.resize(N);
    dist.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int parent, child, w;
        cin >> parent >> child >> w;
        tree[parent - 1].emplace_back(child - 1, w);
        tree[child - 1].emplace_back(parent - 1, w);
    }
    int far = dfs(0, -1, 0);
    fill(dist.begin(), dist.end(), 0);
    int another_far = dfs(far, -1, 0);
    cout << dist[another_far] << "\n";
    return 0;
}
