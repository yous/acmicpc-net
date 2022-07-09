#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = int(1e9) + 7;

int combi(vector<int>& factor, int n, int k) {
    int divide = 1LL * factor[k] * factor[n - k] % MOD;
    int rev = 1;
    int mul = divide;
    int cnt = MOD - 2;
    while (cnt > 0) {
        if (cnt % 2 == 1) {
            rev = 1LL * rev * mul % MOD;
            cnt--;
        } else {
            mul = 1LL * mul * mul % MOD;
            cnt /= 2;
        }
    }
    return 1LL * factor[n] * rev % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N, K;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
    }
    vector<int> factor(N + 1);
    int mul = 1;
    factor[0] = 1;
    factor[1] = 1;
    for (int i = 2; i <= N; i++) {
        mul = 1LL * mul * i % MOD;
        factor[i] = mul;
    }
    vector<int> power(K);
    power[0] = 1;
    mul = 1;
    for (int i = 1; i < K; i++) {
        mul = 1LL * mul * 2 % MOD;
        power[i] = mul;
    }
    cout << 1LL * combi(factor, N, K) * power[K - 1] % MOD << "\n";
    return 0;
}
