#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> lines;
int D;
vector<pair<int, int>> locs;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    lines.resize(N);
    for (int i = 0; i < N; i++) {
        int h, o;
        cin >> h >> o;
        if (h > o) {
            swap(h, o);
        }
        lines[i] = {h, o};
    }
    cin >> D;
    for (auto [x1, x2] : lines) {
        if (x2 - x1 > D) {
            continue;
        }
        locs.emplace_back(x2 - D, 1);
        locs.emplace_back(x1 + 1, -1);
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
