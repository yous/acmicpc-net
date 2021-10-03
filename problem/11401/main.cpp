#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = static_cast<int>(1e9) + 7;
int N, K;
vector<int> fact;

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
    fact.resize(N + 1);
    int num = 1;
    fact[0] = num;
    for (int i = 1; i <= N; i++) {
        num = 1LL * num * i % MOD;
        fact[i] = num;
    }
    int ans = fact[N];
    ans = 1LL * ans * mod_pow(1LL * fact[K] * fact[N - K] % MOD, MOD - 2) % MOD;
    cout << ans << "\n";
    return 0;
}
