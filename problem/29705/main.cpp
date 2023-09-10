#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = int(1e9) + 7;

struct Matrix {
    int N, M;
    vector<vector<int>> mat;

    Matrix(int n) : N(n), M(n), mat(n, vector<int>(n)) {}
    Matrix(int n, int m) : N(n), M(m), mat(n, vector<int>(m)) {}

    Matrix operator*(const Matrix& rhs) const {
        Matrix res(N, rhs.M);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < rhs.M; j++) {
                for (int k = 0; k < M; k++) {
                    res.mat[i][j] += 1LL * mat[i][k] * rhs.mat[k][j] % MOD;
                    res.mat[i][j] %= MOD;
                }
            }
        }
        return res;
    }

    Matrix pow(long long n) {
        Matrix res(N);
        for (int i = 0; i < N; i++) {
            res.mat[i][i] = 1;
        }
        Matrix mul = *this;
        while (n > 0) {
            if (n % 2 == 1) {
                res = res * mul;
            }
            mul = mul * mul;
            n /= 2;
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long A, B;
    cin >> A >> B;
    vector<int> S(9);
    for (auto& num : S) {
        string s;
        cin >> s;
        num = s.size();
    }
    Matrix solve(9, 9);
    for (int i = 0; i < 9; i++) {
        solve.mat[0][i] = S[i];
    }
    for (int i = 1; i < 9; i++) {
        solve.mat[i][i - 1] = 1;
    }
    Matrix vec(9, 1);
    vec.mat[0][0] = 1;
    int ans = 0;
    Matrix g_mat = solve.pow(A + 8) * vec;
    vector<int> g(9);
    vector<int> g_next(9);
    for (int i = 0; i < 9; i++) {
        g[i] = g_mat.mat[i][0];
    }
    Matrix solve_9 = solve.pow(9);
    int cnt = int(B - A + 1);
    while (cnt > 0) {
        for (int i = 0; i < min(9, cnt); i++) {
            ans = (ans + g[8 - i]) % MOD;
        }
        for (int i = 0; i < 9; i++) {
            g_next[i] = 0;
            for (int j = 0; j < 9; j++) {
                g_next[i] = (g_next[i] + 1LL * solve_9.mat[i][j] * g[j] % MOD) % MOD;
            }
        }
        swap(g, g_next);
        cnt -= 9;
    }
    cout << ans << "\n";
    return 0;
}
