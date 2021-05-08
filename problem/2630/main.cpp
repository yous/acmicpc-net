#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
bool paper[128][128];

pair<int, int> solve(int x, int y, int size) {
    if (size == 1) {
        return paper[x][y] ? make_pair(0, 1) : make_pair(1, 0);
    }
    auto p1 = solve(x, y, size / 2);
    auto p2 = solve(x, y + size / 2, size / 2);
    auto p3 = solve(x + size / 2, y, size / 2);
    auto p4 = solve(x + size / 2, y + size / 2, size / 2);

    int first = p1.first + p2.first + p3.first + p4.first;
    int second = p1.second + p2.second + p3.second + p4.second;
    if (first == 0) {
        second = 1;
    } else if (second == 0) {
        first = 1;
    }
    return make_pair(first, second);
}

int main() {
    int i, j;
    cin >> N;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cin >> paper[i][j];
        }
    }
    auto result = solve(0, 0, N);
    cout << result.first << "\n";
    cout << result.second << "\n";
    return 0;
}
