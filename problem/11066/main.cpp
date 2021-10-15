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
            fill(cache[i], cache[i] + K, 0);
        }
        for (int len = 1; len < K; len++) {
            for (int lo = 0; lo < K - len; lo++) {
                int hi = lo + len;
                int cur_min = INF;
                for (int i = lo; i < hi; i++) {
                    cur_min = min(cur_min, cache[lo][i] + cache[i + 1][hi]);
                }
                cache[lo][hi] = cur_min + prefix_sum[hi + 1] - prefix_sum[lo];
            }
        }
        cout << cache[0][K - 1] << "\n";
    }
    return 0;
}
