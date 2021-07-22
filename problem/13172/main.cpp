#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = static_cast<int>(1e9) + 7;
int M;

int power(int n, int order) {
    if (order == 0) {
        return 1;
    }
    int pow_2 = power(n, order / 2);
    if (order % 2) {
        return (1LL * pow_2 * pow_2 % MOD) * n % MOD;
    }
    return 1LL * pow_2 * pow_2 % MOD;
}

int inv(int n) {
    return power(n, MOD - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> M;
    int sum = 0;
    for (int i = 0; i < M; i++) {
        int n, s;
        cin >> n >> s;
        sum += 1LL * s * inv(n) % MOD;
        sum %= MOD;
    }
    cout << sum << "\n";
    return 0;
}
