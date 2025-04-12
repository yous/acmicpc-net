#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

short N, K;
string S;

int solve(int idx, int pos, int excluded_len) {
    if (pos >= N) {
        return N - excluded_len;
    }
    if (idx >= K) {
        return N - excluded_len;
    }
    char ch = S[pos];
    if (ch == 'X') {
        return solve(idx, pos + 1, excluded_len);
    }
    int ans = solve(idx, pos + 1, excluded_len);
    for (int i = pos + 1; i < N; i++) {
        if (S[i] == ch) {
            ans = min(ans, solve(idx + 1, i + 1, excluded_len + i - pos + 1));
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    cin >> S;
    cout << solve(0, 0, 0) << "\n";
    return 0;
}
