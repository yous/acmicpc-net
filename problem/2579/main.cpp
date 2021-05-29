#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> stairs;
int dp[300][2];

int solve(int index, int streak) {
    if (index >= N) {
        return 0;
    }
    if (dp[index][streak] != 0) {
        return dp[index][streak];
    }
    int ans = 0;
    if (streak == 0) {
        if (index >= 2) {
            ans = stairs[index] + max(solve(index - 2, 0), solve(index - 2, 1));
        } else {
            ans = stairs[index];
        }
    } else {
        ans = stairs[index] + solve(index - 1, streak - 1);
    }
    dp[index][streak] = ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    int i;
    int stair;
    for (i = 0; i < N; i++) {
        cin >> stair;
        stairs.push_back(stair);
    }
    cout << max(solve(N - 1, 0), solve(N - 1, 1)) << "\n";
    return 0;
}
