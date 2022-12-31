#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string S;
    cin >> S;
    auto sz = S.size();
    long long ans = 0;
    int idx = 0;
    while (idx < sz) {
        while (idx < sz && S[idx] != 'A') {
            idx++;
        }
        if (idx == sz) {
            break;
        }
        int a_cnt = 0;
        while (idx < sz && S[idx] == 'A') {
            a_cnt++;
            idx++;
        }
        if (idx == sz) {
            break;
        }
        char cur_ch = 'B';
        while (idx < sz && cur_ch < 'Z') {
            if (S[idx] != cur_ch) {
                break;
            }
            while (idx < sz && S[idx] == cur_ch) {
                idx++;
            }
            if (idx == sz) {
                break;
            }
            cur_ch++;
        }
        if (idx == sz) {
            break;
        }
        if (cur_ch != 'Z' || S[idx] != cur_ch) {
            continue;
        }
        int z_cnt = 0;
        while (idx < sz && S[idx] == 'Z') {
            z_cnt++;
            idx++;
        }
        ans += 1LL * a_cnt * z_cnt;
    }
    cout << ans << "\n";
    return 0;
}
