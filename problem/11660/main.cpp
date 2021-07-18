#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct FenwickTree {
    int N;
    vector<vector<int>> t;

    FenwickTree(int n) : N(n), t(n + 1, vector<int>(n + 1)) {}

    int sum(int pos_y, int pos_x) {
        int ans = 0;
        while (pos_y >= 1) {
            int pos = pos_x;
            while (pos >= 1) {
                ans += t[pos_y][pos];
                pos -= pos & -pos;
            }
            pos_y -= pos_y & -pos_y;
        }
        return ans;
    }

    void update(int pos_y, int pos_x, int diff) {
        while (pos_y <= N) {
            int pos = pos_x;
            while (pos <= N) {
                t[pos_y][pos] += diff;
                pos += pos & -pos;
            }
            pos_y += pos_y & -pos_y;
        }
    }
};

int N, M;
FenwickTree* matrix;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    matrix = new FenwickTree(N);
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            int num;
            cin >> num;
            matrix->update(y + 1, x + 1, num);
        }
    }
    for (int i = 0; i < M; i++) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        cout << matrix->sum(y2, x2) - matrix->sum(y2, x1 - 1) - matrix->sum(y1 - 1, x2) + matrix->sum(y1 - 1, x1 - 1) << "\n";
    }
    delete matrix;
    return 0;
}
