#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, K;
    cin >> N >> M >> K;
    int min_cnt = M + 1;
    int ans = -1;
    for (int i = 0; i < N; i++) {
        int dist = 0;
        for (int j = 0; j < M; j++) {
            int num;
            cin >> num;
            dist += num;
            if (dist >= K && min_cnt > j + 1) {
                min_cnt = j + 1;
                ans = i + 1;
            }
        }
    }
    cout << ans << " " << min_cnt << "\n";
    return 0;
}
