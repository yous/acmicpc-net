#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> T;
vector<int> P;
int dp[15];

int solve(int n) {
    if (n >= N) {
        return 0;
    }
    if (dp[n] != 0) {
        return dp[n];
    }
    int ans;
    if (n + T[n] - 1 >= N) {
        ans = solve(n + 1);
    } else {
        ans = max(P[n] + solve(n + T[n]), solve(n + 1));
    }
    dp[n] = ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    int i;
    int t, p;
    for (i = 0; i < N; i++) {
        cin >> t >> p;
        T.push_back(t);
        P.push_back(p);
    }
    cout << solve(0) << "\n";
    return 0;
}
