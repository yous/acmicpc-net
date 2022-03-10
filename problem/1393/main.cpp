#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short xs, ys;
    cin >> xs >> ys;
    short xe, ye, dx, dy;
    cin >> xe >> ye >> dx >> dy;
    if (dx == 0) {
        if (ys >= ye) {
            cout << xe << " " << ys;
        } else {
            cout << xe << " " << ye;
        }
        return 0;
    }
    auto get_y = [&](const int x) {
        return dy * (x - xe) / dx + ye;
    };
    short lo = xe;
    short hi = 200;
    while (lo <= hi) {
        short mid = (lo + hi) / 2;
        short y1 = get_y(mid);
        short y2 = get_y(mid + 1);
        int dist1 = (ys - y1) * (ys - y1) + (xs - mid) * (xs - mid);
        int dist2 = (ys - y2) * (ys - y2) + (xs - mid - 1) * (xs - mid - 1);
        if (dist1 <= dist2) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo << " " << get_y(lo) << "\n";
    return 0;
}
