#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> stairs;
int dp[300][2];

int solve(int index, int streak) {
    if (index >= N || streak >= 2) {
        return -987654321;
    }
    if (index == N - 1) {
        return stairs[N - 1];
    }
    if (streak >= 0 && dp[index][streak] != 0) {
        return dp[index][streak];
    }
    int ans = max(stairs[index] + solve(index + 2, 0),
                  stairs[index] + solve(index + 1, streak + 1));
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
    cout << max(solve(0, 0), solve(1, 0)) << "\n";
    return 0;
}
