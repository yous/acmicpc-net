#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    short D, K, C;
    cin >> N >> D >> K >> C;
    C--;
    vector<short> sushi(N);
    for (short& num : sushi) {
        cin >> num;
        num--;
    }
    vector<int> cnt(D);
    int cur_cnt = 0;
    int ans = 0;
    for (int i = 0; i < K - 1; i++) {
        if (cnt[sushi[i]] == 0) {
            cur_cnt++;
        }
        cnt[sushi[i]]++;
    }
    for (int i = K - 1; i < N; i++) {
        if (cnt[sushi[i]] == 0) {
            cur_cnt++;
        }
        cnt[sushi[i]]++;
        ans = max(ans, cur_cnt + (cnt[C] == 0 ? 1 : 0));
        cnt[sushi[i - K + 1]]--;
        if (cnt[sushi[i - K + 1]] == 0) {
            cur_cnt--;
        }
    }
    for (int i = 0; i < K - 1; i++) {
        if (cnt[sushi[i]] == 0) {
            cur_cnt++;
        }
        cnt[sushi[i]]++;
        ans = max(ans, cur_cnt + (cnt[C] == 0 ? 1 : 0));
        cnt[sushi[i + N - K + 1]]--;
        if (cnt[sushi[i + N - K + 1]] == 0) {
            cur_cnt--;
        }
    }
    cout << ans << "\n";
    return 0;
}
