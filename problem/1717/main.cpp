#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;

struct DisjointSet {
    vector<int> group;

    DisjointSet(int N) : group(N) {
        for (int i = 0; i < N; i++) {
            group[i] = i;
        }
    }

    int find(int n) {
        if (n == group[n]) {
            return n;
        }
        return group[n] = find(group[n]);
    }

    bool merge(int p, int q) {
        p = find(p);
        q = find(q);
        if (p != q) {
            group[p] = q;
            return true;
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    DisjointSet ds = DisjointSet(N + 1);
    while (M-- > 0) {
        int cmd, a, b;
        cin >> cmd >> a >> b;
        if (cmd == 0) {
            ds.merge(a, b);
        } else {
            if (ds.find(a) == ds.find(b)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}
