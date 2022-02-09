#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<pair<int, int>> slopes(N);
    for (auto& [a, b] : slopes) {
        int c;
        cin >> a >> b >> c;
        if (a < 0) {
            a = -a;
            b = -b;
        }
    }
    sort(slopes.begin(), slopes.end(), [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
        return 1LL * lhs.first * rhs.second < 1LL * rhs.first * lhs.second;
    });
    long long ans = 1LL * N * (N - 1) / 2;
    pair<int, int>* prev_slope = &slopes[0];
    int cnt = 1;
    for (int i = 1; i < N; i++) {
        auto& [a, b] = slopes[i];
        if (1LL * prev_slope->first * b == 1LL * a * prev_slope->second) {
            cnt++;
        } else {
            ans -= 1LL * cnt * (cnt - 1) / 2;
            cnt = 1;
        }
        prev_slope = &slopes[i];
    }
    if (cnt > 1) {
        ans -= 1LL * cnt * (cnt - 1) / 2;
    }
    cout << ans << "\n";
    return 0;
}
