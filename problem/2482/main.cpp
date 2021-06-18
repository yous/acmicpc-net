#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000003;
int N, K;
int cache[1001][501];

int line(int n, int k) {
    if (k == 0 || (n == 1 && k <= n)) {
        return 1;
    }
    if (k > (n + 1) / 2) {
        return 0;
    }
    int& ans = cache[n][k];
    if (ans > 0) {
        return ans;
    }
    ans = line(n - 2, k - 1) + line(n - 1, k);
    ans %= MOD;
    return ans;
}

int circle(int n, int k) {
    if (k == 0 || (n == 1 && k <= n)) {
        return 1;
    }
    if (k > n / 2) {
        return 0;
    }
    int ans = (line(n - 3, k - 1) + line(n - 1, k)) % MOD;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    if (K > N / 2) {
        cout << "0\n";
    } else {
        cout << circle(N, K) << "\n";
    }
    return 0;
}
