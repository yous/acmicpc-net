#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> points;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    int x, y;
    while (N-- > 0) {
        cin >> x >> y;
        points.push_back({y, x});
    }
    sort(points.begin(), points.end());
    for (auto& point : points) {
        cout << point.second << " " << point.first << "\n";
    }
    return 0;
}
