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

int ccw(const Point& a, const Point& b, const Point& c) {
    int res = (b - a) * (c - b);
    return (res == 0 ? 0 : res / abs(res));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    vector<Point> triangle;
    for (int i = 0; i < 3; i++) {
        short x, y;
        cin >> x >> y;
        triangle.emplace_back(x, y);
    }
    Point ab = triangle[1] - triangle[0];
    Point ac = triangle[2] - triangle[0];
    cout.precision(1);
    cout << fixed << abs(ab * ac) / 2.0 << "\n";
    cin >> N;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        short x, y;
        cin >> x >> y;
        Point p(x, y);
        int ab = ccw(triangle[0], triangle[1], p);
        int bc = ccw(triangle[1], triangle[2], p);
        int ca = ccw(triangle[2], triangle[0], p);
        if ((ab <= 0 && bc <= 0 && ca <= 0) || (ab >= 0 && bc >= 0 && ca >= 0)) {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
