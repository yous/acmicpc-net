#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;

struct DisjointSet {
    vector<int> group;

    DisjointSet(int n) : group(n) {
        for (int i = 0; i < n; i++) {
            group[i] = i;
        }
    }

    int find(int n) {
        int& g = group[n];
        if (n == g) {
            return n;
        }
        return g = find(g);
    }

    bool merge(int p, int q) {
        int gp = find(p);
        int gq = find(q);
        if (gp != gq) {
            group[gp] = gq;
            return false;
        } else {
            return true;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    DisjointSet ds(N);
    int ans = 0;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        if (ans == 0 && ds.merge(a, b)) {
            ans = i + 1;
        }
    }
    cout << ans << "\n";
    return 0;
}
