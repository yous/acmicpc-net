#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> ADJ;
vector<bool> visited;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    ADJ.resize(N);
    visited.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> ADJ[i];
    }
    int ans = 0;
    int u = 0;
    while (!visited[u] && u != K) {
        visited[u] = true;
        u = ADJ[u];
        ans++;
    }
    if (u != K) {
        cout << "-1\n";
    } else {
        cout << ans << "\n";
    }
    return 0;
}
