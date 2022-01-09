#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    map<int, pair<int, int>> signals;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        auto it = signals.find(x);
        if (it == signals.end()) {
            signals.emplace_hint(it, x, make_pair(y, y));
        } else {
            auto& [v_min, v_max] = it->second;
            if (v_min > y) {
                v_min = y;
            }
            if (v_max < y) {
                v_max = y;
            }
        }
    }
    int prev_x = signals.begin()->first;
    pair<int, int>& prev_y = signals.begin()->second;
    pair<double, double> dist = {0, 0};
    for (auto it = next(signals.begin()); it != signals.end(); ++it) {
        int dx = it->first - prev_x;
        auto [y1, y2] = it->second;
        int dy11 = abs(y1 - prev_y.first);
        int dy21 = abs(y1 - prev_y.second);
        int dy12 = abs(y2 - prev_y.first);
        int dy22 = abs(y2 - prev_y.second);
        double dist1 = max(dist.first + sqrt(1LL * dx * dx + 1LL * dy11 * dy11),
                           dist.second + sqrt(1LL * dx * dx + 1LL * dy21 * dy21));
        double dist2 = max(dist.first + sqrt(1LL * dx * dx + 1LL * dy12 * dy12),
                           dist.second + sqrt(1LL * dx * dx + 1LL * dy22 * dy22));
        dist = {dist1, dist2};
        prev_x = it->first;
        prev_y = it->second;
    }
    cout.precision(8);
    cout << max(dist.first, dist.second) << "\n";
    return 0;
}
