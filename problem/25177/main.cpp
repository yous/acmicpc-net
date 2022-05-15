#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N, M;
    cin >> N >> M;
    vector<short> cur_scores(max(N, M));
    int cur_sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> cur_scores[i];
        cur_sum += cur_scores[i];
    }
    int ans = 0;
    int prev_sum = 0;
    for (int i = 0; i < M; i++) {
        short num;
        cin >> num;
        prev_sum += num;
        if (ans < num - cur_scores[i]) {
            ans = num - cur_scores[i];
        }
    }
    cout << ans << "\n";
    return 0;
}
