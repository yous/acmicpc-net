#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (true) {
        short N;
        cin >> N;
        short num1, num2;
        char ch;
        cin >> num1 >> ch >> num2;
        short M = num1 * 100 + num2;
        if (N == 0 && M == 0) {
            break;
        }
        vector<pair<short, short>> candies(N);
        for (auto& [c, p] : candies) {
            cin >> c;
            cin >> num1 >> ch >> num2;
            p = num1 * 100 + num2;
        }
        vector<int> ans(10001);
        for (auto [c, p] : candies) {
            ans[p] = max(ans[p], int(c));
            for (int price_sum = p; price_sum <= M; price_sum++) {
                ans[price_sum] = max(ans[price_sum], c + ans[price_sum - p]);
            }
        }
        int max_cal = 0;
        for (int p = 1; p <= M; p++) {
            max_cal = max(max_cal, ans[p]);
        }
        cout << max_cal << "\n";
    }
    return 0;
}
