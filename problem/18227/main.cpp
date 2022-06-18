#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct SegTree {
    int N;
    vector<int> t;

    SegTree(int n) : N(n), t(n * 2) {}

    void update(int pos, int val) {
        pos += N;
        for (t[pos] += val; pos > 1; pos /= 2) {
            t[pos / 2] = t[pos] + t[pos ^ 1];
        }
    }

    int query(int l, int r) {
        int ans = 0;
        for (l += N, r += N; l < r; l /= 2, r /= 2) {
            if ((l & 1) != 0) {
                ans += t[l++];
            }
            if ((r & 1) != 0) {
                ans += t[--r];
            }
        }
        return ans;
    }
};

void dfs(int u, int p, int& idx, vector<vector<int>>& graph, vector<int>& start_idx, vector<int>& end_idx, vector<int>& depth) {
    start_idx[u] = idx++;
    depth[u] = depth[p] + 1;
    for (int v : graph[u]) {
        if (v == p) {
            continue;
        }
        dfs(v, u, idx, graph, start_idx, end_idx, depth);
    }
    end_idx[u] = idx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, C;
    cin >> N >> C;
    C--;
    vector<vector<int>> graph(N);
    for (int i = 0; i < N - 1; i++) {
        int x, y;
        cin >> x >> y;
        graph[x - 1].emplace_back(y - 1);
        graph[y - 1].emplace_back(x - 1);
    }
    vector<int> start_idx(N);
    vector<int> end_idx(N);
    vector<int> depth(N);
    depth[C] = 1;
    int idx = 0;
    start_idx[C] = idx++;
    for (int v : graph[C]) {
        if (v == C) {
            continue;
        }
        dfs(v, C, idx, graph, start_idx, end_idx, depth);
    }
    end_idx[C] = idx;
    SegTree st(idx + 1);
    int Q;
    cin >> Q;
    while (Q-- > 0) {
        short cmd;
        cin >> cmd;
        int A;
        cin >> A;
        if (cmd == 1) {
            st.update(start_idx[A - 1], 1);
        } else {
            cout << 1LL * st.query(start_idx[A - 1], end_idx[A - 1]) * depth[A - 1] << "\n";
        }
    }
    return 0;
}
