#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct DisjointSet {
    int N;
    vector<int> group;

    DisjointSet(int n) : N(n), group(n) {
        for (int i = 0; i < n; i++) {
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
    int ans = N * M;
    DisjointSet ds(N * M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char ch;
            cin >> ch;
            int other = 0;
            switch (ch) {
                case 'U':
                    other = (i - 1) * M + j;
                    break;
                case 'D':
                    other = (i + 1) * M + j;
                    break;
                case 'L':
                    other = i * M + j - 1;
                    break;
                case 'R':
                    other = i * M + j + 1;
                    break;
            }
            if (ds.merge(i * M + j, other)) {
                ans--;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
