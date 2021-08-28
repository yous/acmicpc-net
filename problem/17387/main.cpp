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

    bool operator<(const Point& rhs) const {
        if (x == rhs.x) {
            return y < rhs.y;
        }
        return x < rhs.x;
    }
};

vector<Point> points;

int ccw(const Point& a, const Point& b, const Point& c) {
    long long res = (b - a) * (c - b);
    return (res == 0 ? 0 : res / abs(res));
}

bool intersect(Point a, Point b, Point c, Point d) {
    int ab = ccw(a, b, c) * ccw(a, b, d);
    int cd = ccw(c, d, a) * ccw(c, d, b);
    if (ab == 0 && cd == 0) {
        if (b < a) {
            swap(a, b);
        }
        if (d < c) {
            swap(c, d);
        }
        return !(d < a || b < c);
    }
    return ab <= 0 && cd <= 0;
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
