#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int t = 0; t < 3; t++) {
        short N;
        cin >> N;
        vector<pair<int, int>> coins(N);
        int sum = 0;
        for (auto& [price, cnt] : coins) {
            cin >> price >> cnt;
            sum += price * cnt;
        }
        if (sum % 2 == 1) {
            cout << "0\n";
            continue;
        }
        vector<bool> visited(100001);
        auto [price, cnt] = coins[0];
        for (int c = 0; c <= cnt; c++) {
            if (c * price > sum / 2) {
                break;
            }
            visited[c * price] = true;
        }
        if (visited[sum / 2]) {
            cout << "1\n";
            continue;
        }
        bool found = false;
        for (int i = 1; i < N; i++) {
            auto [price, cnt] = coins[i];
            for (int cur_sum = sum / 2; cur_sum >= 0; cur_sum--) {
                if (visited[cur_sum]) {
                    for (int c = 0; c <= cnt; c++) {
                        if (cur_sum + c * price > sum / 2) {
                            break;
                        }
                        visited[cur_sum + c * price] = true;
                        if (cur_sum + c * price == sum / 2) {
                            found = true;
                            goto out;
                        }
                    }
                }
            }
        }
out:
        cout << (found ? "1\n" : "0\n");
    }
    return 0;
}
