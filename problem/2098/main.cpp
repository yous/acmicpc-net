#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;
int N;
int ADJ[16][16];
int cache[16][1 << 16];

int solve(int idx, int cnt, int mask) {
    int& ans = cache[idx][mask];
    if (ans > 0) {
        return ans;
    }
    if (cnt == N - 1) {
        ans = (ADJ[idx][0] > 0 ? ADJ[idx][0] : INF);
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
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> ADJ[i][j];
        }
    }
    cout << solve(0, 0, (1 << 0)) << "\n";
    return 0;
}
