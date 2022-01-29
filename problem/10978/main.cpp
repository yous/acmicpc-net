#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<long long> cache;

long long solve(int pos, int mask) {
    long long& ans = cache[mask];
    if (ans >= 0) {
        return ans;
    }
    if (mask == (1 << N) - 1) {
        ans = 1;
        return ans;
    }
    ans = 0;
    for (int i = 0; i < N; i++) {
        if (i != pos && (mask & (1 << i)) == 0) {
            ans += solve(pos + 1, mask | (1 << i));
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T-- > 0) {
        cin >> N;
        cache.clear();
        cache.resize(1 << N, -1);
        cout << solve(0, 0) << "\n";
    }
    return 0;
}
