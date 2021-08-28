#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

const long long INF = 1e9;

struct Point {
    long long x, y;
    double rx = NAN, ry = NAN;

    Point(long long x, long long y) : x(x), y(y) {}
    Point(double rx, double ry) : rx(rx), ry(ry) {}

    Point operator-(const Point& rhs) const {
        return {x - rhs.x, y - rhs.y};
    }

    long long operator*(const Point& rhs) const {
        return x * rhs.y - y * rhs.x;
    }

    bool operator==(const Point& rhs) const {
        return x == rhs.x && y == rhs.y;
    }

    bool operator<(const Point& rhs) const {
        if (x == rhs.x) {
            return y < rhs.y;
        }
        return x < rhs.x;
    }

    Point operator*(long long rhs) const {
        return {x * rhs, y * rhs};
    }

    Point operator/(double rhs) const {
        return {x / rhs, y / rhs};
    }
};

vector<Point> points;

int ccw(const Point& a, const Point& b, const Point& c) {
    long long res = (b - a) * (c - b);
    return (res == 0 ? 0 : res / abs(res));
}

bool intersect(Point a, Point b, Point c, Point d, Point& r) {
    int abc = ccw(a, b, c);
    int abd = ccw(a, b, d);
    int cda = ccw(c, d, a);
    int cdb = ccw(c, d, b);
    if (abc == 0 && abd == 0) {
        if (b < a) {
            swap(a, b);
        }
        if (d < c) {
            swap(c, d);
        }
        if (d < a || b < c) {
            return false;
        }
        if (a == d) {
            r = a;
        }
        if (b == c) {
            r = b;
        }
        return true;
    }
    if (abc * abd > 0 || cda * cdb > 0) {
        return false;
    }
    Point ab = b - a;
    Point cd = d - c;
    r = ab * (c * d) - cd * (a * b);
    r = r / (ab * cd);
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;
    cout.precision(10);
    for (int i = 0; i < 4; i++) {
        long long x, y;
        cin >> x >> y;
        points.emplace_back(x, y);
    }
    Point r(INF, INF);
    bool inter = intersect(points[0], points[1], points[2], points[3], r);
    cout << inter << "\n";
    if (inter) {
        if (!isnan(r.rx) && !isnan(r.ry)) {
            cout << r.rx << " " << r.ry << "\n";
        } else if (r.x != INF && r.y != INF) {
            cout << r.x << " " << r.y << "\n";
        }
    }
    return 0;
}
