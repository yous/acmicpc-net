#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = static_cast<int>(1e9) + 7;
int N;
vector<int> foods;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    foods.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> foods[i];
    }
    sort(foods.begin(), foods.end());
    int ans = 0;
    long long diff = 0;
    int cnt = (1 << 0);
    for (int lo = 0; lo < N - 1; lo++) {
        int hi = N - 1 - lo;
        diff = (diff + foods[hi] % MOD) % MOD;
        diff = (diff + MOD - (foods[lo] % MOD)) % MOD;
        ans = (ans + diff * cnt % MOD) % MOD;
        cnt = cnt * 2 % MOD;
    }
    cout << ans << "\n";
    return 0;
}
