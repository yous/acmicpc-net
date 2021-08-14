#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = static_cast<int>(1e9) + 7;
int N, M, D;

struct Matrix {
    int N;
    vector<vector<int>> mat;

    Matrix(int N) : N(N), mat(N, vector<int>(N)) {}

    Matrix operator*(const Matrix& o) const {
        Matrix res(N);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++) {
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
    Matrix A(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        A.mat[a - 1][b - 1] = 1;
        A.mat[b - 1][a - 1] = 1;
    }
    cin >> D;
    cout << A.pow(D).mat[0][0] << "\n";
    return 0;
}
