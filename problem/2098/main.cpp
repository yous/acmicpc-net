#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;
int N;
vector<vector<int>> ADJ;
int start;
int cache[16][16][1 << 16];

int solve(int idx, int cnt, int mask) {
    if (cnt == N - 1) {
        return (ADJ[idx][start] > 0 ? ADJ[idx][start] : INF);
    }
    int& ans = cache[start][idx][mask];
    if (ans > 0) {
        return ans;
    }
    ans = INF;
    for (int i = 0; i < N; i++) {
        if ((mask & (1 << i)) == 0 && ADJ[idx][i] > 0) {
            ans = min(ans, ADJ[idx][i] + solve(i, cnt + 1, mask | (1 << i)));
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    ADJ.resize(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> ADJ[i][j];
        }
    }
    int ans = INF;
    for (int i = 0; i < N; i++) {
        start = i;
        ans = min(ans, solve(i, 0, (1 << i)));
    }
    cout << ans << "\n";
    return 0;
}
