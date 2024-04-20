#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short T;
    cin >> T;
    while (T-- > 0) {
        int N;
        cin >> N;
        if (N == 1) {
            cout << "1\n";
            continue;
        }
        vector<pair<char, int>> visited(N, {0, -2});
        queue<int> qu;
        visited[1] = {'1', -1};
        qu.emplace(1);
        bool found = false;
        while (!qu.empty()) {
            auto rem = qu.front();
            qu.pop();
            for (int i = 0; i < 2; i++) {
                int new_rem = (rem * 10 + i) % N;
                if (new_rem == 0) {
                    found = true;
                    vector<char> ans;
                    ans.emplace_back('0' + i);
                    auto prev_idx = rem;
                    while (visited[prev_idx].second >= 0) {
                        ans.emplace_back(visited[prev_idx].first);
                        prev_idx = visited[prev_idx].second;
                    }
                    ans.emplace_back(visited[prev_idx].first);
                    reverse(ans.begin(), ans.end());
                    cout << string(ans.begin(), ans.end()) << "\n";
                    break;
                }
                if (visited[new_rem].second != -2) {
                    continue;
                }
                visited[new_rem] = {'0' + i, rem};
                qu.emplace(new_rem);
            }
            if (found) {
                break;
            }
        }
        if (!found) {
            cout << "BRAK\n";
        }
    }
    return 0;
}
