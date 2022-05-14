#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct DisjointSet {
    vector<int> group;

    DisjointSet(int n) : group(n) {
        for (int i = 0; i < n; i++) {
            group[i] = i;
        }
    }

    int find(int n) {
        int g = group[n];
        if (g == n) {
            return g;
        }
        return group[n] = find(g);
    }

    bool merge(int p, int q) {
        int gp = find(p);
        int gq = find(q);
        if (gp != gq) {
            group[gp] = gq;
            return true;
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    map<int, int> transitions;
    int trans_idx = 0;
    vector<int> trans_map(N, -1);
    DisjointSet ds(M);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        auto it = transitions.find(u);
        if (it != transitions.end()) {
            int idx = it->second;
            transitions.erase(it);
            if (trans_map[u - 1] == -1) {
                trans_map[u - 1] = idx;
            }
            it = transitions.find(v);
            if (it != transitions.end()) {
                ds.merge(idx, it->second);
            } else {
                transitions.emplace(v, idx);
            }
        } else {
            it = transitions.find(v);
            if (it != transitions.end()) {
                if (trans_map[u - 1] == -1) {
                    trans_map[u - 1] = it->second;
                }
            } else {
                if (trans_map[u - 1] == -1) {
                    trans_map[u - 1] = trans_idx;
                }
                transitions.emplace(v, trans_idx);
                trans_idx++;
            }
        }
    }
    vector<int> result(trans_idx);
    for (auto [v, idx] : transitions) {
        result[ds.find(idx)] = v;
    }
    if (trans_map[0] == -1) {
        cout << 1;
    } else {
        cout << result[ds.find(trans_map[0])];
    }
    for (int i = 1; i < N; i++) {
        if (trans_map[i] == -1) {
            cout << " " << i + 1;
        } else {
            cout << " " << result[ds.find(trans_map[i])];
        }
    }
    cout << "\n";
    return 0;
}
