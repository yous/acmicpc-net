#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> yx_clovers(N);
    vector<pair<int, int>> xy_clovers(N);
    for (int i = 0; i < N; i++) {
        int X, Y;
        cin >> X >> Y;
        yx_clovers[i] = {Y, X};
        xy_clovers[i] = {X, Y};
    }
    sort(yx_clovers.begin(), yx_clovers.end());
    sort(xy_clovers.begin(), xy_clovers.end());
    pair<int, int> cur_loc = {0, 0};
    string cmds;
    cin >> cmds;
    for (auto ch : cmds) {
        if (ch == 'L') {
            swap(cur_loc.first, cur_loc.second);
            cur_loc = *prev(lower_bound(yx_clovers.begin(), yx_clovers.end(), cur_loc));
            swap(cur_loc.first, cur_loc.second);
        } else if (ch == 'R') {
            swap(cur_loc.first, cur_loc.second);
            cur_loc = *upper_bound(yx_clovers.begin(), yx_clovers.end(), cur_loc);
            swap(cur_loc.first, cur_loc.second);
        } else if (ch == 'U') {
            cur_loc = *upper_bound(xy_clovers.begin(), xy_clovers.end(), cur_loc);
        } else {
            cur_loc = *prev(lower_bound(xy_clovers.begin(), xy_clovers.end(), cur_loc));
        }
    }
    cout << cur_loc.first << " " << cur_loc.second << "\n";
    return 0;
}
