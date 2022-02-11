#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = int(1e9) + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int A, B, N;
    cin >> A >> B >> N;
    int res = 1;
    int mul = 2;
    int cnt = N - 1;
    while (cnt > 0) {
        if (cnt % 2 == 1) {
            res = 1LL * res * mul % MOD;
            cnt--;
        } else {
            mul = 1LL * mul * mul % MOD;
            cnt /= 2;
        }
    }
    int ans = 1;
    for (int i = 0; i < 31; i++) {
        ans = 1LL * ans * res % MOD;
    }
    cout << ans << "\n";
    return 0;
}
