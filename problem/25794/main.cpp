#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int X, Y;
    cin >> X >> Y;
    if (X == 0 || Y == 0 || X == Y) {
        cout << "7\n";
        int x = 0;
        int y = 0;
        int dx[] = {1, 1, 1, -1, -1, -1, 1};
        int dy[] = {1, -1, -1, -1, -1, 1, 1};
        for (int i = 0; i < 7; i++) {
            if (dx[i] * dy[i] > 0) {
                x += dx[i] * X;
                y += dy[i] * Y;
            } else {
                x += dx[i] * Y;
                y += dy[i] * X;
            }
            cout << x << " " << y << "\n";
        }
        return 0;
    }
    cout << "15\n";
    int x = 0;
    int y = 0;
    bool xy[] = {
        true, false, false, true, true, false,
        false, true,
        true, false, false, true, true, false, true
    };
    int dx[] = {
        1, 1, 1, -1, -1, -1,
        1, 1,
        1, -1, -1, -1, -1, 1, 1
    };
    int dy[] = {
        1, -1, -1, -1, -1, 1,
        1, 1,
        -1, -1, -1, 1, 1, 1, -1
    };
    for (int i = 0; i < 15; i++) {
        if (xy[i]) {
            x += dx[i] * X;
            y += dy[i] * Y;
        } else {
            x += dx[i] * Y;
            y += dy[i] * X;
        }
        cout << x << " " << y << "\n";
    }
    return 0;
}
