#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<bool>> canvas;

void draw(int n, bool down, int y, int x) {
    if (n == 1) {
        canvas[y][x] = true;
        return;
    }
    if (down) {
        for (int i = 0; i < n * 2 - 1; i++) {
            canvas[y][x + i] = true;
        }
        for (int i = 1; i <= n - 1; i++) {
            canvas[y + i][x + i] = true;
            canvas[y + i][x + n * 2 - 2 - i] = true;
        }
        draw((n - 1) / 2, !down, y + 1, x + n / 2 + 1);
    } else {
        for (int i = n - 1; i >= 1; i--) {
            canvas[y + n - i - 1][x + i] = true;
            canvas[y + n - i - 1][x + n * 2 - 2 - i] = true;
        }
        for (int i = 0; i < n * 2 - 1; i++) {
            canvas[y + n - 1][x + i] = true;
        }
        draw((n - 1) / 2, !down, y + n / 2, x + n / 2 + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    bool down = (N % 2 == 0);
    int sz = 1;
    for (int i = 1; i < N; i++) {
        sz = sz * 2 + 1;
    }
    canvas.resize(sz);
    for (int i = 0; i < sz; i++) {
        if (down) {
            canvas[i].resize(sz * 2 - 1 - i);
        } else {
            canvas[i].resize(sz + i);
        }
    }
    draw(sz, down, 0, 0);
    for (vector<bool>& row : canvas) {
        for (auto p : row) {
            if (p) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
