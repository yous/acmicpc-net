#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000;
int N;
long long B;
vector<vector<short>> A;
vector<vector<vector<short>>> table;

void mul(vector<vector<short>>& A, vector<vector<short>>& B, vector<vector<short>>& res) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            short& elem = res[i][j];
            elem = 0;
            for (int k = 0; k < N; k++) {
                elem += A[i][k] * B[k][j] % MOD;
                elem %= MOD;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> B;
    A.resize(N, vector<short>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
            A[i][j] %= MOD;
        }
    }
    vector<vector<short>> ans;
    if (B > 1) {
        int power = 63 - __builtin_clzl(B);
        table.resize(power, vector<vector<short>>(N, vector<short>(N)));
        mul(A, A, table[0]);
        for (int i = 1; i < power; i++) {
            mul(table[i - 1], table[i - 1], table[i]);
        }
        ans = table[power - 1];
        B -= (1LL << power);
    } else {
        ans = A;
        B -= 1;
    }
    while (B > 0) {
        vector<vector<short>> tmp(N, vector<short>(N));
        int power = 63 - __builtin_clzl(B);
        if (power == 0) {
            mul(ans, A, tmp);
        } else {
            mul(ans, table[power - 1], tmp);
        }
        ans = tmp;
        B -= (1LL << power);
    }
    for (int i = 0; i < N; i++) {
        cout << ans[i][0];
        for (int j = 1; j < N; j++) {
            cout << " " << ans[i][j];
        }
        cout << "\n";
    }
    return 0;
}
