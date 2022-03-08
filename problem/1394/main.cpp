#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 900528;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string chars;
    cin >> chars;
    string password;
    cin >> password;
    int sz = chars.size();
    int pw_sz = password.size();
    vector<int> power(pw_sz);
    int p = 1;
    for (int i = 0; i < pw_sz; i++) {
        power[i] = p;
        p = p * sz % MOD;
    }
    int ans = 0;
    for (int i = 0; i < pw_sz - 1; i++) {
        ans = (ans + power[i + 1]) % MOD;
    }
    for (int i = 0; i < pw_sz; i++) {
        for (int j = 0; j < sz; j++) {
            if (password[i] == chars[j]) {
                break;
            }
            ans = (ans + power[pw_sz - i - 1]) % MOD;
        }
    }
    ans = (ans + 1) % MOD;
    cout << ans << "\n";
    return 0;
}
