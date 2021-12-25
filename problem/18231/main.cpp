#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u - 1].emplace_back(v - 1);
        graph[v - 1].emplace_back(u - 1);
    }
    int K;
    cin >> K;
    vector<bool> destroyed(N);
    for (int i = 0; i < K; i++) {
        int num;
        cin >> num;
        destroyed[num - 1] = true;
    }
    vector<int> selected;
    vector<bool> covered(N);
    int cnt = 0;
    for (int u = 0; u < N; u++) {
        if (!destroyed[u]) {
            continue;
        }
        vector<bool> tmp(covered);
        tmp[u] = true;
        bool cover = true;
        for (auto v : graph[u]) {
            if (!destroyed[v]) {
                cover = false;
                break;
            }
            tmp[v] = true;
        }
        if (cover) {
            covered = tmp;
            cnt++;
            selected.emplace_back(u + 1);
        }
    }
    bool found = true;
    for (int i = 0; i < N; i++) {
        if (destroyed[i] != covered[i]) {
            found = false;
            break;
        }
    }
    if (found) {
        cout << cnt << "\n";
        cout << selected[0];
        for (int i = 1; i < cnt; i++) {
            cout << " " << selected[i];
        }
        cout << "\n";
    } else {
        cout << "-1\n";
    }
    return 0;
}
