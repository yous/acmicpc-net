#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string S;
    cin >> S;
    int len = S.size();
    int r_cnt = 0;
    for (int i = 0; i < len; i++) {
        if (S[i] == 'R') {
            r_cnt++;
        }
    }
    if (r_cnt == 0) {
        cout << "0\n";
        return 0;
    }
    int ans = r_cnt;
    int lo = 0;
    int hi = len - 1;
    int k_cnt = 0;
    while (lo < hi) {
        while (S[lo] == 'R') {
            r_cnt--;
            lo++;
        }
        while (S[hi] == 'R') {
            r_cnt--;
            hi--;
        }
        if (lo >= hi) {
            break;
        }
        k_cnt += 2;
        if (r_cnt <= 0) {
            break;
        }
        ans = max(ans, k_cnt + r_cnt);
        lo++;
        hi--;
    }
    cout << ans << "\n";
    return 0;
}
