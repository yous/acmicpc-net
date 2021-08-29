#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int T;
short x_min, y_min, x_max, y_max;
short x1, y1, x2, y2;

struct Point {
    short x, y;

    Point(short x, short y) : x(x), y(y) {}

    Point operator-(const Point& rhs) const {
        return Point(x - rhs.x, y - rhs.y);
    }

    int operator*(const Point& rhs) const {
        return x * rhs.y - y * rhs.x;
    }

    bool operator==(const Point& rhs) const {
        return x == rhs.x && y == rhs.y;
    }

    bool operator<(const Point& rhs) const {
        if (x != rhs.x) {
            return x < rhs.x;
        }
        return y < rhs.y;
    }
};

int ccw(const Point& a, const Point& b, const Point& c) {
    int res = (b - a) * (c - b);
    return (res == 0 ? 0 : res / abs(res));
}

int intersect(Point a, Point b, Point c, Point d, Point& r) {
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
            return 0;
        }
        if (a == d) {
            r = a;
            return 1;
        }
        if (b == c) {
            r = b;
            return 1;
        }
        return 4;
    }
    if (abc * abd > 0 || cda * cdb > 0) {
        return 0;
    }
    if (abc == 0) {
        r = c;
    }
    if (abd == 0) {
        r = d;
    }
    if (cda == 0) {
        r = a;
    }
    if (cdb == 0) {
        r = b;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T-- > 0) {
        cin >> x_min >> y_min >> x_max >> y_max;
        cin >> x1 >> y1 >> x2 >> y2;
        vector<Point> rect;
        rect.emplace_back(x_min, y_min);
        rect.emplace_back(x_max, y_min);
        rect.emplace_back(x_max, y_max);
        rect.emplace_back(x_min, y_max);
        vector<Point> line;
        line.emplace_back(x1, y1);
        line.emplace_back(x2, y2);
        int ans = 0;
        vector<Point> inters;
        for (int i = 0; i < 4; i++) {
            Point inter(10001, 10001);
            int cnt = intersect(line[0], line[1], rect[i], rect[(i + 1) % 4], inter);
            if (cnt == 4) {
                ans = 4;
                break;
            }
            if (cnt == 0) {
                continue;
            }
            if (cnt == 1) {
                if (inter.x != 10001 && inter.y != 10001) {
                    bool found = false;
                    for (auto p : inters) {
                        if (p == inter) {
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        inters.emplace_back(inter);
                        ans++;
                    }
                } else {
                    ans++;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
