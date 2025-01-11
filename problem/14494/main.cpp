#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = int(1e9) + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N, M;
    cin >> N >> M;
    vector<vector<int>> D(N, vector<int>(M));
    D[0][0] = 1;
    for (int y = 1; y < N; y++) {
        D[y][0] = 1;
    }
    for (int x = 1; x < M; x++) {
        D[0][x] = 1;
    }
    for (int y = 1; y < N; y++) {
        for (int x = 1; x < M; x++) {
            D[y][x] = ((D[y][x - 1] + D[y - 1][x]) % MOD + D[y - 1][x - 1]) % MOD;
        }
    }
    cout << D[N - 1][M - 1] << "\n";
    return 0;
}
