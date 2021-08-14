#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M, K;

struct Matrix {
    int N, M;
    vector<vector<int>> mat;

    Matrix(int N) : N(N), M(N), mat(N, vector<int>(N)) {
        for (int i = 0; i < N; i++) {
            mat[i][i] = 1;
        }
    }

    Matrix(int N, int M) : N(N), M(M), mat(N, vector<int>(M)) {}

    Matrix operator*(const Matrix& other) const {
        Matrix res(N, other.M);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < other.M; j++) {
                for (int k = 0; k < M; k++) {
                    res.mat[i][j] += mat[i][k] * other.mat[k][j];
                }
            }
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    Matrix A(N, M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> A.mat[i][j];
        }
    }
    cin >> M >> K;
    Matrix B(M, K);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            cin >> B.mat[i][j];
        }
    }
    Matrix mul = A * B;
    for (int i = 0; i < N; i++) {
        cout << mul.mat[i][0];
        for (int j = 1; j < K; j++) {
            cout << " " << mul.mat[i][j];
        }
        cout << "\n";
    }
    return 0;
}
