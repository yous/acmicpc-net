#include <algorithm>
#include <cmath>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

short N, S;

short solve(int idx, vector<tuple<int, short, short>>& moles, vector<short>& cache) {
    if (idx >= N) {
        return 0;
    }
    auto& ans = cache[idx];
    if (ans >= 0) {
        return ans;
    }
    ans = 1;
    auto [T, x, y] = moles[idx];
    for (int i = idx + 1; i < N; i++) {
        auto [T_o, x_o, y_o] = moles[i];
        if (sqrt((x_o - x) * (x_o - x) + (y_o - y) * (y_o - y)) <= 1LL * S * (T_o - T)) {
            ans = max(ans, short(1 + solve(i, moles, cache)));
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> S;
    vector<tuple<int, short, short>> moles(N);
    for (auto& [T, x, y] : moles) {
        cin >> x >> y >> T;
    }
    sort(moles.begin(), moles.end());
    vector<short> cache(N, -1);
    short ans = 0;
    for (int i = 0; i < N; i++) {
        auto [T, x, y] = moles[i];
        if (sqrt(x * x + y * y) <= 1LL * S * T) {
            ans = max(ans, solve(i, moles, cache));
        }
    }
    cout << ans << "\n";
    return 0;
}
