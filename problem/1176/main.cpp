#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

short N, K;
vector<short> heights;
vector<vector<long long>> cache;

long long solve(int idx, int mask) {
    long long& ans = cache[idx][mask];
    if (ans >= 0) {
        return ans;
    }
    if (mask == (1 << N) - 1) {
        ans = 1;
        return ans;
    }
    ans = 0;
    for (int i = 0; i < N; i++) {
        if ((mask & (1 << i)) != 0 || abs(heights[i] - heights[idx]) <= K) {
            continue;
        }
        ans += solve(i, mask | (1 << i));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    heights.resize(N);
    for (short& num : heights) {
        cin >> num;
    }
    cache.resize(N, vector<long long>(1 << N, -1));
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += solve(i, 1 << i);
    }
    cout << ans << "\n";
    return 0;
}
