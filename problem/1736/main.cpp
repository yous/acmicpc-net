#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N, M;
    cin >> N >> M;
    vector<vector<bool>> field(N, vector<bool>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int num;
            cin >> num;
            field[i][j] = num;
        }
    }
    vector<short> cur_ys;
    int cnt = 0;
    for (int x = 0; x < M; x++) {
        int cur_idx = 0;
        for (int y = 0; y < N; y++) {
            if (!field[y][x]) {
                continue;
            }
            if (cur_ys.empty()) {
                cur_ys.emplace_back(y);
                cnt++;
                continue;
            }
            if (cur_ys[cur_idx] > y) {
                cur_ys.emplace(cur_ys.begin() + cur_idx, y);
                cnt++;
            } else {
                while (cur_idx < cnt && cur_ys[cur_idx] <= y) {
                    cur_idx++;
                }
                cur_idx--;
                if (cur_ys[cur_idx] <= y) {
                    cur_ys[cur_idx] = y;
                } else {
                    cur_ys.emplace(cur_ys.begin() + cur_idx, y);
                }
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}
