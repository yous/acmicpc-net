#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const short MOD = 10'007;
int N, K;
vector<short> fact(1001);

int mod_pow(int n, int k) {
    int res = 1;
    int mul = n;
    while (k > 0) {
        if (k % 2 == 1) {
            res = res * mul % MOD;
            k--;
        } else {
            mul = mul * mul % MOD;
            k /= 2;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    int num = 1;
    fact[0] = num;
    for (int i = 1; i <= N; i++) {
        num = num * i % MOD;
        fact[i] = num;
    }
    int ans = fact[N];
    ans = ans * mod_pow(fact[K] * fact[N - K] % MOD, MOD - 2) % MOD;
    cout << ans << "\n";
    return 0;
}
