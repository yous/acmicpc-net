#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

short solve(int idx, short N, vector<pair<double, double>>& diamonds, vector<short>& cache) {
    if (idx >= N) {
        return 0;
    }
    auto& ans = cache[idx];
    if (ans >= 0) {
        return ans;
    }
    ans = 1;
    auto [w, c] = diamonds[idx];
    for (int i = idx + 1; i < N; i++) {
        auto [w_o, c_o] = diamonds[i];
        if (w < w_o && c > c_o) {
            ans = max(ans, short(1 + solve(i, N, diamonds, cache)));
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short T;
    cin >> T;
    while (T-- > 0) {
        short N;
        cin >> N;
        vector<pair<double, double>> diamonds(N);
        for (auto& [w, c] : diamonds) {
            cin >> w >> c;
        }
        vector<short> cache(N, -1);
        short ans = 0;
        for (int i = 0; i < N; i++) {
            ans = max(ans, solve(i, N, diamonds, cache));
        }
        cout << ans << "\n";
    }
    return 0;
}
