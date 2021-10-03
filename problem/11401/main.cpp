#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = static_cast<int>(1e9) + 7;
int N, K;

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
    cin >> N >> K;
    int fact_n = 1;
    int fact_k = 1;
    for (int i = 1; i <= N; i++) {
        fact_n = 1LL * fact_n * i % MOD;
        if (i == K) {
            fact_k = 1LL * fact_k * fact_n % MOD;
        }
        if (i == N - K) {
            fact_k = 1LL * fact_k * fact_n % MOD;
        }
    }
    int ans = fact_n;
    ans = 1LL * ans * mod_pow(fact_k, MOD - 2) % MOD;
    cout << ans << "\n";
    return 0;
}
