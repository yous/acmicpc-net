#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;

struct Point {
    int x, y;

    long long operator*(const Point& other) const {
        return 1LL* x * other.y - 1LL * y * other.x;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    Point first_p;
    cin >> first_p.x >> first_p.y;
    long long ans = 0;
    Point prev_p = first_p;
    for (int i = 1; i < N; i++) {
        Point point;
        cin >> point.x >> point.y;
        ans += prev_p * point;
        prev_p = point;
    }
    ans += prev_p * first_p;
    if (ans < 0) {
        ans = -ans;
    }
    cout << ans / 2 << (ans % 2 == 0 ? ".0\n" : ".5\n");
    return 0;
}
