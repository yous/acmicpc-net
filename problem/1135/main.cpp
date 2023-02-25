#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solve(int idx, int N, vector<vector<short>>& children, vector<int>& cache) {
    if (idx >= N) {
        return 0;
    }
    auto& ans = cache[idx];
    if (ans >= 0) {
        return ans;
    }
    ans = 0;
    vector<int> times;
    for (auto& child : children[idx]) {
        times.emplace_back(-solve(child, N, children, cache));
    }
    sort(times.begin(), times.end());
    int cur_time = 1;
    for (auto time : times) {
        time = -time;
        ans = max(ans, cur_time + time);
        cur_time++;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N;
    cin >> N;
    vector<short> bosses(N);
    vector<vector<short>> children(N);
    vector<int> cache(N, -1);
    for (int i = 0; i < N; i++) {
        cin >> bosses[i];
        if (bosses[i] != -1) {
            children[bosses[i]].emplace_back(i);
        }
    }
    cout << solve(0, N, children, cache) << "\n";
    return 0;
}
