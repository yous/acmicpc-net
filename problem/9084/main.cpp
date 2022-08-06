#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short T;
    cin >> T;
    while (T-- > 0) {
        short N;
        cin >> N;
        vector<short> coins(N);
        for (short& num : coins) {
            cin >> num;
        }
        short M;
        cin >> M;
        vector<int> ans(10001);
        for (short coin : coins) {
            ans[coin]++;
            for (int sum = coin; sum <= M; sum++) {
                ans[sum] += ans[sum - coin];
            }
        }
        cout << ans[M] << "\n";
    }
    return 0;
}
