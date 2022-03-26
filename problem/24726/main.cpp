#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

double get_vol(short r1, short r2, short h) {
    return 1LL * (r1 * r1 + r1 * r2 + r2 * r2) * h * M_PI / 3;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    pair<short, short> tri[3];
    for (auto& [x, y] : tri) {
        cin >> x >> y;
    }
    double x_vol = 0;
    sort(&tri[0], &tri[3]);
    x_vol += get_vol(tri[0].second, tri[2].second, tri[2].first - tri[0].first);
    x_vol -= get_vol(tri[0].second, tri[1].second, tri[1].first - tri[0].first);
    x_vol -= get_vol(tri[1].second, tri[2].second, tri[2].first - tri[1].first);
    x_vol = abs(x_vol);
    double y_vol = 0;
    sort(&tri[0], &tri[3], [](const pair<short, short>& lhs, const pair<short, short>& rhs) {
        if (lhs.second != rhs.second) {
            return lhs.second < rhs.second;
        }
        return lhs.first < rhs.first;
    });
    y_vol += get_vol(tri[0].first, tri[2].first, tri[2].second - tri[0].second);
    y_vol -= get_vol(tri[0].first, tri[1].first, tri[1].second - tri[0].second);
    y_vol -= get_vol(tri[1].first, tri[2].first, tri[2].second - tri[1].second);
    y_vol = abs(y_vol);
    cout.precision(7);
    cout << fixed << x_vol << " " << y_vol << "\n";
    return 0;
}
