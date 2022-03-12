#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;

int solve(vector<bool> cur, vector<bool>& target) {
    int cnt = 0;
    int idx = 1;
    while (idx < N - 1) {
        if (cur[idx - 1] != target[idx - 1]) {
            cur[idx - 1] = !cur[idx - 1];
            cur[idx] = !cur[idx];
            cur[idx + 1] = !cur[idx + 1];
            cnt++;
        }
        idx++;
    }
    if (cur[idx - 1] != target[idx - 1]) {
        cur[idx - 1] = !cur[idx - 1];
        cur[idx] = !cur[idx];
        cnt++;
    }
    if (cur[idx] == target[idx]) {
        return cnt;
    } else {
        return N + 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    vector<bool> bulbs(N);
    for (int i = 0; i < N; i++) {
        char ch;
        cin >> ch;
        bulbs[i] = ch == '1';
    }
    vector<bool> target(N);
    for (int i = 0; i < N; i++) {
        char ch;
        cin >> ch;
        target[i] = ch == '1';
    }
    int ans = N + 1;
    ans = min(ans, solve(bulbs, target));
    bulbs[0] = !bulbs[0];
    bulbs[1] = !bulbs[1];
    ans = min(ans, 1 + solve(bulbs, target));
    if (ans == N + 1) {
        cout << "-1\n";
    } else {
        cout << ans << "\n";
    }
    return 0;
}
