#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, L;
vector<int> cities;
int cache[1001][1001][2];

int solve(int left_hi, int right_lo, bool on_left) {
    if (left_hi < 0 && right_lo >= N) {
        return 0;
    }
    int& ans = cache[left_hi + 1][right_lo + 1][on_left ? 1 : 0];
    if (ans > 0) {
        return ans;
    }
    int cur_idx = on_left ? left_hi + 1 : right_lo - 1;
    int remain_cnt = left_hi + 1 + N - right_lo;
    if (left_hi < 0) {
        ans = (cities[right_lo] - cities[cur_idx]) * remain_cnt + solve(left_hi, right_lo + 1, false);
    } else if (right_lo >= N) {
        ans = (cities[cur_idx] - cities[left_hi]) * remain_cnt + solve(left_hi - 1, right_lo, true);
    } else {
        ans = min((cities[cur_idx] - cities[left_hi]) * remain_cnt + solve(left_hi - 1, right_lo, true),
                  (cities[right_lo] - cities[cur_idx]) * remain_cnt + solve(left_hi, right_lo + 1, false));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        cities.push_back(n);
    }
    sort(cities.begin(), cities.end());
    int cur_idx = lower_bound(cities.begin(), cities.end(), L) - cities.begin();
    int ans;
    if (cur_idx == 0) {
        ans = (cities[cur_idx] - L) * N + solve(cur_idx - 1, cur_idx + 1, false);
    } else if (cur_idx == N) {
        ans = (L - cities[cur_idx - 1]) * N + solve(cur_idx - 2, cur_idx, true);
    } else if (cities[cur_idx] == L) {
        ans = solve(cur_idx - 1, cur_idx + 1, true);
    } else {
        ans = min((L - cities[cur_idx - 1]) * N + solve(cur_idx - 2, cur_idx, true),
                  (cities[cur_idx] - L) * N + solve(cur_idx - 1, cur_idx + 1, false));
    }
    cout << ans << "\n";
    return 0;
}
