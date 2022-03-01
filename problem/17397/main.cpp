#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

short N, M;
vector<short> C;
int cache[1000][200][11];

int solve(short idx, short rem, short cur) {
    if (idx >= N) {
        return 0;
    }
    int& ans = cache[idx][rem][cur];
    if (ans >= 0) {
        return ans;
    }
    ans = (cur > C[idx] ? (cur - C[idx]) * (cur - C[idx]) : 0) + solve(idx + 1, rem, C[idx]);
    for (int i = 1; i <= rem; i++) {
        int nxt = C[idx] + i;
        if (nxt > cur) {
            break;
        }
        ans = min(ans, (cur - nxt) * (cur - nxt) + solve(idx + 1, rem - i, nxt));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    C.resize(N);
    for (short& num : C) {
        cin >> num;
    }
    fill(&cache[0][0][0], &cache[1000][0][0], -1);
    cout << solve(0, M, 0) << "\n";
    return 0;
}
