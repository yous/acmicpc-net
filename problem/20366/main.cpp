#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N;
    cin >> N;
    vector<int> heights(N);
    for (auto& num : heights) {
        cin >> num;
    }
    sort(heights.begin(), heights.end());
    int ans = heights[N - 2] + heights[N - 1] - heights[0] - heights[1];
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            int snowman = heights[i] + heights[j];
            int lo = 0;
            while (lo == i || lo == j) {
                lo++;
            }
            int hi = N - 1;
            while (hi == i || hi == j) {
                hi--;
            }
            while (lo < hi && heights[lo] + heights[hi] < snowman) {
                lo++;
                while (lo == i || lo == j) {
                    lo++;
                }
            }
            if (lo >= hi) {
                continue;
            }
            ans = min(ans, heights[lo] + heights[hi] - snowman);
            while (lo < hi) {
                int prev_hi;
                while (lo < hi && heights[lo] + heights[hi] >= snowman) {
                    prev_hi = hi;
                    hi--;
                    while (hi == i || hi == j) {
                        hi--;
                    }
                }
                ans = min(ans, heights[lo] + heights[prev_hi] - snowman);
                lo++;
                while (lo == i || lo == j) {
                    lo++;
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
