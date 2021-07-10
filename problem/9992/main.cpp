#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

const int MOD = 2014;
string S;
map<string, int> cache;

int solve(string S) {
    auto sz = S.size();
    if (sz == 2) {
        return 0;
    }
    auto it = cache.find(S);
    if (it != cache.end()) {
        return it->second;
    }
    int ans = 0;
    for (int i = 1; i < (static_cast<int>(sz) + 1) / 2; i++) {
        string tok = S.substr(0, i);
        string remain = S.substr(i, sz - i);
        int way = (remain.rfind(tok, 0) == 0) + (remain.find(tok, sz - i * 2) == sz - i * 2);
        if (way > 0) {
            ans += way * (1 + solve(remain));
            ans %= MOD;
        }
        tok = S.substr(sz - i, i);
        remain = S.substr(0, sz - i);
        way = (remain.rfind(tok, 0) == 0) + (remain.find(tok, sz - i * 2) == sz - i * 2);
        if (way > 0) {
            ans += way * (1 + solve(remain));
            ans %= MOD;
        }
    }
    cache[S] = ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> S;
    cout << solve(S) << "\n";
    return 0;
}
