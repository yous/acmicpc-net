#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

short N;
vector<short> guilty;
vector<vector<short>> R;
short mafia;

short solve(int dead_mask, int dead_cnt) {
    if ((dead_mask & (1 << mafia)) != 0 || dead_cnt == N - 1) {
        return 0;
    }
    if ((N - dead_cnt) % 2 == 1) {
        short max_guilty = -1000;
        int dead_idx = 0;
        for (int i = 0; i < N; i++) {
            if ((dead_mask & (1 << i)) != 0) {
                continue;
            }
            if (max_guilty < guilty[i]) {
                max_guilty = guilty[i];
                dead_idx = i;
            }
        }
        return solve(dead_mask | (1 << dead_idx), dead_cnt + 1);
    }
    short ans = 0;
    for (int i = 0; i < N; i++) {
        if (i == mafia || (dead_mask & (1 << i)) != 0) {
            continue;
        }
        for (int j = 0; j < N; j++) {
            guilty[j] += R[i][j];
        }
        ans = max(ans, short(1 + solve(dead_mask | (1 << i), dead_cnt + 1)));
        for (int j = 0; j < N; j++) {
            guilty[j] -= R[i][j];
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    guilty.resize(N);
    for (short& num : guilty) {
        cin >> num;
    }
    R.resize(N, vector<short>(N));
    for (auto& row : R) {
        for (short& num : row) {
            cin >> num;
        }
    }
    cin >> mafia;
    cout << solve(0, 0) << "\n";
    return 0;
}
