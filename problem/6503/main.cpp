#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int M;
    while (true) {
        cin >> M;
        if (M == 0) {
            break;
        }
        string S;
        cin >> ws;
        getline(cin, S);
        int sz = S.size();
        vector<bool> used(128, false);
        vector<int> last_occur(128);
        int use_cnt = 0;
        int len = 0;
        int ans = 0;
        for (int i = 0; i < sz; i++) {
            if (used[S[i]]) {
                last_occur[S[i]] = i;
                len++;
                continue;
            }
            if (use_cnt < M) {
                used[S[i]] = true;
                last_occur[S[i]] = i;
                use_cnt++;
                len++;
                continue;
            }
            ans = max(ans, len);
            int far = 0;
            int min_val = i;
            for (int j = 0; j < 128; j++) {
                if (used[j] && last_occur[j] >= i - len) {
                    if (min_val > last_occur[j]) {
                        min_val = last_occur[j];
                        far = j;
                    }
                }
            }
            used[far] = false;
            used[S[i]] = true;
            last_occur[S[i]] = i;
            int prev_len = len;
            len = i - last_occur[far];
            for (int j = i - prev_len + 1; j <= i - len; j++) {
                if (last_occur[S[j]] <= i - len && used[S[j]]) {
                    used[S[j]] = false;
                    use_cnt--;
                }
            }
        }
        ans = max(ans, len);
        cout << ans << "\n";
    }
    return 0;
}
