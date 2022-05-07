#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N;
    cin >> N;
    vector<pair<short, short>> buildings(N);
    for (auto& [x, y] : buildings) {
        cin >> x >> y;
    }
    int ans_dist = 20000 * 20000 + 20000 * 20000;
    int ans = -1;
    for (int i = 0; i < N; i++) {
        auto [x, y] = buildings[i];
        int max_dist = 0;
        for (int j = 0; j < N; j++) {
            if (i == j) {
                continue;
            }
            auto [ox, oy] = buildings[j];
            int dist = (oy - y) * (oy - y) + (ox - x) * (ox - x);
            if (max_dist < dist) {
                max_dist = dist;
            }
        }
        if (ans_dist > max_dist) {
            ans_dist = max_dist;
            ans = i;
        }
    }
    cout << buildings[ans].first << " " << buildings[ans].second << "\n";
    return 0;
}
