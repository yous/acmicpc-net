#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int A, K;
    cin >> A >> K;
    queue<int> qu;
    vector<bool> visited(K);
    qu.emplace(A);
    visited[A - 1] = true;
    int step = 0;
    while (!qu.empty()) {
        auto sz = qu.size();
        while (sz-- > 0) {
            int num = qu.front();
            qu.pop();
            if (num == K) {
                cout << step << "\n";
                return 0;
            }
            if (num + 1 <= K && !visited[num]) {
                qu.emplace(num + 1);
                visited[num] = true;
            }
            if (num * 2 <= K && !visited[num * 2 - 1]) {
                qu.emplace(num * 2);
                visited[num * 2 - 1] = true;
            }
        }
        step++;
    }
    return 0;
}
