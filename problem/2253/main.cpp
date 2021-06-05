#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int INF = 987654321;
int N, M;
set<int> smalls;
int dp[10001][150];

int solve(int stone, int velo) {
    if (stone > N) {
        return INF;
    }
    if (stone == N) {
        return 0;
    }
    int& ans = dp[stone][velo];
    if (ans) {
        return ans;
    }
    int _min = INF;
    for (int dv = -1; dv <= 1; dv++) {
        int new_velo = velo + dv;
        if (new_velo >= 1) {
            int new_stone = stone + new_velo;
            if (smalls.find(new_stone) == smalls.end()) {
                _min = min(_min, 1 + solve(stone + new_velo, new_velo));
            }
        }
    }
    ans = _min;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        smalls.insert(num);
    }
    int _min = solve(2, 1);
    if (_min == INF) {
        cout << "-1\n";
    } else {
        cout << 1 + _min << "\n";
    }
    return 0;
}
