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
    int p = 1;
    int ans = 0;
    for (int i = 1; i < pw_sz; i++) {
        p = p * sz % MOD;
        ans = (ans + p) % MOD;
    }
    int num = 0;
    for (char ch : password) {
        num = (num * sz + char_map[(unsigned char)ch]) % MOD;
    }
    ans = (ans + num + 1) % MOD;
    cout << ans << "\n";
    return 0;
}
