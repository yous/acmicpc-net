#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int T;

struct Point {
    long long x, y;

    Point(long long x, long long y) : x(x), y(y) {}

    Point operator-(const Point& rhs) const {
        return {x - rhs.x, y - rhs.y};
    }

    long long operator*(const Point& rhs) const {
        return x * rhs.y - y * rhs.x;
    }

    bool operator<(const Point& rhs) const {
        if (x == rhs.x) {
            return y < rhs.y;
        }
        return x < rhs.x;
    }
};

vector<Point> line;
vector<Point> rect;

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
    cin >> T;
    while (T-- > 0) {
        line.clear();
        rect.clear();
        for (int i = 0; i < 2; i++) {
            long long x, y;
            cin >> x >> y;
            line.emplace_back(x, y);
        }
        for (int i = 0; i < 2; i++) {
            long long x, y;
            cin >> x >> y;
            rect.emplace_back(x, y);
        }
        if (rect[0].x > rect[1].x) {
            swap(rect[0].x, rect[1].x);
        }
        if (rect[0].y > rect[1].y) {
            swap(rect[0].y, rect[1].y);
        }
        rect.emplace_back(rect[0].x, rect[1].y);
        rect.emplace_back(rect[1].x, rect[0].y);
        bool inter = false;
        inter |= intersect(line[0], line[1], rect[0], rect[2]);
        inter |= intersect(line[0], line[1], rect[0], rect[3]);
        inter |= intersect(line[0], line[1], rect[2], rect[1]);
        inter |= intersect(line[0], line[1], rect[3], rect[1]);
        if (inter) {
            cout << "T\n";
            continue;
        }
        if (rect[0].x < line[0].x && line[0].x < rect[1].x &&
                rect[0].y < line[0].y && line[0].y < rect[1].y &&
                rect[0].x < line[1].x && line[1].x < rect[1].x &&
                rect[0].y < line[1].y && line[1].y < rect[1].y) {
            cout << "T\n";
            continue;
        }
        cout << "F\n";
    }
    return 0;
}
