#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M, Q;
vector<int> inv_P[32];

int solve(int loc) {
    int start = min(loc, N - M);
    int ans = loc - start;
    while (start >= 0) {
        for (int idx = 31; idx >= 0; idx--) {
            if (start & (1 << idx)) {
                int n = inv_P[idx][ans];
                if (n == M) {
                    continue;
                }
                ans = n;
                start -= (1 << idx);
            }
        }
        ans = inv_P[0][ans];
        if (ans == M || start == 0) {
            break;
        }
        start--;
    }
    return start + ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> Q;
    inv_P[0].resize(M);
    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        inv_P[0][num - 1] = i + 1;
    }
    for (int p = 1; p < 32; p++) {
        for (int i = 0; i < M; i++) {
            int n = inv_P[p - 1][i];
            if (n == M) {
                inv_P[p].push_back(n);
            } else {
                inv_P[p].push_back(inv_P[p - 1][n]);
            }
        }
    }
    for (int i = 0; i < Q; i++) {
        int num;
        cin >> num;
        cout << solve(N - num) << "\n";
    }
    return 0;
}
