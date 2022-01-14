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

    int operator<(const Point& rhs) const {
        if (y != rhs.y) {
            return y < rhs.y;
        }
        return x < rhs.x;
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
        bool inside = true;
        int sign = 0;
        for (int j = 0; j < 3; j++) {
            Point& a = triangle[j];
            Point& b = triangle[(j + 1) % 3];
            int res = ccw(a, b, p);
            if (res == 0) {
                if ((p < a && p < b) || (a < p && b < p)) {
                    inside = false;
                    break;
                } else {
                    inside = true;
                    break;
                }
            } else {
                if (sign == 0) {
                    sign = res / abs(res);
                } else if (sign != res / abs(res)) {
                    inside = false;
                    break;
                }
            }
        }
        if (inside) {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
