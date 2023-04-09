#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct DisjointSet {
    int N;
    vector<int> group;

    DisjointSet(int n) : N(n), group(n) {
        for (int i = 0; i < N; i++) {
            group[i] = i;
        }
    }

    int find(int n) {
        int g = group[n];
        if (g == n) {
            return g;
        }
        return group[g] = find(g);
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
    vector<tuple<int, int, int>> edges(M);
    for (auto& [T, U, V] : edges) {
        cin >> U >> V >> T;
        U--;
        V--;
    }
    sort(edges.begin(), edges.end());
    DisjointSet ds(N);
    int day = 1;
    for (auto [T, U, V] : edges) {
        if (T != day) {
            break;
        }
        if (!ds.merge(U, V)) {
            break;
        }
        day++;
    }
    cout << day << "\n";
    return 0;
}
