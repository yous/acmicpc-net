#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, K;
    cin >> N >> M >> K;
    vector<pair<int, int>> rain(M);
    int total = 0;
    int ans = -1;
    for (int i = 0; i < M; i++) {
        int T, R;
        cin >> T >> R;
        total += R;
        if (ans < 0 && total > K) {
            ans = i + 1;
        }
    }
    if (ans < 0) {
        cout << "-1\n";
    } else {
        cout << ans << " 1\n";
    }
    return 0;
}
