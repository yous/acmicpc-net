#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x, y;

    Point(int x, int y) : x(x), y(y) {}

    Point operator-(const Point& rhs) const {
        return {x - rhs.x, y - rhs.y};
    }

    long long operator*(const Point& rhs) const {
        return 1LL * x * rhs.y - 1LL * y * rhs.x;
    }
};

vector<Point> points;

int ccw(const Point& a, const Point& b, const Point& c) {
    long long res = (b - a) * (c - b);
    return (res == 0 ? 0 : res / abs(res));
}

bool intersect(const Point& a, const Point& b, const Point& c, const Point& d) {
    return ccw(a, b, c) * ccw(a, b, d) < 0 && ccw(c, d, a) * ccw(c, d, b) < 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 0; i < 4; i++) {
        int x, y;
        cin >> x >> y;
        points.emplace_back(x, y);
    }
    cout << intersect(points[0], points[1], points[2], points[3]) << "\n";
    return 0;
}
