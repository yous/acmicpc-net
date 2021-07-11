#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int T;
int N;
vector<short> stickers[2];
vector<int> cache[2];

int solve(int idx, bool up) {
    if (idx >= N) {
        return 0;
    }
    int& ans = cache[up][idx];
    if (ans >= 0) {
        return ans;
    }
    if (up) {
        ans = max({ans, stickers[0][idx] + solve(idx + 1, false), solve(idx + 1, true)});
    } else {
        ans = max({ans, stickers[1][idx] + solve(idx + 1, true), solve(idx + 1, false)});
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T-- > 0) {
        cin >> N;
        for (int i = 0; i < 2; i++) {
            stickers[i].clear();
            stickers[i].resize(N);
            cache[i].clear();
            cache[i].resize(N);
            fill(cache[i].begin(), cache[i].end(), -1);
            for (int j = 0; j < N; j++) {
                cin >> stickers[i][j];
            }
        }
        cout << max(solve(0, true), solve(0, false)) << "\n";
    }
    return 0;
}
