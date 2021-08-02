#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M, K;
vector<vector<int>> prefix_matrix;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    prefix_matrix.resize(N + 1);
    for (int x = 0; x <= M; x++) {
        prefix_matrix[0].push_back(0);
    }
    for (int y = 1; y <= N; y++) {
        prefix_matrix[y].push_back(0);
        for (int x = 1; x <= M; x++) {
            int num;
            cin >> num;
            prefix_matrix[y].push_back(num + prefix_matrix[y - 1][x] + prefix_matrix[y][x - 1] - prefix_matrix[y - 1][x - 1]);
        }
    }
    cin >> K;
    for (int k = 0; k < K; k++) {
        int i, j, y, x;
        cin >> i >> j >> y >> x;
        cout << prefix_matrix[y][x] - prefix_matrix[i - 1][x] - prefix_matrix[y][j - 1] + prefix_matrix[i - 1][j - 1] << "\n";
    }
    return 0;
}
