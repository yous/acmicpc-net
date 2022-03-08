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
    int char_map[256];
    int sz = chars.size();
    for (int i = 0; i < sz; i++) {
        char_map[(unsigned char)chars[i]] = i;
    }
    int pw_sz = password.size();
    vector<int> power(pw_sz);
    int p = 1;
    power[0] = p;
    int ans = 0;
    for (int i = 1; i < pw_sz; i++) {
        p = p * sz % MOD;
        power[i] = p;
        ans = (ans + power[i]) % MOD;
    }
    for (int i = 0; i < pw_sz; i++) {
        ans = (ans + power[pw_sz - i - 1] * char_map[(unsigned char)password[i]]) % MOD;
    }
    ans = (ans + 1) % MOD;
    cout << ans << "\n";
    return 0;
}
