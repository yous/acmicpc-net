#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<pair<int, int>> LR(11, pair<int, int>(-INF, -INF));
    vector<bool> visited(2048);
    for (int i = 0; i < 2047; i++) {
        vector<int> point(11);
        for (auto& num : point) {
            cin >> num;
        }
        int idx = 0;
        for (int j = 0; j < 11; j++) {
            idx *= 2;
            if (LR[j].first == -INF) {
                LR[j].first = point[j];
            } else if (LR[j].first != point[j]) {
                LR[j].second = point[j];
                idx += 1;
            }
        }
        visited[idx] = true;
    }
    vector<int> ans(11);
    for (int idx = 0; idx < 2048; idx++) {
        if (visited[idx]) {
            continue;
        }
        int cur_idx = idx;
        for (int i = 10; i >= 0; i--) {
            if (cur_idx % 2 == 0) {
                ans[i] = LR[i].first;
            } else {
                ans[i] = LR[i].second;
            }
            cur_idx /= 2;
        }
    }
    cout << ans[0];
    for (int i = 1; i < 11; i++) {
        cout << " " << ans[i];
    }
    cout << "\n";
    return 0;
}
