#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> matrix;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    matrix.resize(N + 1, vector<int>(N + 1));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int num;
            cin >> num;
            matrix[i][j] = matrix[i][j - 1] + matrix[i - 1][j] - matrix[i - 1][j - 1] + num;
        }
    }
    for (int i = 0; i < M; i++) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        cout << matrix[y2][x2] - matrix[y2][x1 - 1] - matrix[y1 - 1][x2] + matrix[y1 - 1][x1 - 1] << "\n";
    }
    return 0;
}
