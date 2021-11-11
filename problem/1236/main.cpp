#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<bool> row;
vector<bool> col;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    row.resize(N);
    col.resize(M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char ch;
            cin >> ch;
            if (ch == 'X') {
                row[i] = true;
                col[j] = true;
            }
        }
    }
    int row_num = 0;
    int col_num = 0;
    for (int i = 0; i < N; i++) {
        if (!row[i]) {
            row_num++;
        }
    }
    for (int i = 0; i < M; i++) {
        if (!col[i]) {
            col_num++;
        }
    }
    cout << max(row_num, col_num) << "\n";
    return 0;
}
