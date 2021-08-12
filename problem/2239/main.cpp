#include <algorithm>
#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

char sudoku[9][9];
bitset<9> row[9];
bitset<9> col[9];
bitset<9> group[9];
vector<int> zeros;

bool dfs(int zero_idx) {
    int idx = zeros[zero_idx];
    int y = idx / 9,
        x = idx % 9;
    for (int i = 1; i <= 9; i++) {
        if (row[y][i - 1] || col[x][i - 1] || group[y / 3 * 3 + x / 3][i - 1]) {
            continue;
        }
        sudoku[y][x] = i;
        row[y][i - 1] = true;
        col[x][i - 1] = true;
        group[y / 3 * 3 + x / 3][i - 1] = true;
        if (zero_idx == zeros.size() - 1 || dfs(zero_idx + 1)) {
            return true;
        }
        sudoku[y][x] = 0;
        row[y][i - 1] = false;
        col[x][i - 1] = false;
        group[y / 3 * 3 + x / 3][i - 1] = false;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char ch;
            cin >> ch;
            int num = ch - '0';
            sudoku[i][j] = num;
            if (num != 0) {
                row[i][num - 1] = true;
                col[j][num - 1] = true;
                group[i / 3 * 3 + j / 3][num - 1] = true;
            }
        }
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (sudoku[i][j] == 0) {
                zeros.push_back(i * 9 + j);
            }
        }
    }
    dfs(0);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << 0 + sudoku[i][j];
        }
        cout << "\n";
    }
    return 0;
}
