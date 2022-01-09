#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<pair<int, int>> signals(N);
    for (auto& p : signals) {
        cin >> p.first >> p.second;
    }
    sort(signals.begin(), signals.end());
    int prev_x = signals[0].first;
    int prev_y1 = signals[0].second;
    int prev_y2 = prev_y1;
    int idx = 1;
    while (idx < N && signals[idx].first == prev_x) {
        prev_y2 = signals[idx].second;
        idx++;
    }
    pair<double, double> dist = {0, 0};
    while (idx < N) {
        int x = signals[idx].first;
        int y1 = signals[idx].second;
        int y2 = y1;
        idx++;
        while (idx < N && signals[idx].first == x) {
            y2 = signals[idx].second;
            idx++;
        }
        int dx = x - prev_x;
        int dy11 = abs(y1 - prev_y1);
        int dy21 = abs(y1 - prev_y2);
        int dy12 = abs(y2 - prev_y1);
        int dy22 = abs(y2 - prev_y2);
        double dist1 = max(dist.first + sqrt(1LL * dx * dx + 1LL * dy11 * dy11),
                           dist.second + sqrt(1LL * dx * dx + 1LL * dy21 * dy21));
        double dist2 = max(dist.first + sqrt(1LL * dx * dx + 1LL * dy12 * dy12),
                           dist.second + sqrt(1LL * dx * dx + 1LL * dy22 * dy22));
        dist = {dist1, dist2};
        prev_x = x;
        prev_y1 = y1;
        prev_y2 = y2;
    }
    cout.precision(8);
    cout << max(dist.first, dist.second) << "\n";
    return 0;
}
