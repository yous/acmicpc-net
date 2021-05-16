#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> points;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    while (N-- > 0) {
        int x, y;
        cin >> x >> y;
        points.push_back(make_pair(x, y));
    }
    sort(points.begin(), points.end());
    for (auto point : points) {
        cout << point.first << " " << point.second << "\n";
    }
    return 0;
}
