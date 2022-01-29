#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<long long> cache(21, -1);

long long solve(int n) {
    long long& ans = cache[n];
    if (ans >= 0) {
        return ans;
    }
    ans = 1LL * (n - 1) * (solve(n - 1) + solve(n - 2));
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    cache[0] = 0;
    cache[1] = 0;
    cache[2] = 1;
    while (T-- > 0) {
        cin >> N;
        cout << solve(N) << "\n";
    }
    return 0;
}
