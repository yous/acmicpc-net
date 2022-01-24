#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = static_cast<int>(1e9) + 7;
short N;
int fact;
vector<int> fact_inv(1515);

int solve(int one_cnt) {
    int num_sum = one_cnt + (N - one_cnt) * 5;
    if (num_sum % 3 != 0) {
        return 0;
    }
    return 1LL * fact * fact_inv[one_cnt] % MOD * fact_inv[N - one_cnt - 1] % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    fact = 1;
    fact_inv[0] = 1;
    for (int i = 1; i < N; i++) {
        fact = 1LL * fact * i % MOD;
        int num = 1;
        int mul = fact;
        int pow = MOD - 2;
        while (pow > 0) {
            if (pow % 2 == 1) {
                num = 1LL * num * mul % MOD;
            }
            mul = 1LL * mul * mul % MOD;
            pow /= 2;
        }
        fact_inv[i] = num;
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans = (ans + solve(i)) % MOD;
    }
    cout << ans << "\n";
    return 0;
}
