#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short R, C, W;
    cin >> R >> C >> W;
    vector<vector<long long>> pascal(R + W, vector<long long>(R + W));
    pascal[0][0] = 1;
    for (int y = 1; y < R + W; y++) {
        pascal[y][0] = 1;
        pascal[y][y] = 1;
        for (int x = 1; x < y; x++) {
            pascal[y][x] = pascal[y - 1][x - 1] + pascal[y - 1][x];
        }
    }
    long long sum = 0;
    for (int y = R - 1; y < R + W - 1; y++) {
        for (int x = C - 1; x <= C + y - R; x++) {
            sum += pascal[y][x];
        }
    }
    cout << sum << "\n";
    return 0;
}
