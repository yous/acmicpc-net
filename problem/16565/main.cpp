#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 10007;
int N;
vector<int> factor(53);

int combi(int n, int k) {
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
    cin >> N;
    if (N <= 3) {
        cout << "0\n";
        return 0;
    }
    int mul = 1;
    factor[0] = 1;
    factor[1] = 1;
    for (int i = 2; i <= 52; i++) {
        mul = 1LL * mul * i % MOD;
        factor[i] = mul;
    }
    int ans = 0;
    int grp = 1;
    while (grp * 4 <= N) {
        ans += 1LL * combi(13, grp) * combi(52 - 4 * grp, N - 4 * grp) % MOD * (grp % 2 == 1 ? 1 : -1) + MOD;
        ans %= MOD;
        grp++;
    }
    cout << ans << "\n";
    return 0;
}
