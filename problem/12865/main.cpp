#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> weights;
vector<short> values;
vector<vector<int>> cache;

int solve(int idx, int remain) {
    if (idx == N || remain == 0) {
        return 0;
    }
    int& ans = cache[idx][remain - 1];
    if (ans >= 0) {
        return ans;
    }
    ans = solve(idx + 1, remain);
    int weight = weights[idx];
    if (remain >= weight) {
        ans = max(ans, values[idx] + solve(idx + 1, remain - weight));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    int pass = 0;
    for (int i = 0; i < N; i++) {
        int w;
        short v;
        cin >> w >> v;
        if (v == 0) {
            pass++;
            continue;
        }
        weights.push_back(w);
        values.push_back(v);
    }
    N -= pass;
    cache.resize(N, vector<int>(K, -1));
    cout << solve(0, K) << "\n";
    return 0;
}
