#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> stones;
int S;
vector<bool> visited;

int dfs(int u) {
    int cnt = 0;
    if (!visited[u]) {
        visited[u] = true;
        cnt++;
        if (u - stones[u] >= 0) {
            cnt += dfs(u - stones[u]);
        }
        if (u + stones[u] < N) {
            cnt += dfs(u + stones[u]);
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    stones.resize(N);
    visited.resize(N);
    for (int& num : stones) {
        cin >> num;
    }
    cin >> S;
    cout << dfs(S - 1) << "\n";
    return 0;
}
