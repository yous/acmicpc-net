#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;
int N, K;
vector<vector<short>> T;
vector<vector<int>> cache;

int solve(short mask, int pos) {
    if (mask == (1 << N) - 1) {
        return 0;
    }
    int& ans = cache[mask][pos];
    if (ans != INF) {
        return ans;
    }
    for (int i = 0; i < N; i++) {
        if ((mask & (1 << i)) == 0) {
            ans = min(ans, T[pos][i] + solve(mask | (1 << i), i));
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    cache.resize(1 << N, vector<int>(N, INF));
    T.resize(N, vector<short>(N));
    for (auto& row : T) {
        for (auto& num : row) {
            cin >> num;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (T[i][j] == 0) {
                continue;
            }
            for (int k = 0; k < N; k++) {
                T[i][j] = min(T[i][j], short(T[i][k] + T[k][j]));
            }
        }
    }
    cout << solve(1 << K, K) << "\n";
    return 0;
}
