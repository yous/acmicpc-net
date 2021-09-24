#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> locs;
int D;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    locs.resize(N * 2);
    for (int i = 0; i < N; i++) {
        int h, o;
        cin >> h >> o;
        if (h > o) {
            swap(h, o);
        }
        locs[i] = {h, o};
    }
    cin >> D;
    for (int i = 0; i < N; i++) {
        auto [x1, x2] = locs[i];
        if (x2 - x1 > D) {
            locs[i] = {x1, 1};
            locs[i + N] = {x1, -1};
        } else {
            locs[i] = {x2 - D, 1};
            locs[i + N] = {x1 + 1, -1};
        }
    }
    sort(locs.begin(), locs.end());
    int cur = 0;
    int max_cnt = 0;
    int idx = locs[0].first;
    for (auto [x, inc] : locs) {
        if (idx != x) {
            if (max_cnt < cur) {
                max_cnt = cur;
            }
            idx = x;
        }
        cur += inc;
    }
    if (max_cnt < cur) {
        max_cnt = cur;
    }
    cout << max_cnt << "\n";
    return 0;
}
