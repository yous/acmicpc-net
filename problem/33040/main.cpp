#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int H, W;
    cin >> H >> W;
    int C, D;
    cin >> C >> D;
    if (H > W + 1) {
        cout << "-1\n";
        return 0;
    }
    int min_sum = H * (H - 1) / 2;
    if (C < min_sum || D < min_sum) {
        cout << "-1\n";
        return 0;
    }
    int D_rem = D;
    for (int y = 0; y < H; y++) {
        int offset = (D_rem - min_sum) / (H - y);
        bool first = true;
        for (int x = 0; x < W - (offset + y); x++) {
            if (first) {
                first = false;
            } else {
                cout << " ";
            }
            cout << "1";
        }
        for (int x = 0; x < offset + y; x++) {
            if (first) {
                first = false;
            } else {
                cout << " ";
            }
            cout << "9";
        }
        D_rem -= offset + y;
        min_sum -= y;
        cout << "\n";
    }
    return 0;
}
