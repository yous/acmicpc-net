#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Point {
    short x, y;

    Point(short x, short y) : x(x), y(y) {}

    Point operator-(const Point& rhs) const {
        return Point(x - rhs.x, y - rhs.y);
    }

    int operator*(const Point& rhs) const {
        return x * rhs.y - y * rhs.x;
    }
};

vector<Point> points;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 0; i < 3; i++) {
        short x, y;
        cin >> x >> y;
        points.emplace_back(x, y);
    }
    int ccw = (points[1] - points[0]) * (points[2] - points[1]);
    cout << (ccw > 0 ? 1 : (ccw < 0 ? -1 : 0)) << "\n";
    return 0;
}
