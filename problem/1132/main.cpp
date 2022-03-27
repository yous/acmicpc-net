#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N;
    cin >> N;
    vector<vector<short>> cnt(10, vector<short>(12));
    vector<bool> not_zero(10);
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        not_zero[s[0] - 'A'] = true;
        int sz = s.size();
        for (int j = 0; j < sz; j++) {
            cnt[s[j] - 'A'][12 - sz + j]++;
        }
    }
    vector<pair<long long, int>> alpha(10);
    for (int i = 0; i <= 9; i++) {
        auto& p = alpha[i];
        p = {0, i};
        for (int j = 0; j < 12; j++) {
            p.first = p.first * 10 + cnt[i][j];
        }
    }
    sort(alpha.begin(), alpha.end());
    int zero_idx = 0;
    while (not_zero[alpha[zero_idx].second]) {
        zero_idx++;
    }
    long long ans = 0;
    int digit = 1;
    for (int i = 0; i <= 9; i++) {
        if (i == zero_idx) {
            continue;
        }
        ans += alpha[i].first * digit;
        digit++;
    }
    cout << ans << "\n";
    return 0;
}
