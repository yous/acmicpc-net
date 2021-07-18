#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

string S1, S2;
vector<vector<short>> cache;
int s1_sz, s2_sz;

short solve(int s1_idx, int s2_idx) {
    if (s1_idx == s1_sz || s2_idx == s2_sz) {
        return 0;
    }
    short& ans = cache[s1_idx][s2_idx];
    if (ans >= 0) {
        return ans;
    }
    ans = max(solve(s1_idx, s2_idx + 1), solve(s1_idx + 1, s2_idx));
    if (S1[s1_idx] == S2[s2_idx]) {
        ans = max(ans, static_cast<short>(1 + solve(s1_idx + 1, s2_idx + 1)));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> S1 >> S2;
    s1_sz = S1.size();
    s2_sz = S2.size();
    cache.resize(s1_sz, vector<short>(s2_sz, -1));
    cout << solve(0, 0) << "\n";
    return 0;
}
