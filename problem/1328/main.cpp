#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, L, R;
long long cache[101][101];
long long com_cache[101][51];
const long long mod = 1000000007;

long long combi(int n, int k) {
    if (n == k || k == 0) {
        return 1;
    }
    if (k > n / 2) {
        k = n - k;
    }
    if (com_cache[n][k] != 0) {
        return com_cache[n][k];
    }
    long long ans = (combi(n - 1, k - 1) + combi(n - 1, k)) % mod;
    com_cache[n][k] = ans;
    return ans;
}

long long solve(int n, int l) {
    if (l > n) {
        return 0;
    }
    if (l == 0) {
        if (n == 0) {
            return 1;
        } else {
            return 0;
        }
    }
    if (l == n || n <= 2) {
        return 1;
    }
    if (cache[n][l] != 0) {
        return cache[n][l];
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        long long partial = solve(i, l - 1);
        for (int j = 1; j <= n - 1 - i; j++) {
            partial *= j;
            partial %= mod;
        }
        partial *= combi(n - 1, i);
        partial %= mod;
        ans += partial;
        ans %= mod;
    }
    cache[n][l] = ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> L >> R;
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        long long partial = solve(i, L - 1) * solve(N - 1 - i, R - 1);
        partial %= mod;
        partial *= combi(N - 1, i);
        partial %= mod;
        ans += partial;
        ans %= mod;
    }
    cout << ans << "\n";
    return 0;
}
