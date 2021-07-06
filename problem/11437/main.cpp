#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> ADJ;
vector<int> rev_idx;

struct SegTree {
    int N;
    vector<pair<int, int>> t;

    SegTree(int n) : N(n), t(n * 2) {}

    void build(void) {
        for (int i = N - 1; i >= 0; i--) {
            t[i] = min(t[i * 2], t[i * 2 + 1]);
        }
    }

    int query(int l, int r) {
        pair<int, int> ans = t[l + N];
        for (l += N, r += N; l < r; l /= 2, r /= 2) {
            if (l & 1) {
                ans = min(ans, t[l++]);
            }
            if (r & 1) {
                ans = min(ans, t[--r]);
            }
        }
        return ans.second;
    }
};

int dfs(int s, int e, int idx, int depth, vector<pair<int, int>>& t) {
    t[idx] = {depth, s};
    rev_idx[s] = idx - (N * 2 - 1);
    idx++;
    for (int v : ADJ[s]) {
        if (v != e) {
            idx = dfs(v, s, idx, depth + 1, t);
            t[idx] = {depth, s};
            idx++;
        }
    }
    return idx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    ADJ.resize(N + 1);
    rev_idx.resize(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        ADJ[u].push_back(v);
        ADJ[v].push_back(u);
    }
    SegTree st(N * 2 - 1);
    dfs(1, 0, N * 2 - 1, 0, st.t);
    st.build();
    cin >> M;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        int u_idx = rev_idx[u];
        int v_idx = rev_idx[v];
        if (u_idx > v_idx) {
            swap(u_idx, v_idx);
        }
        cout << st.query(u_idx, v_idx) << "\n";
    }
    return 0;
}
