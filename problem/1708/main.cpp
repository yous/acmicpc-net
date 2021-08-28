#include <algorithm>
#include <iostream>
#include <stack>
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

vector<Point> points;

int ccw(const Point& a, const Point& b, const Point& c) {
    long long res = (b - a) * (c - b);
    return (res == 0 ? 0 : res / abs(res));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    Point min_p(40001, 40001);
    int min_idx = -1;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        points.emplace_back(x, y);
        if (y < min_p.y || (y == min_p.y && x < min_p.x)) {
            min_p = {x, y};
            min_idx = i;
        }
    }
    swap(points[0], points[min_idx]);
    sort(next(points.begin()), points.end(), [&](const Point& lhs, const Point& rhs) {
        Point dl = lhs - points[0];
        Point dr = rhs - points[0];
        if (1LL * dl.y * dr.x != 1LL * dl.x * dr.y) {
            return 1LL * dl.y * dr.x < 1LL * dl.x * dr.y;
        }
        if (dl.y == dr.y) {
            return dl.x < dr.x;
        }
        return dl.y < dr.y;
    });
    stack<int> st;
    st.push(0);
    st.push(1);
    for (int i = 2; i < N; i++) {
        while (st.size() > 1) {
            int q = st.top();
            st.pop();
            int p = st.top();
            if (ccw(points[p], points[q], points[i]) > 0) {
                st.push(q);
                break;
            }
        }
        st.push(i);
    }
    cout << st.size() << "\n";
    return 0;
}
