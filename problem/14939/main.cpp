#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
bool bulbs[10][10];
bool bulbs2[10][10];

void check(int y, int x) {
    bulbs2[y][x] = !bulbs2[y][x];
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= 10 || nx < 0 || nx >= 10) {
            continue;
        }
        bulbs2[ny][nx] = !bulbs2[ny][nx];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            char ch;
            cin >> ch;
            bulbs[i][j] = (ch == 'O');
        }
    }
    int ans = INF;
    for (int first_bits = 0; first_bits < (1 << 10); first_bits++) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                bulbs2[i][j] = bulbs[i][j];
            }
        }
        int cnt = 0;
        for (int j = 0; j < 10; j++) {
            if (first_bits & (1 << j)) {
                check(0, j);
                cnt++;
            }
        }
        for (int i = 1; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (bulbs2[i - 1][j]) {
                    check(i, j);
                    cnt++;
                }
            }
        }
        bool fail = false;
        for (int j = 0; j < 10; j++) {
            if (bulbs2[9][j]) {
                fail = true;
                break;
            }
        }
        if (!fail) {
            ans = min(ans, cnt);
        }
    }
    if (ans == INF) {
        cout << "-1\n";
    } else {
        cout << ans << "\n";
    }
    return 0;
}
