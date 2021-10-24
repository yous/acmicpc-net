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
        if (scc_num[v] > 0) {
            continue;
        }
        if (label[v] == 0) {
            res = min(res, dfs(v));
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
    graph.resize(M * 2 + 1);
    label.resize(M * 2 + 1);
    scc_num.resize(M * 2 + 1);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        graph[M - x].emplace_back(M + y);
        graph[M - y].emplace_back(M + x);
    }
    for (int u = -M; u <= M; u++) {
        if (u == 0) {
            continue;
        }
        if (label[M + u] == 0) {
            dfs(M + u);
        }
    }
    bool can_make = true;
    for (int u = 1; u <= M; u++) {
        if (scc_num[M - u] == scc_num[M + u]) {
            can_make = false;
            cout << "OTL\n";
            break;
        }
    }
    if (can_make) {
        cout << "^_^\n";
    }
    return 0;
}
