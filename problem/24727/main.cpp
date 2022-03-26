#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N;
    cin >> N;
    short A, B;
    cin >> A >> B;
    vector<string> building(N, string(N, '0'));
    short A_cnt = 0;
    for (int yx = 0; yx <= N * 2 - 2; yx++) {
        for (int y = max(0, yx - (N - 1)); y <= min(N - 1, yx); y++) {
            int x = yx - y;
            building[y][x] = '1';
            A_cnt++;
            if (A_cnt == A) {
                break;
            }
        }
        if (A_cnt == A) {
            break;
        }
    }
    short B_cnt = 0;
    for (int yx = N * 2 - 2; yx >= 0; yx--) {
        for (int y = min(N - 1, yx); y >= max(0, yx - (N - 1)); y--) {
            int x = yx - y;
            if (building[y][x] == '1' || (y > 0 && building[y - 1][x] == '1') || (x > 0 && building[y][x - 1] == '1')) {
                cout << "-1\n";
                return 0;
            }
            building[y][x] = '2';
            B_cnt++;
            if (B_cnt == B) {
                break;
            }
        }
        if (B_cnt == B) {
            break;
        }
    }
    cout << "1\n";
    for (auto& row : building) {
        cout << row << "\n";
    }
    return 0;
}
