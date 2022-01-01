#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = static_cast<int>(1e9) + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    vector<int> cache(3);
    cache[1] = 3;
    cache[2] = 3 * cache[1] + 4;
    int max_idx = 2;
    while (T-- > 0) {
        int N;
        cin >> N;
        if (N % 3 != 0) {
            cout << "0\n";
            continue;
        }
        N /= 3;
        if (max_idx >= N) {
            cout << cache[N] << "\n";
            continue;
        }
        cache.resize(N + 1);
        for (int i = max_idx + 1; i <= N; i++) {
            cache[i] = (3LL * cache[i - 1] + i * 2) % MOD;
            for (int j = 2; j < i; j++) {
                cache[i] = (cache[i] + 2LL * j * cache[i - j] % MOD) % MOD;
            }
        }
        cout << cache[N] << "\n";
        max_idx = N;
    }
    return 0;
}
