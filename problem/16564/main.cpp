#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> levels;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    levels.resize(N);
    for (int& level : levels) {
        cin >> level;
    }
    sort(levels.begin(), levels.end());
    int ans = levels[0];
    int idx = 0;
    int cur_cnt = 1;
    while (K > 0) {
        while (idx < N - 1 && levels[idx + 1] == ans) {
            cur_cnt++;
            idx++;
        }
        if (idx < N - 1) {
            int next_level = levels[idx + 1];
            if (K / cur_cnt >= next_level - ans) {
                K -= (next_level - ans) * cur_cnt;
                ans = next_level;
                cur_cnt++;
                idx++;
            } else {
                cout << ans + (K / cur_cnt) << "\n";
                return 0;
            }
        } else {
            cout << ans + (K / cur_cnt) << "\n";
            return 0;
        }
    }
    cout << ans << "\n";
    return 0;
}
