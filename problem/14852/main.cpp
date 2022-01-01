#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = static_cast<int>(1e9) + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> cache(N + 1);
    vector<int> prefix_sum(N + 1);
    cache[1] = 2;
    cache[2] = 7;
    prefix_sum[1] = 2;
    prefix_sum[2] = 9;
    for (int i = 3; i <= N; i++) {
        cache[i] = (2LL * prefix_sum[i - 1] % MOD + cache[i - 2]) % MOD;
        cache[i] = (cache[i] + 2) % MOD;
        prefix_sum[i] = (prefix_sum[i - 1] + cache[i]) % MOD;
    }
    cout << cache[N] << "\n";
    return 0;
}
