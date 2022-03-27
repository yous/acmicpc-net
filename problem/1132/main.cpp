#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long long solve(int num, vector<vector<short>>& cnt, vector<short>& digit, vector<bool>& used) {
    if (num == 10) {
        long long res = 0;
        for (int i = 0; i < 12; i++) {
            res = res * 10;
            for (int j = 0; j < 10; j++) {
                res += cnt[i][j] * digit[j];
            }
        }
        return res;
    }
    long long res = 0;
    for (int i = 0; i <= 9; i++) {
        if (used[i]) {
            continue;
        }
        digit[i] = num;
        used[i] = true;
        res = max(res, solve(num + 1, cnt, digit, used));
        used[i] = false;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N;
    cin >> N;
    vector<vector<short>> cnt(12, vector<short>(10));
    vector<bool> not_zero(10);
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        not_zero[s[0] - 'A'] = true;
        int sz = s.size();
        for (int j = 0; j < sz; j++) {
            cnt[12 - sz + j][s[j] - 'A']++;
        }
    }
    vector<bool> used(10);
    vector<short> digit(10);
    long long ans = 0;
    for (int i = 0; i <= 9; i++) {
        if (not_zero[i]) {
            continue;
        }
        digit[i] = 0;
        used[i] = true;
        ans = max(ans, solve(1, cnt, digit, used));
        used[i] = false;
    }
    cout << ans << "\n";
    return 0;
}
