#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = int(1e9) + 7;

int solve(int idx, short S, vector<short>& songs, vector<vector<vector<vector<int>>>>& cache) {
    if (idx >= S) {
        if (songs[0] == 0 && songs[1] == 0 && songs[2] == 0) {
            return 1;
        }
        return 0;
    }
    auto& ans = cache[idx][songs[0]][songs[1]][songs[2]];
    if (ans != -1) {
        return ans;
    }
    ans = 0;
    for (int i = 0; i < 3; i++) {
        if (songs[i] == 0) {
            continue;
        }
        songs[i]--;
        ans = (ans + solve(idx + 1, S, songs, cache)) % MOD;
        songs[i]++;
    }
    for (int i = 0; i < 3; i++) {
        if (songs[i] == 0 || songs[(i + 1) % 3] == 0) {
            continue;
        }
        songs[i]--;
        songs[(i + 1) % 3]--;
        ans = (ans + solve(idx + 1, S, songs, cache)) % MOD;
        songs[i]++;
        songs[(i + 1) % 3]++;
    }
    if (songs[0] > 0 && songs[1] > 0 && songs[2] > 0) {
        songs[0]--;
        songs[1]--;
        songs[2]--;
        ans = (ans + solve(idx + 1, S, songs, cache)) % MOD;
        songs[0]++;
        songs[1]++;
        songs[2]++;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short S;
    cin >> S;
    vector<short> songs(3);
    for (auto& num : songs) {
        cin >> num;
    }
    vector<vector<vector<vector<int>>>> cache(S, vector<vector<vector<int>>>(songs[0] + 1, vector<vector<int>>(songs[1] + 1, vector<int>(songs[2] + 1, -1))));
    cout << solve(0, S, songs, cache) << "\n";
    return 0;
}
