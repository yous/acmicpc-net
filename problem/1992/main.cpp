#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<string> matrix;

string solve(int y, int x, int size) {
    if (size == 1) {
        return matrix[y][x] == '0' ? "0" : "1";
    }
    string ul = solve(y, x, size / 2);
    string ur = solve(y, x + size / 2, size / 2);
    string dl = solve(y + size / 2, x, size / 2);
    string dr = solve(y + size / 2, x + size / 2, size / 2);
    if (ul[0] != '(' && ur[0] != '(' && dl[0] != '(' && dr[0] != '(' &&
            ul[0] == ur[0] && ur[0] == dl[0] && dl[0] == dr[0]) {
        return ul;
    }
    return "(" + ul + ur + dl + dr + ")";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        matrix.push_back(s);
    }
    cout << solve(0, 0, N) << "\n";
    return 0;
}
