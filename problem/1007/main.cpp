#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

const long long INF = 4e18;
int T;
int N;
long long min_sum;

struct Point {
    int x, y;

    Point() : x(0), y(0) {}
    Point(int x, int y) : x(x), y(y) {}

    Point operator+(const Point& rhs) const {
        return {x + rhs.x, y + rhs.y};
    }

    Point operator-(const Point& rhs) const {
        return {x - rhs.x, y - rhs.y};
    }
};

vector<Point> points;
Point min_point;

void dfs(int idx, int cnt, Point cur_sum) {
    if (cnt == N / 2) {
        auto [x, y] = cur_sum;
        for (int i = idx; i < N; i++) {
            x -= points[i].x;
            y -= points[i].y;
        }
        long long tmp = 1LL * x * x + 1LL * y * y;
        if (tmp < min_sum) {
            min_sum = tmp;
            min_point = {x, y};
        }
        return;
    }
    if (idx == N) {
        return;
    }
    dfs(idx + 1, cnt + 1, cur_sum + points[idx]);
    dfs(idx + 1, cnt, cur_sum - points[idx]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    cout.precision(7);
    cout << fixed;
    while (T-- > 0) {
        cin >> N;
        points.clear();
        for (int i = 0; i < N; i++) {
            int x, y;
            cin >> x >> y;
            points.emplace_back(x, y);
        }
        min_sum = INF;
        dfs(0, 0, {0, 0});
        cout << sqrt(1LL * min_point.x * min_point.x + 1LL * min_point.y * min_point.y) << "\n";
    }
    return 0;
}
