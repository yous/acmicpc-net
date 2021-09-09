#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9;
short N;
int cache[100][10][1 << 10];

int solve(int idx, int num, int mask) {
    int& ans = cache[idx][num][mask];
    if (ans > 0) {
        return ans - 1;
    }
    if (idx == N - 1) {
        ans = (mask == (1 << 10) - 1) ? 2 : 1;
        return ans - 1;
    }
    if (num > 0) {
        ans += solve(idx + 1, num - 1, mask | (1 << (num - 1)));
        ans %= MOD;
    }
    if (num < 9) {
        ans += solve(idx + 1, num + 1, mask | (1 << (num + 1)));
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
        ans += solve(0, i, (1 << i));
        ans %= MOD;
    }
    cout << ans << "\n";
    return 0;
}
