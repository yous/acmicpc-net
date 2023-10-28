#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = int(1e9) + 7;

int mod_pow(int n, long long k) {
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
int mod_inv(int n) {
    return mod_pow(n, MOD - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short A;
    long long B;
    cin >> A >> B;
    if (A == 1) {
        cout << B % MOD << "\n";
        return 0;
    }
    int ans = (mod_pow(A, B) + MOD - 1) % MOD;
    ans = 1LL * ans * mod_inv(A - 1) % MOD;
    cout << ans << "\n";
    return 0;
}
