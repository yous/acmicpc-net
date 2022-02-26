#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const long long INF = 4e18;
vector<long long> prefix_sum;
vector<vector<long long>> cache;

long long cost(int l, int r) {
    return (prefix_sum[r + 1] - prefix_sum[l]) * (r - l + 1);
}

void solve(int cnt, int l, int r, int optl, int optr) {
    if (l > r) {
        return;
    }
    int mid = (l + r) / 2;
    pair<long long, int> opt = {INF, -1};
    for (int i = optl, ed = min(optr, mid); i <= ed; i++) {
        opt = min(opt, {(i > 0 ? cache[cnt - 1][i - 1] : 0) + cost(i, mid), i});
    }
    cache[cnt][mid] = opt.first;
    solve(cnt, l, mid - 1, optl, opt.second);
    solve(cnt, mid + 1, r, opt.second, optr);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short L, G;
    cin >> L >> G;
    vector<int> C(L);
    prefix_sum.resize(L + 1);
    long long sum = 0;
    for (int i = 0; i < L; i++) {
        cin >> C[i];
        sum += C[i];
        prefix_sum[i + 1] = sum;
    }
    cache.resize(G, vector<long long>(L));
    for (int i = 0; i < L; i++) {
        cache[0][i] = cost(0, i);
    }
    for (int i = 1; i < G; i++) {
        solve(i, 0, L - 1, 0, L - 1);
    }
    cout << cache[G - 1][L - 1] << "\n";
    return 0;
}
