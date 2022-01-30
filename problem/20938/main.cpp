#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<double> bulbs;
vector<double> cache;
vector<vector<double>> probs;

double solve(int pos, int chunk_cnt) {
    if (pos >= N) {
        return 0.0;
    }
    if (chunk_cnt < 0) {
        return 0.0;
    }
    double& ans = cache[pos * 10 + chunk_cnt];
    if (ans >= 0.0) {
        return ans;
    }
    ans = 0.0;
    for (int i = pos + 1; i <= N; i++) {
        ans = max(ans, probs[i - 1][pos] + solve(i, chunk_cnt - 1));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    bulbs.resize(N);
    for (double& bulb: bulbs) {
        cin >> bulb;
    }
    cache.resize(N * 10, -1.0);
    probs.resize(N, vector<double>(N));
    for (int i = N - 1; i >= 0; i--) {
        double prob = 0.0;
        for (int j = i; j >= 0; j--) {
            prob = (1.0 - bulbs[j]) * (1.0 + prob);
            probs[i][j] = prob;
        }
    }
    cout.precision(7);
    cout << fixed << solve(0, K - 1) << "\n";
    return 0;
}
