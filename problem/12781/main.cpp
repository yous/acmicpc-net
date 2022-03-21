#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Point {
    short x, y;

    Point() : x(0), y(0) {}
    Point(short x, short y) : x(x), y(y) {}

    Point operator-(const Point& other) const {
        return Point(x - other.x, y - other.y);
    }

    int operator*(const Point& other) const {
        return x * other.y - y * other.x;
    }
};

int ccw(const Point& a, const Point& b, const Point& c) {
    int res = (b - a) * (c - a);
    return res == 0 ? res : res / abs(res);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Point points[4];
    for (int i = 0; i < 4; i++) {
        short x, y;
        cin >> x >> y;
        points[i] = Point(x, y);
    }
    if (ccw(points[0], points[1], points[2]) * ccw(points[0], points[1], points[3]) < 0) {
        cout << "1\n";
    } else {
        cout << "0\n";
    }
    return 0;
}
