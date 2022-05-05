#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short ax, ay, bx, by, cx, cy, dx, dy;
    cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;
    double lo = 0;
    double hi = 1;
    auto get_dist = [&](double mid) {
        double diff_x = cx - ax + (dx - cx - (bx - ax)) * mid;
        double diff_y = cy - ay + (dy - cy - (by - ay)) * mid;
        return diff_x * diff_x + diff_y * diff_y;
    };
    while (hi - lo >= 1e-9) {
        double mid1 = (lo * 2 + hi) / 3;
        double mid2 = (lo + hi * 2) / 3;
        double d_mid1 = get_dist(mid1);
        double d_mid2 = get_dist(mid2);
        if (d_mid1 >= d_mid2) {
            lo = mid1;
        } else {
            hi = mid2;
        }
    }
    cout.precision(7);
    cout << fixed << sqrt(get_dist(lo)) << "\n";
    return 0;
}
