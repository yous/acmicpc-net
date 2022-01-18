#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<short> scores;
vector<int> cache;

int solve(int idx) {
    if (idx >= N) {
        return 0;
    }
    int& ans = cache[idx];
    if (ans >= 0) {
        return ans;
    }
    short min_val = scores[idx];
    short max_val = min_val;
    ans = solve(idx + 1);
    for (int i = idx + 1; i < N; i++) {
        short val = scores[i];
        if (min_val > val) {
            min_val = val;
        }
        if (max_val < val) {
            max_val = val;
        }
        ans = max(ans, max_val - min_val + solve(i + 1));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    scores.resize(N);
    cache.resize(N, -1);
    for (short& num : scores) {
        cin >> num;
    }
    cout << solve(0) << "\n";
    return 0;
}
