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
        for (auto& [price, cnt] : coins) {
            cin >> price >> cnt;
        }
        vector<bool> visited(100001);
        vector<bool> next_visited(100001);
        auto [price, cnt] = coins[0];
        for (int c = cnt % 2; c <= cnt; c += 2) {
            visited[c * price] = true;
        }
        for (int i = 1; i < N; i++) {
            auto [price, cnt] = coins[i];
            for (int sum = 0; sum <= 100000; sum++) {
                if (visited[sum]) {
                    for (int c = cnt % 2; c <= cnt; c += 2) {
                        if (sum + c * price <= 100000) {
                            next_visited[sum + c * price] = true;
                        }
                        next_visited[abs(sum - c * price)] = true;
                    }
                }
            }
            fill(visited.begin(), visited.end(), false);
            swap(visited, next_visited);
        }
        cout << (visited[0] ? "1\n" : "0\n");
    }
    return 0;
}
