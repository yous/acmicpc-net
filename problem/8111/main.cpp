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
        short N;
        cin >> N;
        if (N == 1) {
            cout << "1\n";
            continue;
        }
        vector<bool> visited(N);
        queue<pair<string, int>> qu;
        visited[1] = true;
        qu.emplace("1", 1);
        bool found = false;
        while (!qu.empty()) {
            auto [str, rem] = qu.front();
            qu.pop();
            for (int i = 0; i < 2; i++) {
                int new_rem = (rem * 10 + i) % N;
                if (new_rem == 0) {
                    found = true;
                    cout << str + to_string(i) << "\n";
                    break;
                }
                if (visited[new_rem]) {
                    continue;
                }
                visited[new_rem] = true;
                qu.emplace(str + to_string(i), new_rem);
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
