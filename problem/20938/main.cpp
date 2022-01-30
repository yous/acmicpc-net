#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<double> bulbs;
vector<double> cache;

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
    double prob = 1.0;
    double num = 0.0;
    for (int i = pos; i < N; i++) {
        prob *= (1.0 - bulbs[i]);
        num += prob;
        ans = max(ans, num + solve(i + 1, chunk_cnt - 1));
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
    cout.precision(7);
    cout << fixed << solve(0, K - 1) << "\n";
    return 0;
}
