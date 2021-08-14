#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const short MOD = 100;
short X, Y, A0, A1;
int N;

struct Matrix {
    int mat[2][2] = {{1, 0}, {0, 1}};

    Matrix() {}

    Matrix(int a11, int a12, int a21, int a22) : mat{{a11, a12}, {a21, a22}} {}

    Matrix operator*(const Matrix& o) const {
        Matrix res;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                res.mat[i][j] = 0;
                for (int k = 0; k < 2; k++) {
                    res.mat[i][j] += mat[i][k] * o.mat[k][j] % MOD;
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> X >> Y >> A0 >> A1 >> N;
    Matrix A(X, Y, 1, 0);
    Matrix An = A.pow(N - 1);
    short ans = (An.mat[0][0] * A1 % MOD + An.mat[0][1] * A0 % MOD) % MOD;
    cout << ans / 10 << ans % 10 << "\n";
    return 0;
}
