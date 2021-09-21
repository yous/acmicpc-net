#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

short N;

struct DisjointSet {
    vector<int> group;
    vector<int> cnt;
    int max_cnt;

    DisjointSet(int n) : group(n), cnt(n), max_cnt(1) {
        for (int i = 0; i < n; i++) {
            group[i] = i;
            cnt[i] = 1;
        }
    }

    int find(int n) {
        if (n == group[n]) {
            return group[n];
        }
        return group[n] = find(group[n]);
    }

    bool merge(int p, int q) {
        int gp = find(p);
        int gq = find(q);
        if (gp != gq) {
            group[gp] = gq;
            cnt[gq] += cnt[gp];
            if (cnt[gq] > max_cnt) {
                max_cnt = cnt[gq];
            }
            return true;
        }
        return false;
    }
};

struct Point {
    short x, y;

    Point(short x, short y) : x(x), y(y) {}

    Point operator-(const Point& rhs) const {
        return Point(x - rhs.x, y - rhs.y);
    }

    int operator*(const Point& rhs) const {
        return x * rhs.y - y * rhs.x;
    }

    bool operator<(const Point& rhs) const {
        if (y != rhs.y) {
            return y < rhs.y;
        }
        return x < rhs.x;
    }
};

vector<Point> points;

int ccw(const Point& a, const Point& b, const Point& c) {
    int res = (b - a) * (c - b);
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
    cin >> N;
    DisjointSet ds(N);
    for (int i = 0; i < N; i++) {
        short x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        points.emplace_back(x1, y1);
        points.emplace_back(x2, y2);
    }
    int ans = N;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (intersect(points[i * 2], points[i * 2 + 1], points[j * 2], points[j * 2 + 1])) {
                if (ds.merge(i, j)) {
                    ans--;
                }
            }
        }
    }
    cout << ans << "\n";
    cout << ds.max_cnt << "\n";
    return 0;
}
