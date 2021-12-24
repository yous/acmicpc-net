#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<pair<int, int>> rect(N);
    for (auto& [x, y] : rect) {
        cin >> x >> y;
        x = -x;
    }
    sort(rect.begin(), rect.end());
    long long ans = 0;
    int cur_y = 0;
    for (auto [x, y] : rect) {
        x = -x;
        if (cur_y < y) {
            ans += 1LL * x * (y - cur_y);
            cur_y = y;
        }
    }
    cout << ans << "\n";
    return 0;
}
