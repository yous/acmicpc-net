#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = static_cast<int>(1e9) + 7;
int T, N, D;

struct Matrix {
    int N, M;
    vector<vector<int>> mat;

    Matrix(int N) : N(N), M(N), mat(N, vector<int>(N)) {}
    Matrix(int N, int M) : N(N), M(M), mat(N, vector<int>(M)) {}

    Matrix& operator+=(const Matrix& rhs) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                mat[i][j] += rhs.mat[i][j];
                mat[i][j] %= MOD;
            }
        }
        return *this;
    }

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
    cin >> T >> N >> D;
    vector<Matrix> blood(T, Matrix(N));
    for (int t = 0; t < T; t++) {
        int M;
        cin >> M;
        for (int i = 0; i < M; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            blood[t].mat[a - 1][b - 1] = c;
        }
    }
    vector<Matrix> solve(T + 1, Matrix(N));
    for (int i = 0; i < N; i++) {
        solve[0].mat[i][i] = 1;
    }
    for (int t = 1; t <= T; t++) {
        solve[t] = solve[t - 1] * blood[t - 1];
    }
    if (D <= T) {
        for (int i = 0; i < N; i++) {
            cout << solve[D].mat[i][0];
            for (int j = 1; j < N; j++) {
                cout << " " << solve[D].mat[i][j];
            }
            cout << "\n";
        }
        return 0;
    }
    Matrix ans = solve[T].pow(D / T) * solve[D % T];
    for (int i = 0; i < N; i++) {
        cout << ans.mat[i][0];
        for (int j = 1; j < N; j++) {
            cout << " " << ans.mat[i][j];
        }
        cout << "\n";
    }
    return 0;
}
