#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

short T, W;
vector<bool> plums;
vector<vector<short>> cache;

short solve(int pos, int cnt) {
    if (pos >= T) {
        return 0;
    }
    short& ans = cache[pos][cnt];
    if (ans >= 0) {
        return ans;
    }
    bool is_two = (cnt % 2 == 1);
    if (cnt == W) {
        ans = (plums[pos] == is_two ? 1 : 0) + solve(pos + 1, cnt);
        return ans;
    }
    if (plums[pos] == is_two) {
        ans = 1 + solve(pos + 1, cnt);
    } else {
        ans = max(solve(pos + 1, cnt), short(1 + solve(pos + 1, cnt + 1)));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T >> W;
    plums.resize(T);
    for (int i = 0; i < T; i++) {
        int num;
        cin >> num;
        plums[i] = (num == 2);
    }
    cache.resize(T, vector<short>(W + 1, -1));
    cout << solve(0, 0) << "\n";
    return 0;
}
