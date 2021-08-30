#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

short C;
short N;

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

vector<pair<Point, short>> points;

int ccw(const Point& a, const Point& b, const Point& c) {
    int res = (b - a) * (c - b);
    return (res == 0 ? 0 : res / abs(res));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> C;
    while (C-- > 0) {
        cin >> N;
        points.clear();
        short min_idx = -1;
        Point min_p(10001, 10001);
        for (int i = 0; i < N; i++) {
            short x, y;
            cin >> x >> y;
            Point p(x, y);
            points.emplace_back(p, i);
            if (p.y < min_p.y || (p.y == min_p.y && p.x < min_p.x)) {
                min_idx = i;
                min_p = p;
            }
        }
        swap(points[0], points[min_idx]);
        sort(next(points.begin()), points.end(), [&](const auto& lhs, const auto& rhs) {
            Point dl = lhs.first - points[0].first;
            Point dr = rhs.first - points[0].first;
            if (dl.y * dr.x != dl.x * dr.y) {
                return dl.y * dr.x < dl.x * dr.y;
            }
            if (dl.y != dr.y) {
                return dl.y < dr.y;
            }
            return dl.x < dr.x;
        });
        Point last_d = points.rbegin()->first - points[0].first;
        int cnt = 1;
        for (auto it = next(points.rbegin()); it != points.rend(); ++it) {
            Point d = it->first - points[0].first;
            if (last_d.y * d.x != last_d.x * d.y) {
                break;
            }
            cnt++;
        }
        reverse(points.rbegin(), next(points.rbegin(), cnt));
        bool is_first = true;
        for (auto& [p, idx] : points) {
            if (is_first) {
                is_first = false;
                cout << idx;
            } else {
                cout << " " << idx;
            }
        }
        cout << "\n";
    }
    return 0;
}
