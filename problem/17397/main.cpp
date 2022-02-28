#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;
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
    ans = INF;
    for (int i = 0; i <= rem; i++) {
        int nxt = C[idx] + i;
        if (nxt > 10) {
            break;
        }
        ans = min(ans, (cur > nxt ? (cur - nxt) * (cur - nxt) : 0) + solve(idx + 1, rem - i, nxt));
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
