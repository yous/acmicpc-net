#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = static_cast<int>(1e6) + 3;
int N, S, E, T;

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
    cin >> N >> S >> E >> T;
    Matrix roads(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char ch;
            cin >> ch;
            roads.mat[i][j] = ch - '0';
        }
    }
    vector<Matrix> time(6, Matrix(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            time[roads.mat[i][j]].mat[i][j] = 1;
        }
    }
    vector<Matrix> solve(6, Matrix(N));
    for (int i = 0; i < N; i++) {
        solve[0].mat[i][i] = 1;
    }
    for (int t = 1; t <= 5; t++) {
        for (int i = 1; i <= t; i++) {
            solve[t] += solve[t - i] * time[i];
        }
    }
    if (T <= 5) {
        cout << solve[T].mat[S - 1][E - 1] << "\n";
        return 0;
    }
    T -= 5;
    Matrix init(N * 5, N);
    for (int t = 5; t >= 1; t--) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                init.mat[(5 - t) * N + i][j] = solve[t].mat[i][j];
            }
        }
    }
    Matrix formula(N * 5);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            formula.mat[i][j] = time[1].mat[i][j];
            formula.mat[i][N + j] = time[2].mat[i][j];
            formula.mat[i][N * 2 + j] = time[3].mat[i][j];
            formula.mat[i][N * 3 + j] = time[4].mat[i][j];
            formula.mat[i][N * 4 + j] = time[5].mat[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        formula.mat[N + i][i] = 1;
        formula.mat[N * 2 + i][N + i] = 1;
        formula.mat[N * 3 + i][N * 2 + i] = 1;
        formula.mat[N * 4 + i][N * 3 + i] = 1;
    }
    cout << (formula.pow(T) * init).mat[S - 1][E - 1] << "\n";
    return 0;
}
