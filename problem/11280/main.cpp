#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> graph;
vector<int> label;
int cnt = 1;
vector<int> scc_num;
int scc_cnt = 0;
stack<int> st;

int dfs(int u) {
    label[u] = cnt++;
    int res = label[u];
    st.emplace(u);
    for (int v : graph[u]) {
        if (scc_num[v] != 0) {
            continue;
        }
        if (label[v] == 0) {
            int vtop = dfs(v);
            res = min(res, vtop);
        } else {
            res = min(res, label[v]);
        }
    }
    if (res == label[u]) {
        scc_cnt++;
        while (true) {
            int v = st.top();
            st.pop();
            scc_num[v] = scc_cnt;
            if (v == u) {
                break;
            }
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    graph.resize(N * 2 + 1);
    label.resize(N * 2 + 1);
    scc_num.resize(N * 2 + 1);
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        graph[N - x].emplace_back(N + y);
        graph[N - y].emplace_back(N + x);
    }
    for (int u = -N; u <= N; u++) {
        if (u == 0) {
            continue;
        }
        if (label[N + u] == 0) {
            dfs(N + u);
        }
    }
    bool can_make = true;
    for (int u = 1; u <= N; u++) {
        if (scc_num[N - u] == scc_num[N + u]) {
            can_make = false;
            cout << "0\n";
            break;
        }
    }
    if (can_make) {
        cout << "1\n";
    }
    return 0;
}
