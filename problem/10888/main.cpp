#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;

struct DisjointSet {
    vector<int> group;
    vector<int> cnt;

    DisjointSet(int N) : group(N), cnt(N, 1) {
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

    pair<int, int> merge(int p, int q) {
        int gp = find(p);
        int gq = find(q);
        if (gp != gq) {
            group[gp] = group[gq];
            auto res = make_pair(cnt[gp], cnt[gq]);
            cnt[gq] += cnt[gp];
            return res;
        }
        return make_pair(0, 0);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    DisjointSet ds(N);
    long long pairs = 0;
    long long bridges = 0;
    for (int i = 0; i < N - 1; i++) {
        int num;
        cin >> num;
        auto [gp, gq] = ds.merge(num - 1, num);
        pairs += 1LL * (gp + gq) * (gp + gq + 1) / 2 - 1LL * gp * (gp + 1) / 2 - 1LL * gq * (gq + 1) / 2;
        bridges += 1LL * (gp + gq - 1) * (gp + gq) * (gp + gq + 1) / 6;
        bridges -= 1LL * (gp - 1) * gp * (gp + 1) / 6;
        bridges -= 1LL * (gq - 1) * gq * (gq + 1) / 6;
        cout << pairs << " " << bridges << "\n";
    }
    return 0;
}
