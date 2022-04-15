#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string S, P;
    cin >> S >> P;
    int S_sz = S.size();
    int P_sz = P.size();
    int idx = 0;
    int ans = 0;
    while (idx < P_sz) {
        int max_len = 0;
        for (int i = 0; i < S_sz - max_len; i++) {
            int len = 0;
            while (i + len < S_sz && idx + len < P_sz && S[i + len] == P[idx + len]) {
                len++;
            }
            max_len = max(max_len, len);
        }
        idx += max_len;
        ans++;
    }
    cout << ans << "\n";
    return 0;
}
