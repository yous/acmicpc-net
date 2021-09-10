#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9;
short N;
int cache[99][10][100];

int solve(int idx, int num, int mask) {
    if (idx == N - 1) {
        return mask == 9;
    }
    int& ans = cache[idx][num][mask];
    if (ans > 0) {
        return ans - 1;
    }
    int lo = mask / 10;
    int hi = mask % 10;
    if (num > 0) {
        ans += solve(idx + 1, num - 1, min(lo, num - 1) * 10 + hi);
        ans %= MOD;
    }
    if (num < 9) {
        ans += solve(idx + 1, num + 1, lo * 10 + max(hi, num + 1));
        ans %= MOD;
    }
    ans++;
    return ans - 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    if (N <= 9) {
        cout << "0\n";
        return 0;
    }
    int ans = 0;
    for (int i = 1; i <= 9; i++) {
        ans += solve(0, i, i * 11);
        ans %= MOD;
    }
    cout << ans << "\n";
    return 0;
}
