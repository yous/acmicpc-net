#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

const short dy[] = {-1, 1, 0, 0};
const short dx[] = {0, 0, -1, 1};

int puzzle_to_num(vector<vector<short>>& puzzle) {
    int res = 0;
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            res = res * 10 + puzzle[y][x];
        }
    }
    return res;
}

void num_to_puzzle(int puzzle_num, vector<vector<short>>& puzzle) {
    for (int y = 2; y >= 0; y--) {
        for (int x = 2; x >= 0; x--) {
            puzzle[y][x] = puzzle_num % 10;
            puzzle_num /= 10;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<short>> puzzle(3, vector<short>(3));
    for (auto& row : puzzle) {
        for (auto& num : row) {
            cin >> num;
        }
    }
    int puzzle_num = puzzle_to_num(puzzle);
    if (puzzle_num == 123456780) {
        cout << "0\n";
        return 0;
    }
    queue<int> qu;
    set<int> visited;
    qu.emplace(puzzle_num);
    visited.emplace(puzzle_num);
    int step = 1;
    while (!qu.empty()) {
        auto sz = qu.size();
        while (sz-- > 0) {
            num_to_puzzle(qu.front(), puzzle);
            qu.pop();
            for (int y = 0; y < 3; y++) {
                for (int x = 0; x < 3; x++) {
                    if (puzzle[y][x] != 0) {
                        continue;
                    }
                    for (int i = 0; i < 4; i++) {
                        short ny = y + dy[i];
                        short nx = x + dx[i];
                        if (ny < 0 || ny >= 3 || nx < 0 || nx >= 3) {
                            continue;
                        }
                        swap(puzzle[y][x], puzzle[ny][nx]);
                        int new_num = puzzle_to_num(puzzle);
                        if (new_num == 123456780) {
                            cout << step << "\n";
                            return 0;
                        }
                        swap(puzzle[y][x], puzzle[ny][nx]);
                        auto it = visited.lower_bound(new_num);
                        if (it != visited.end() && *it == new_num) {
                            continue;
                        } else {
                            visited.emplace_hint(it, new_num);
                            qu.emplace(new_num);
                        }
                    }
                }
            }
        }
        step++;
    }
    cout << "-1\n";
    return 0;
}
