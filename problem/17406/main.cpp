#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const short dy[] = {1, 0, -1, 0};
const short dx[] = {0, 1, 0, -1};
short N, M, K;
vector<vector<short>> A;
vector<tuple<short, short, short>> ops;

int solve(int idx, vector<bool>& selected, vector<vector<short>>& A) {
    if (idx == K) {
        int ans = 0;
        for (int j = 0; j < M; j++) {
            ans += A[0][j];
        }
        for (int i = 1; i < N; i++) {
            int sum = 0;
            for (int j = 0; j < M; j++) {
                sum += A[i][j];
            }
            ans = min(ans, sum);
        }
        return ans;
    }
    int ans = 100 * M;
    for (int k = 0; k < K; k++) {
        if (selected[k]) {
            continue;
        }
        selected[k] = true;
        vector<vector<short>> new_A(A);
        auto [r, c, s] = ops[k];
        for (int sz = 1; sz <= s; sz++) {
            int y = r - sz;
            int x = c - sz;
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < sz * 2; j++) {
                    short ny = y + dy[i];
                    short nx = x + dx[i];
                    new_A[y][x] = A[ny][nx];
                    y = ny;
                    x = nx;
                }
            }
        }
        ans = min(ans, solve(idx + 1, selected, new_A));
        selected[k] = false;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> K;
    A.resize(N, vector<short>(M));
    for (auto& row : A) {
        for (auto& num : row) {
            cin >> num;
        }
    }
    ops.resize(K);
    for (auto& [r, c, s] : ops) {
        cin >> r >> c >> s;
        r--;
        c--;
    }
    vector<bool> selected(K);
    cout << solve(0, selected, A) << "\n";
    return 0;
}
