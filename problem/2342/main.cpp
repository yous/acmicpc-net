#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;
const int dist[5][4] = {
    {2, 2, 2, 2},
    {1, 3, 4, 3},
    {3, 1, 3, 4},
    {4, 3, 1, 3},
    {3, 4, 3, 1}
};
int dp[2][5][5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 0; i < 5; i++) {
        fill(dp[0][i], dp[0][i] + 5, INF);
        fill(dp[1][i], dp[1][i] + 5, INF);
    }
    int idx = 0;
    dp[idx][0][0] = 0;
    char ch;
    while (cin >> ch) {
        if (ch == '0') {
            break;
        }
        int step = ch - '0';
        for (int i = 0; i < 5; i++) {
            fill(dp[idx ^ 1][i], dp[idx ^ 1][i] + 5, INF);
        }
        for (int l = 0; l < 5; l++) {
            for (int r = 0; r < 5; r++) {
                if (dp[idx][l][r] < INF) {
                    if (r != step) {
                        dp[idx ^ 1][step][r] = min(dp[idx ^ 1][step][r], dist[l][step - 1] + dp[idx][l][r]);
                    }
                    if (l != step) {
                        dp[idx ^ 1][l][step] = min(dp[idx ^ 1][l][step], dist[r][step - 1] + dp[idx][l][r]);
                    }
                }
            }
        }
        idx ^= 1;
    }
    int ans = INF;
    for (int l = 0; l < 5; l++) {
        for (int r = 0; r < 5; r++) {
            ans = min(ans, dp[idx][l][r]);
        }
    }
    cout << ans << "\n";
    return 0;
}
