#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N, M;
    cin >> N >> M;
    vector<vector<bool>> lamps(N, vector<bool>(M));
    for (auto& row : lamps) {
        for (int x = 0; x < M; x++) {
            char ch;
            cin >> ch;
            row[x] = ch == '1';
        }
    }
    short K;
    cin >> K;
    short ans = 0;
    for (int y = 0; y < N; y++) {
        vector<bool> turn_on(M);
        short cnt = 0;
        for (int x = 0; x < M; x++) {
            if (!lamps[y][x]) {
                turn_on[x] = true;
                cnt++;
            }
        }
        if (cnt > K || (K - cnt) % 2 != 0) {
            continue;
        }
        cnt = 1;
        for (int ny = 0; ny < N; ny++) {
            if (ny == y) {
                continue;
            }
            bool all_on = true;
            for (int x = 0; x < M; x++) {
                if ((lamps[ny][x] && turn_on[x]) || (!lamps[ny][x] && !turn_on[x])) {
                    all_on = false;
                    break;
                }
            }
            if (all_on) {
                cnt++;
            }
        }
        if (cnt > ans) {
            ans = cnt;
        }
    }
    cout << ans << "\n";
    return 0;
}
