#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = static_cast<int>(1e9) + 7;
int M, N, K;
vector<int> fact(4'000'001);
vector<int> fact_rev(4'000'001);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> M;
    fact[0] = 1;
    fact_rev[0] = 1;
    for (int i = 1; i <= 4'000'000; i++) {
        fact[i] = 1LL * fact[i - 1] * i % MOD;
    }
    for (int i = 0; i < M; i++) {
        cin >> N >> K;
        int denom = 1LL * fact[K] * fact[N - K] % MOD;
        int rev = 1;
        int mul = denom;
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
        cout << (1LL * fact[N] * rev % MOD) << "\n";
    }
    return 0;
}
