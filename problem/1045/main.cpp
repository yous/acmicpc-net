#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct DisjointSet {
    short N;
    vector<short> group;

    DisjointSet(short N) : N(N), group(N) {
        for (short i = 0; i < N; i++) {
            group[i] = i;
        }
    }

    short find(short n) {
        if (n == group[n]) {
            return n;
        }
        return group[n] = find(group[n]);
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
    vector<vector<bool>> graph(N, vector<bool>(N));
    vector<vector<bool>> used(N, vector<bool>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char ch;
            cin >> ch;
            graph[i][j] = (ch == 'Y');
        }
    }
    DisjointSet ds(N);
    vector<short> ans(N);
    short cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (!graph[i][j]) {
                continue;
            }
            if (!ds.merge(i, j)) {
                continue;
            }
            used[i][j] = true;
            ans[i]++;
            ans[j]++;
            cnt++;
        }
    }
    if (cnt < N - 1) {
        cout << "-1\n";
        return 0;
    }
    if (cnt < M) {
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (!graph[i][j]) {
                    continue;
                }
                if (!used[i][j]) {
                    used[i][j] = true;
                    ans[i]++;
                    ans[j]++;
                    cnt++;
                    if (cnt == M) {
                        break;
                    }
                }
            }
            if (cnt == M) {
                break;
            }
        }
    }
    if (cnt < M) {
        cout << "-1\n";
        return 0;
    }
    cout << ans[0];
    for (int i = 1; i < N; i++) {
        cout << " " << ans[i];
    }
    cout << "\n";
    return 0;
}
