#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = static_cast<int>(1e9) + 7;
int M;

int mod_pow(int a, int n) {
    int res = 1;
    while (n > 0) {
        if (n & 1) {
            res = 1LL * res * a % MOD;
        }
        a = 1LL * a * a % MOD;
        n /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> M;
    int sum = 0;
    for (int i = 0; i < M; i++) {
        int n, s;
        cin >> n >> s;
        sum += 1LL * s * mod_pow(n, MOD - 2) % MOD;
        sum %= MOD;
    }
    cout << sum << "\n";
    return 0;
}
