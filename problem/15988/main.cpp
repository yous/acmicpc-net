#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = static_cast<int>(1e9) + 9;
vector<int> cache(1000001, MOD);

int solve(int n) {
    int& ans = cache[n];
    if (ans != MOD) {
        return ans;
    }
    ans = ((solve(n - 1) + solve(n - 2)) % MOD + solve(n - 3)) % MOD;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cache[1] = 1;
    cache[2] = 2;
    cache[3] = 4;
    int T;
    cin >> T;
    while (T-- > 0) {
        int N;
        cin >> N;
        cout << solve(N) << "\n";
    }
    return 0;
}
