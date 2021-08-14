#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = static_cast<int>(1e9) + 7;
long long N;
int M;

struct Matrix {
    int N, M;
    vector<vector<int>> mat;

    Matrix(int N) : N(N), M(N), mat(N, vector<int>(N)) {}
    Matrix(int N, int M) : N(N), M(M), mat(N, vector<int>(M)) {}

    Matrix operator*(const Matrix& o) const {
        Matrix res(N, o.M);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < o.M; j++) {
                for (int k = 0; k < M; k++) {
                    res.mat[i][j] += 1LL * mat[i][k] * o.mat[k][j] % MOD;
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
    cin >> N >> M;
    if (N < M) {
        cout << "1\n";
        return 0;
    }
    Matrix init(M, 1);
    for (int i = 0; i < M; i++) {
        init.mat[i][0] = 1;
    }
    Matrix formula(M);
    N -= M - 1;
    formula.mat[0][0] = 1;
    formula.mat[0][M - 1] = 1;
    for (int i = 1; i < M; i++) {
        formula.mat[i][i - 1] = 1;
    }
    cout << (formula.pow(N) * init).mat[0][0] << "\n";
    return 0;
}
