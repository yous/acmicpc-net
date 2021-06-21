#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int N;
vector<vector<short>> MATRIX;

tuple<int, int, int> solve(int y, int x, int size) {
    if (size == 1) {
        switch (MATRIX[y][x]) {
            case -1:
                return {1, 0, 0};
            case 0:
                return {0, 1, 0};
            case 1:
                return {0, 0, 1};
        }
    }
    int a = 0,
        b = 0,
        c = 0;
    bool is_a = true,
         is_b = true,
         is_c = true;
    for (int i = 0; i < size; i += size / 3) {
        for (int j = 0; j < size; j += size / 3) {
            int na, nb, nc;
            tie(na, nb, nc) = solve(y + i, x + j, size / 3);
            a += na;
            b += nb;
            c += nc;
            if (is_a && nb + nc > 0) {
                is_a = false;
            }
            if (is_b && na + nc > 0) {
                is_b = false;
            }
            if (is_c && na + nb > 0) {
                is_c = false;
            }
        }
    }
    if (is_a) {
        return {1, 0, 0};
    } else if (is_b) {
        return {0, 1, 0};
    } else if (is_c) {
        return {0, 0, 1};
    } else {
        return {a, b, c};
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    MATRIX.resize(N);
    for (int i = 0; i < N; i++) {
        auto& row = MATRIX[i];
        for (int j = 0; j < N; j++) {
            short num;
            cin >> num;
            row.push_back(num);
        }
    }
    int a, b, c;
    tie(a, b, c) = solve(0, 0, N);
    cout << a << "\n";
    cout << b << "\n";
    cout << c << "\n";
    return 0;
}
