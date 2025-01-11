#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<int>> cache(10000 + 1, vector<int>(3));
    cache[1] = {1, 0, 0};
    cache[2] = {1, 1, 0};
    cache[3] = {2, 0, 1};
    for (int n = 4; n <= 10000; n++) {
        cache[n] = {
            cache[n - 1][0] + cache[n - 1][1] + cache[n - 1][2],
            cache[n - 2][1] + cache[n - 2][2],
            cache[n - 3][2]
        };
    }
    int T;
    cin >> T;
    while (T-- > 0) {
        short N;
        cin >> N;
        cout << cache[N][0] + cache[N][1] + cache[N][2] << "\n";
    }
    return 0;
}
