#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<short> S(N);
    for (auto& num : S) {
        cin >> num;
    }
    int l_idx = 0;
    int r_idx = 0;
    vector<int> cnt(10);
    int types = 0;
    int ans = 0;
    while (r_idx < N) {
        cnt[S[r_idx]]++;
        if (cnt[S[r_idx]] == 1) {
            types++;
        }
        while (types > 2) {
            cnt[S[l_idx]]--;
            if (cnt[S[l_idx]] == 0) {
                types--;
            }
            l_idx++;
        }
        ans = max(ans, r_idx - l_idx + 1);
        r_idx++;
    }
    cout << ans << "\n";
    return 0;
}
