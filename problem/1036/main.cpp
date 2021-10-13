#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
int digit[52][36];
int K;
vector<int> max_digits(36);
vector<bool> sel(36);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        int sz = s.size();
        for (int i = sz - 1; i >= 0; i--) {
            int num = (s[i] <= '9' ? s[i] - '0' : s[i] - 'A' + 10);
            digit[52 - sz + i][num]++;
            int cur_i = i;
            while (digit[52 - sz + cur_i][num] == 36) {
                digit[52 - sz + cur_i][num] = 0;
                digit[52 - sz + cur_i - 1][num]++;
                cur_i--;
            }
        }
    }
    cin >> K;
    for (int i = 0; i < 36; i++) {
        max_digits[i] = i;
    }
    sort(max_digits.begin(), max_digits.end(), [&](const int lhs, const int rhs) {
        long long l = 0;
        long long r = 0;
        for (int i = 0; i < 52; i++) {
            l += digit[i][lhs] * (35 - lhs);
            r += digit[i][rhs] * (35 - rhs);
            if (l == r) {
                l = 0;
                r = 0;
                continue;
            }
            if (l > r) {
                if ((l - r) * 36 >= 1LL * 36 * (35 - rhs)) {
                    return true;
                }
                l -= r;
                r = 0;
            } else {
                if ((r - l) * 36 >= 1LL * 36 * (35 - lhs)) {
                    return false;
                }
                r -= l;
                l = 0;
            }
            l *= 36;
            r *= 36;
        }
        return l > r;
    });
    for (int i = 0; i < K; i++) {
        sel[max_digits[i]] = true;
    }
    char ans[52];
    int add = 0;
    for (int i = 51; i >= 0; i--) {
        int sum = add;
        for (int j = 0; j < 36; j++) {
            if (sel[j]) {
                sum += digit[i][j] * 35;
            } else {
                sum += digit[i][j] * j;
            }
        }
        add = sum / 36;
        sum %= 36;
        ans[i] = (sum <= 9 ? sum + '0' : sum - 10 + 'A');
    }
    int start = 0;
    while (start < 51 && ans[start] == '0') {
        start++;
    }
    while (start <= 51) {
        cout << ans[start++];
    }
    cout << "\n";
    return 0;
}
