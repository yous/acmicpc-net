#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

string S;
int S_sz;

int make_pi(int prefix) {
    int pos = 1;
    int matched = 0;
    int ans = 0;
    int len = S_sz - prefix;
    vector<int> pi(len);
    while (pos + matched < len) {
        if (S[prefix + pos + matched] == S[prefix + matched]) {
            matched++;
            ans = max(ans, matched);
            pi[pos + matched - 1] = matched;
        } else if (matched == 0) {
            pos++;
        } else {
            pos += matched - pi[matched - 1];
            matched = pi[matched - 1];
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> S;
    S_sz = S.size();
    int ans = 0;
    int prefix = 0;
    while (prefix < S_sz) {
        ans = max(ans, make_pi(prefix));
        prefix++;
    }
    cout << ans << "\n";
    return 0;
}
