#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;

struct Point {
    int x, y;

    Point(int x, int y) : x(x), y(y) {}

    Point operator-(const Point& rhs) const {
        return {x - rhs.x, y - rhs.y};
    }

    long long operator*(const Point& rhs) const {
        return 1LL * x * rhs.y - 1LL * y * rhs.x;
    }
};

Point P(0, 0);
vector<Point> points;

int ccw(const Point& a, const Point& b, const Point& c) {
    long long res = (b - a) * (c - b);
    return (res == 0 ? 0 : res / abs(res));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> P.x >> P.y;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        points.emplace_back(x, y);
    }
    int ans = 0;
    while (N >= 3) {
        auto min_it = min_element(points.begin(), points.end(), [](const Point& lhs, const Point& rhs) {
            if (lhs.y != rhs.y) {
                return lhs.y < rhs.y;
            }
            return lhs.x < rhs.x;
        });
        swap(points[0], *min_it);
        sort(next(points.begin()), points.end(), [&](const Point& lhs, const Point& rhs) {
            Point dl = lhs - points[0];
            Point dr = rhs - points[0];
            if (1LL * dl.y * dr.x != 1LL * dl.x * dr.y) {
                return 1LL * dl.y * dr.x < 1LL * dl.x * dr.y;
            }
            if (dl.y != dr.y) {
                return dl.y < dr.y;
            }
            return dl.x < dr.x;
        });
        vector<int> st;
        st.push_back(0);
        st.push_back(1);
        for (int i = 2; i < N; i++) {
            int sz;
            while ((sz = st.size()) > 1) {
                int q = st[sz - 1];
                int p = st[sz - 2];
                if (ccw(points[p], points[q], points[i]) > 0) {
                    break;
                }
                st.pop_back();
            }
            st.push_back(i);
        }
        int sz = st.size();
        if (sz < 3) {
            break;
        }
        bool safe = true;
        for (int i = 0; i < sz; i++) {
            if (ccw(points[st[i]], points[st[(i + 1) % sz]], P) <= 0) {
                safe = false;
                break;
            }
        }
        if (!safe) {
            break;
        }
        vector<bool> used(N);
        for (int i = 0; i < sz; i++) {
            used[st[i]] = true;
        }
        vector<Point> tmp;
        for (int i = 0; i < N; i++) {
            if (!used[i]) {
                tmp.emplace_back(points[i]);
            }
        }
        swap(points, tmp);
        ans++;
        N -= sz;
    }
    cout << ans << "\n";
    return 0;
}
