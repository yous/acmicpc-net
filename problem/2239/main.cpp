#include <algorithm>
#include <bitset>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MASK = (1 << 9) - 1;
char sudoku[9][9];
char save[9][9];
bitset<9> row[9];
bitset<9> col[9];
bitset<9> group[9];
vector<int> zeros;
queue<int> qu;

void set_num(int y, int x, int num) {
    sudoku[y][x] = num;
    row[y][num - 1] = true;
    col[x][num - 1] = true;
    group[y / 3 * 3 + x / 3][num - 1] = true;
}

void check_row(int y) {
    for (int i = 0; i < 9; i++) {
        if (sudoku[y][i] == 0) {
            int num = __builtin_ctz(MASK - row[y].to_ulong()) + 1;
            set_num(y, i, num);
            qu.push(y * 9 + i);
            return;
        }
    }
}

void check_col(int x) {
    for (int i = 0; i < 9; i++) {
        if (sudoku[i][x] == 0) {
            int num = __builtin_ctz(MASK - col[x].to_ulong()) + 1;
            set_num(i, x, num);
            qu.push(i * 9 + x);
            return;
        }
    }
}

void check_group(int y, int x) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sudoku[y + i][x + j] == 0) {
                int num = __builtin_ctz(MASK - group[y + x / 3].to_ulong()) + 1;
                set_num(y + i, x + j, num);
                qu.push((y + i) * 9 + x + j);
                return;
            }
        }
    }
}

void step(void) {
    while (!qu.empty()) {
        int idx = qu.front();
        qu.pop();
        int y = idx / 9,
            x = idx % 9;
        if (row[y].count() == 8) {
            check_row(y);
        }
        if (col[x].count() == 8) {
            check_col(x);
        }
        if (group[y / 3 * 3 + x / 3].count() == 8) {
            check_group(y / 3 * 3, x / 3 * 3);
        }
    }
}

bool dfs(int zero_idx) {
    int idx = zeros[zero_idx];
    int y = idx / 9,
        x = idx % 9;
    for (int i = 1; i <= 9; i++) {
        if (row[y][i - 1] || col[x][i - 1] || group[y / 3 * 3 + x / 3][i - 1]) {
            continue;
        }
        set_num(y, x, i);
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
        if (row[i].count() == 8) {
            check_row(i);
        }
        if (col[i].count() == 8) {
            check_col(i);
        }
        if (group[i].count() == 8) {
            check_group(i / 3 * 3, i % 3 * 3);
        }
    }
    step();
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
