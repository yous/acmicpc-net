#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

short N, S, M;
vector<short> vols;
vector<vector<short>> cache;

short solve(int idx, short vol) {
    if (idx >= N) {
        return vol;
    }
    short& ans = cache[idx][vol];
    if (ans >= -1) {
        return ans;
    }
    ans = -1;
    if (vol - vols[idx] >= 0) {
        short nxt = solve(idx + 1, vol - vols[idx]);
        if (nxt != -1) {
            ans = max(ans, nxt);
        }
    }
    if (vol + vols[idx] <= M) {
        short nxt = solve(idx + 1, vol + vols[idx]);
        if (nxt != -1) {
            ans = max(ans, nxt);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> S >> M;
    vols.resize(N);
    for (short& num : vols) {
        cin >> num;
    }
    cache.resize(N, vector<short>(M + 1, -2));
    cout << solve(0, S) << "\n";
    return 0;
}
