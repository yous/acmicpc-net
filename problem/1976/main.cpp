#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct DisjointSet {
    vector<short> group;

    DisjointSet(short n) : group(n) {
        for (int i = 0; i < n; i++) {
            group[i] = i;
        }
    }

    short find(short n) {
        short g = group[n];
        if (g == n) {
            return g;
        }
        return group[n] = find(g);
    }

    bool merge(short p, short q) {
        short gp = find(p);
        short gq = find(q);
        if (gp != gq) {
            group[gq] = gp;
            return true;
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N, M;
    cin >> N >> M;
    bool graph[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int num;
            cin >> num;
            graph[i][j] = (num == 1);
        }
    }
    DisjointSet ds(N);
    for (int u = 0; u < N - 1; u++) {
        for (int v = u + 1; v < N; v++) {
            if (graph[u][v]) {
                ds.merge(u, v);
            }
        }
    }
    short prev_num;
    cin >> prev_num;
    for (int i = 1; i < M; i++) {
        short num;
        cin >> num;
        if (ds.find(prev_num - 1) != ds.find(num - 1)) {
            cout << "NO\n";
            return 0;
        }
        prev_num = num;
    }
    cout << "YES\n";
    return 0;
}
