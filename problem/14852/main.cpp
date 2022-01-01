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
    int prefix_sum;
    cache[1] = 2;
    cache[2] = 7;
    prefix_sum = 9;
    for (int i = 3; i <= N; i++) {
        cache[i] = (2LL * prefix_sum + cache[i - 2] + 2) % MOD;
        prefix_sum = (prefix_sum + cache[i]) % MOD;
    }
    cout << cache[N] << "\n";
    return 0;
}
