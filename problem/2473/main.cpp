#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int N;
vector<int> liquid;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    liquid.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> liquid[i];
    }
    sort(liquid.begin(), liquid.end());
    long long min_sum = 1e18;
    tuple<int, int, int> ans = {-1, -1, -1};
    for (int i = 0; i < N - 2; i++) {
        int num = liquid[i];
        int lo = i + 1;
        int hi = N - 1;
        while (lo < hi) {
            int two = liquid[lo] + liquid[hi];
            long long sum = 0LL + num + two;
            if (sum == 0) {
                cout << num << " " << liquid[lo] << " " << liquid[hi] << "\n";
                return 0;
            }
            if (abs(sum) < min_sum) {
                min_sum = abs(sum);
                ans = {i, lo, hi};
            }
            if (two < -num) {
                lo++;
            } else {
                hi--;
            }
        }
    }
    auto [a, b, c] = ans;
    cout << liquid[a] << " " << liquid[b] << " " << liquid[c] << "\n";
    return 0;
}
