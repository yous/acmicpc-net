#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e5;
short N;
int A, B, C;
int ans = 0;

void solve(int idx, int score, int choco) {
    if (idx >= N * 2) {
        ans = max(ans, score);
        return;
    }
    score = (score + B) % MOD;
    int dark_idx = idx + 1;
    while (dark_idx < N * 2) {
        if (choco & (1 << dark_idx)) {
            break;
        }
        choco |= 1 << dark_idx;
        int new_score = score;
        int new_idx = idx + 1;
        while (choco & (1 << new_idx)) {
            new_score = 1LL * new_score * C % MOD;
            new_idx++;
        }
        solve(new_idx, new_score, choco);
        choco &= ~(1 << dark_idx);
        dark_idx += 2;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    cin >> A >> B >> C;
    solve(0, A, 0);
    cout << ans << "\n";
    return 0;
}
