#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000;
int N;
long long B;

struct Matrix {
    int N;
    vector<vector<short>> mat;

    Matrix(int N) : N(N), mat(N, vector<short>(N)) {
        for (int i = 0; i < N; i++) {
            mat[i][i] = 1;
        }
    }

    Matrix operator*(const Matrix& other) const {
        Matrix res(N);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                res.mat[i][j] = 0;
                for (int k = 0; k < N; k++) {
                    res.mat[i][j] += mat[i][k] * other.mat[k][j] % MOD;
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
    cin >> N >> B;
    Matrix A(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A.mat[i][j];
            A.mat[i][j] %= MOD;
        }
    }
    Matrix ans = A.pow(B);
    for (int i = 0; i < N; i++) {
        cout << ans.mat[i][0];
        for (int j = 1; j < N; j++) {
            cout << " " << ans.mat[i][j];
        }
        cout << "\n";
    }
    return 0;
}
