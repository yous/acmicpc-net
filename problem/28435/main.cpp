#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = int(1e9) + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    vector<int> A(K);
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        A[num % K]++;
    }
    vector<int> power_2(N + 1);
    power_2[0] = 1;
    for (int i = 1; i <= N; i++) {
        power_2[i] = 1LL * power_2[i - 1] * 2 % MOD;
    }
    int sum = 1;
    for (int i = 1; i < (K + 1) / 2; i++) {
        sum = 1LL * sum * (((power_2[A[i]] + power_2[A[K - i]]) % MOD - 1 + MOD) % MOD) % MOD;
    }
    if (K % 2 == 0) {
        sum = 1LL * sum * (A[K / 2] + 1) % MOD;
    }
    sum = 1LL * sum * (A[0] + 1) % MOD;
    sum = (sum - N - 1 + MOD) % MOD;
    cout << sum << "\n";
    return 0;
}
