#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct DisjointSet {
    vector<int> group;
    vector<int> cnt;

    DisjointSet(int n) : group(n), cnt(n, 1) {
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

    int merge(int gp, int gq, bool ally) {
        if (gp != gq) {
            if (ally) {
                group[gq] = gp;
                cnt[gp] += cnt[gq];
                return 2;
            } else {
                if (cnt[gp] > cnt[gq]) {
                    group[gq] = gp;
                    cnt[gp] -= cnt[gq];
                    return 2;
                } else if (cnt[gp] < cnt[gq]) {
                    group[gp] = gq;
                    cnt[gq] -= cnt[gp];
                    return 1;
                } else {
                    return 3;
                }
            }
        }
        return 0;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    DisjointSet ds(N);
    for (int i = 0; i < N; i++) {
        cin >> ds.cnt[i];
    }
    int cnt = N;
    vector<bool> survived(N, true);
    for (int i = 0; i < M; i++) {
        int O, P, Q;
        cin >> O >> P >> Q;
        int gp = ds.find(P - 1);
        int gq = ds.find(Q - 1);
        int dead = ds.merge(gp, gq, O == 1);
        if ((dead & 1) != 0) {
            cnt--;
            survived[gp] = false;
        }
        if ((dead & 2) != 0) {
            cnt--;
            survived[gq] = false;
        }
    }
    cout << cnt << "\n";
    if (cnt == 0) {
        return 0;
    }
    vector<int> remains(cnt);
    int idx = 0;
    for (int i = 0; i < N; i++) {
        if (survived[i]) {
            remains[idx] = ds.cnt[i];
            idx++;
        }
    }
    sort(remains.begin(), remains.end());
    cout << remains[0];
    for (int i = 1; i < cnt; i++) {
        cout << " " << remains[i];
    }
    cout << "\n";
    return 0;
}
