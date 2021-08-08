#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = static_cast<int>(1e9) + 7;
long long N;

struct Matrix {
    int a11, a12;
    int a21, a22;

    Matrix(int a11, int a12, int a21, int a22) : a11(a11), a12(a12), a21(a21), a22(a22) {}

    Matrix operator*(const struct Matrix& mat) const {
        return {static_cast<int>((1LL * a11 * mat.a11 % MOD + 1LL * a12 * mat.a21 % MOD) % MOD),
                static_cast<int>((1LL * a11 * mat.a12 % MOD + 1LL * a12 * mat.a22 % MOD) % MOD),
                static_cast<int>((1LL * a21 * mat.a11 % MOD + 1LL * a22 * mat.a21 % MOD) % MOD),
                static_cast<int>((1LL * a21 * mat.a12 % MOD + 1LL * a22 * mat.a22 % MOD) % MOD)};
    }
};

vector<Matrix> table;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    if (N < 2) {
        cout << N << "\n";
        return 0;
    }
    N--;
    int power = 63 - __builtin_clzl(N);
    table.resize(power + 1, {0, 0, 0, 0});
    table[0] = {1, 1, 1, 0};
    for (int i = 1; i <= power; i++) {
        table[i] = table[i - 1] * table[i - 1];
    }
    Matrix ans = table[power];
    N -= (1LL << power);
    while (N > 0) {
        power = 63 - __builtin_clzl(N);
        Matrix tmp = ans * table[power];
        ans = tmp;
        N -= (1LL << power);
    }
    cout << ans.a11 << "\n";
    return 0;
}
