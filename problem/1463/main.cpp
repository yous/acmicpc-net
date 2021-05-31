#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
int cache[1000001];

int solve(int n) {
    if (n == 1) {
        return 0;
    }
    if (cache[n] != 0) {
        return cache[n];
    }
    int ans = 1 + solve(n - 1);
    if (n % 3 == 0) {
        ans = min(ans, 1 + solve(n / 3));
    }
    if (n % 2 == 0) {
        ans = min(ans, 1 + solve(n / 2));
    }
    cache[n] = ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    cout << solve(N) << "\n";
    return 0;
}
