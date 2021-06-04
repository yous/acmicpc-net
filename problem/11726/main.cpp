#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 10007;
int N;
int dp[1001];

int solve(int n) {
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    int& ans = dp[n];
    if (ans) {
        return ans;
    }
    ans = (solve(n - 1) + solve(n - 2)) % MOD;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    cout << solve(N) << "\n";
    return 0;
}
