#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> points;

int main() {
    scanf("%d", &N);
    while (N-- > 0) {
        int x, y;
        scanf("%d %d", &x, &y);
        points.push_back(make_pair(x, y));
    }
    sort(points.begin(), points.end());
    for (auto point : points) {
        printf("%d %d\n", point.first, point.second);
    }
    return 0;
}
