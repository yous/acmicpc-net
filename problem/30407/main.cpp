#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

short N;
short H, D, K;

int solve(int idx, short health, short dist, int surprise, vector<short>& damages) {
    int ans = -1;
    if (health < 0) {
        return -1;
    }
    if (idx >= N) {
        return health;
    }
    if (idx == surprise) {
        ans = solve(idx + 1, dist >= damages[idx] ? health : health - (damages[idx] - dist), dist, surprise, damages);
        return ans;
    }
    ans = max(ans, solve(idx + 1, dist >= damages[idx] ? health : health - (damages[idx] - dist) / 2, dist, surprise, damages));
    ans = max(ans, solve(idx + 1, dist + K >= damages[idx] ? health : health - (damages[idx] - dist - K), dist + K, surprise, damages));
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    cin >> H >> D >> K;
    vector<short> damages(N);
    for (auto& num : damages) {
        cin >> num;
    }
    int ans = -1;
    for (int i = 0; i < N; i++) {
        if (i == N - 1) {
            ans = max(ans, solve(0, H, D, -1, damages));
        } else {
            short prev_damage = damages[i + 1];
            damages[i + 1] = 0;
            ans = max(ans, solve(0, H, D, i, damages));
            damages[i + 1] = prev_damage;
        }
    }
    cout << ans << "\n";
    return 0;
}
