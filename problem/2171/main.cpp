#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> x_points;
vector<pair<int, int>> y_points;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    x_points.resize(N);
    y_points.resize(N);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        x_points[i] = {x, y};
        y_points[i] = {y, x};
    }
    sort(x_points.begin(), x_points.end());
    sort(y_points.begin(), y_points.end());
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        int x1 = x_points[i].first;
        int y1 = x_points[i].second;
        auto it = lower_bound(y_points.begin(), y_points.end(), make_pair(y1, x1 + 1));
        while (it != y_points.end() && it->first == y1) {
            int x2 = it->second;
            for (int j = i + 1; j < N; j++) {
                if (x_points[j].first != x1) {
                    break;
                }
                int y2 = x_points[j].second;
                auto it2 = lower_bound(x_points.begin(), x_points.end(), make_pair(x2, y2));
                if (it2 != x_points.end() && it2->first == x2 && it2->second == y2) {
                    ans++;
                }
            }
            it++;
        }
    }
    cout << ans << "\n";
    return 0;
}
