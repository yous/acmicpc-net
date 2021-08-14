#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = static_cast<int>(1e9) + 7;
int N, K;

struct Matrix {
    int N;
    vector<vector<int>> mat;

    Matrix(int N) : N(N), mat(N, vector<int>(N)) {
        for (int i = 0; i < N; i++) {
            mat[i][i] = 1;
        }
    }

    Matrix operator*(const Matrix& o) const {
        Matrix res(N);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                res.mat[i][j] = 0;
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
    cin >> N >> K;
    Matrix A(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A.mat[i][j];
        }
    }
    Matrix Ak = A.pow(K);
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ans += Ak.mat[i][j];
            ans %= MOD;
        }
    }
    cout << ans << "\n";
    return 0;
}
