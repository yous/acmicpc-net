#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int T;
short N, M;

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

vector<Point> blacks;
vector<Point> whites;
vector<int> black_convex;
vector<int> white_convex;

int ccw(const Point& a, const Point& b, const Point& c) {
    int res = (b - a) * (c - b);
    return (res == 0 ? 0 : res / abs(res));
}

void make_convex(vector<Point>& points, int cnt, vector<int>& convex) {
    int min_idx = 0;
    Point min_p(10001, 10001);
    for (int i = 0; i < cnt; i++) {
        short x, y;
        cin >> x >> y;
        points.emplace_back(x, y);
        if (y < min_p.y || (y == min_p.y && x < min_p.x)) {
            min_idx = i;
            min_p = {x, y};
        }
    }
    swap(points[0], points[min_idx]);
    sort(next(points.begin()), points.end(), [&](const Point& lhs, const Point& rhs) {
        int ret = ccw(points[0], lhs, rhs);
        return ret > 0 || (ret == 0 && lhs < rhs);
    });
    if (cnt == 1) {
        return;
    }
    convex.push_back(0);
    convex.push_back(1);
    for (int i = 2; i < cnt; i++) {
        while (convex.size() > 1) {
            int q = *convex.rbegin();
            int p = *next(convex.rbegin());
            if (ccw(points[p], points[q], points[i]) > 0) {
                break;
            }
            convex.pop_back();
        }
        convex.push_back(i);
    }
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
        blacks.clear();
        whites.clear();
        black_convex.clear();
        white_convex.clear();
        cin >> N >> M;
        make_convex(blacks, N, black_convex);
        make_convex(whites, M, white_convex);
        if (N > M) {
            swap(N, M);
            swap(blacks, whites);
            swap(black_convex, white_convex);
        }
        if (N == 1 && M == 1) {
            cout << "YES\n";
            continue;
        } else if (N == 1) {
            if (M == 2) {
                auto [x_min, x_max] = minmax(whites[0].x, whites[1].x);
                auto [y_min, y_max] = minmax(whites[0].y, whites[1].y);
                if (ccw(blacks[0], whites[0], whites[1]) == 0 &&
                        x_min <= blacks[0].x && blacks[0].x <= x_max &&
                        y_min <= blacks[0].y && blacks[0].y <= y_max) {
                    cout << "NO\n";
                } else {
                    cout << "YES\n";
                }
                continue;
            }
            int sz = white_convex.size();
            bool is_inside = true;
            for (int i = 0; i < sz; i++) {
                int a = white_convex[i];
                int b = white_convex[(i + 1) % sz];
                if (ccw(whites[a], whites[b], blacks[0]) < 0) {
                    is_inside = false;
                    break;
                }
            }
            if (is_inside) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
            }
            continue;
        } else if (N == 2 && M == 2) {
            if (intersect(blacks[0], blacks[1], whites[0], whites[1])) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
            }
            continue;
        }
        int black_sz = black_convex.size();
        int white_sz = white_convex.size();
        if (black_sz >= 3 && white_sz >= 3) {
            bool found = false;
            for (int i = 0; i < black_sz; i++) {
                for (int j = 0; j < white_sz; j++) {
                    if (intersect(blacks[black_convex[i]], blacks[black_convex[(i + 1) % black_sz]],
                                whites[white_convex[j]], whites[white_convex[(j + 1) % white_sz]])) {
                        found = true;
                        break;
                    }
                }
                if (found) {
                    break;
                }
            }
            if (found) {
                cout << "NO\n";
                continue;
            }
        }
        if (black_sz >= 3) {
            bool is_inside = true;
            for (int i = 0; i < black_sz; i++) {
                for (int j = 0; j < M; j++) {
                    if (ccw(blacks[black_convex[i]], blacks[black_convex[(i + 1) % black_sz]], whites[j]) < 0) {
                        is_inside = false;
                        break;
                    }
                }
                if (!is_inside) {
                    break;
                }
            }
            if (is_inside) {
                cout << "NO\n";
                continue;
            }
        }
        if (white_sz >= 3) {
            bool is_inside = true;
            for (int i = 0; i < white_sz; i++) {
                for (int j = 0; j < N; j++) {
                    if (ccw(whites[white_convex[i]], whites[white_convex[(i + 1) % white_sz]], blacks[j]) < 0) {
                        is_inside = false;
                        break;
                    }
                }
                if (!is_inside) {
                    break;
                }
            }
            if (is_inside) {
                cout << "NO\n";
                continue;
            }
        }
        cout << "YES\n";
    }
    return 0;
}
