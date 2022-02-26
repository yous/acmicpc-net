#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, D;
vector<int> temps;
vector<int> values;
long long ans = 0;

long long cost(int l, int r) {
    return 1LL * (r - l) * temps[r] + values[l];
}

void solve(int l, int r, int optl, int optr) {
    if (l > r) {
        return;
    }
    int mid = (l + r) / 2;
    pair<long long, int> opt = {0, -1};
    for (int i = max(optl, mid - D), ed = min(optr, mid); i <= ed; i++) {
        opt = max(opt, {cost(i, mid), i});
    }
    ans = max(ans, opt.first);
    solve(l, mid - 1, optl, opt.second);
    solve(mid + 1, r, opt.second, optr);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> D;
    temps.resize(N);
    for (int& num : temps) {
        cin >> num;
    }
    values.resize(N);
    for (int& num : values) {
        cin >> num;
    }
    solve(0, N - 1, 0, N - 1);
    cout << ans << "\n";
    return 0;
}
