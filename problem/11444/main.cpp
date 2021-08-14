#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = static_cast<int>(1e9) + 7;
long long N;

struct Matrix {
    int mat[2][2] = {{1, 0}, {0, 1}};

    Matrix() {}

    Matrix(int a11, int a12, int a21, int a22) : mat{{a11, a12}, {a21, a22}} {}

    Matrix operator*(const struct Matrix& o) const {
        Matrix res;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                res.mat[i][j] = 0;
                for (int k = 0; k < 2; k++) {
                    res.mat[i][j] += 1LL * mat[i][k] * o.mat[k][j] % MOD;
                    res.mat[i][j] %= MOD;
                }
            }
        }
        return res;
    }

    Matrix pow(long long n) {
        Matrix res;
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

Matrix fibo(1, 1, 1, 0);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    if (N < 2) {
        cout << N << "\n";
        return 0;
    }
    N--;
    cout << fibo.pow(N).mat[0][0] << "\n";
    return 0;
}
