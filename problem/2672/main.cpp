#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<tuple<int, int, int, int>> points(N * 2);
    for (int i = 0; i < N; i++) {
        double x, y, w, h;
        cin >> x >> y >> w >> h;
        int xi = x * 10,
            yi = y * 10,
            wi = w * 10,
            hi = h * 10;
        points[i * 2] = {xi, yi, yi + hi, 1};
        points[i * 2 + 1] = {xi + wi, yi, yi + hi, -1};
    }
    sort(points.begin(), points.end());
    auto [prev_x, y1, y2, diff] = points[0];
    int ans = 0;
    vector<int> ys(20001);
    ys[y1] += diff;
    ys[y2] -= diff;
    for (int i = 1; i < N * 2; i++) {
        auto [x, y1, y2, diff] = points[i];
        if (prev_x < x) {
            int cnt = 0;
            int len = 0;
            for (int y = 0; y <= 20000; y++) {
                cnt += ys[y];
                if (cnt > 0) {
                    len++;
                }
            }
            ans += len * (x - prev_x);
        }
        ys[y1] += diff;
        ys[y2] -= diff;
        prev_x = x;
    }
    cout << ans / 100;
    if (ans % 100 > 0) {
        cout << "." << (ans % 100 / 10) << ans % 10;
    }
    cout << "\n";
    return 0;
}
