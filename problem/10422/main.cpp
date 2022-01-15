#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;
vector<int> cache(5000, MOD);
vector<int> uniq(5000, MOD);

int solve(int l) {
    if (l == 0) {
        return 0;
    }
    int& ans = cache[l - 1];
    if (ans != MOD) {
        return ans;
    }
    uniq[l - 1] = solve(l - 2);
    ans = uniq[l - 1];
    for (int i = 2; i <= l - 2; i++) {
        ans = (ans + 1LL * uniq[i - 1] * solve(l - i) % MOD) % MOD;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cache[0] = 0;
    cache[1] = 1;
    uniq[0] = 0;
    uniq[1] = 1;
    int T;
    cin >> T;
    while (T-- > 0) {
        int L;
        cin >> L;
        cout << solve(L) << "\n";
    }
    return 0;
}
