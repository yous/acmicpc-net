#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<pair<int, int>>> slopes;
vector<int> cache;

int solve(int start) {
    int& ans = cache[start];
    if (ans >= 0) {
        return ans;
    }
    ans = 0;
    for (auto& [v, c] : slopes[start]) {
        ans = max(ans, c + solve(v));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    slopes.resize(N);
    cache.resize(N, -1);
    for (int i = 0; i < M; i++) {
        int s, t, c;
        cin >> s >> t >> c;
        slopes[s - 1].emplace_back(t - 1, c);
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, solve(i));
    }
    cout << ans << "\n";
    return 0;
}
