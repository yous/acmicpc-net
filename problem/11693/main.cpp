#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = static_cast<int>(1e9) + 7;
int N, M;

int mod_pow(int n, int k) {
    int res = 1;
    int mul = n;
    while (k > 0) {
        if (k % 2 == 1) {
            res = 1LL * res * mul % MOD;
            k--;
        } else {
            mul = 1LL * mul * mul % MOD;
            k /= 2;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    int ans = 1;
    for (int i = 2; i * i <= N; i++) {
        int cnt = 0;
        while (N % i == 0) {
            N /= i;
            cnt++;
        }
        if (cnt == 0) {
            continue;
        }
        int factor = (mod_pow(i, (1LL * cnt * M + 1) % (MOD - 1)) - 1 + MOD) % MOD;
        factor = 1LL * factor * mod_pow(i - 1, MOD - 2) % MOD;
        ans = 1LL * ans * factor % MOD;
    }
    if (N > 1) {
        int factor = (mod_pow(N, M + 1) - 1 + MOD) % MOD;
        factor = 1LL * factor * mod_pow(N - 1, MOD - 2) % MOD;
        ans = 1LL * ans * factor % MOD;
    }
    cout << ans << "\n";
    return 0;
}
