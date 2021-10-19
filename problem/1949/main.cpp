#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<short> people;
vector<vector<short>> ADJ;
int cache[10000][2];

int solve(int u, int s, bool include) {
    int& ans = cache[u][include];
    if (ans > 0) {
        return ans - 1;
    }
    ans = 1;
    if (include) {
        ans += people[u];
    }
    for (int v : ADJ[u]) {
        if (v == s) {
            continue;
        }
        if (include) {
            ans += solve(v, u, !include);
        } else {
            ans += max(solve(v, u, true), solve(v, u, false));
        }
    }
    return ans - 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    people.resize(N);
    ADJ.resize(N);
    for (short& num : people) {
        cin >> num;
    }
    for (int i = 0; i < N - 1; i++) {
        short a, b;
        cin >> a >> b;
        ADJ[a - 1].emplace_back(b - 1);
        ADJ[b - 1].emplace_back(a - 1);
    }
    int ans = solve(0, -1, true);
    ans = max(ans, solve(0, -1, false));
    cout << ans << "\n";
    return 0;
}
