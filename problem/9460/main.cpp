#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T-- > 0) {
        short N;
        int K;
        cin >> N >> K;
        vector<pair<int, int>> metals(N);
        for (auto& [x, y] : metals) {
            cin >> x >> y;
        }
        sort(metals.begin(), metals.end());
        int lo = 0;
        int hi = 200000000;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int cnt = 1;
            int idx = 0;
            int min_y = 100000001;
            int max_y = -100000001;
            while (idx < N) {
                auto [x, y] = metals[idx];
                min_y = min(min_y, y);
                max_y = max(max_y, y);
                if (max_y - min_y > mid) {
                    cnt++;
                    min_y = max_y = y;
                }
                idx++;
            }
            if (cnt <= K) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        cout.precision(1);
        cout << fixed << lo / 2.0 << "\n";
    }
    return 0;
}
