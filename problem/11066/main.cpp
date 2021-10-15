#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 2e9;
int T;
int K;
vector<int> files;
vector<int> prefix_sum;
int cache[500][500];

int solve(int lo, int hi) {
    int& ans = cache[lo][hi];
    if (ans >= 0) {
        return ans;
    }
    if (lo == hi) {
        return ans = 0;
    }
    ans = INF;
    for (int i = lo; i < hi; i++) {
        ans = min(ans, solve(lo, i) + solve(i + 1, hi));
    }
    ans += prefix_sum[hi + 1] - prefix_sum[lo];
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T-- > 0) {
        cin >> K;
        files.resize(K);
        prefix_sum.resize(K + 1);
        int cur_sum = 0;
        prefix_sum[0] = cur_sum;
        for (int i = 0; i < K; i++) {
            cin >> files[i];
            cur_sum += files[i];
            prefix_sum[i + 1] = cur_sum;
        }
        for (int i = 0; i < K; i++) {
            fill(cache[i], cache[i] + K, -1);
        }
        cout << solve(0, K - 1) << "\n";
    }
    return 0;
}
