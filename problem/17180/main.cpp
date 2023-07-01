#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

int solve(short idx1, short idx2, short N, short M, string& S1, string& S2, vector<vector<int>>& cache) {
    if (idx1 >= N || idx2 >= M) {
        return INF;
    }
    auto& ans = cache[idx1][idx2];
    if (ans != INF) {
        return ans;
    }
    if (idx1 == N - 1 && idx2 == M - 1) {
        ans = abs(S1[idx1] - S2[idx2]);
        return ans;
    }
    ans = abs(S1[idx1] - S2[idx2]) + solve(idx1 + 1, idx2 + 1, N, M, S1, S2, cache);
    ans = min(ans, abs(S1[idx1] - S2[idx2]) + solve(idx1 + 1, idx2, N, M, S1, S2, cache));
    ans = min(ans, abs(S1[idx1] - S2[idx2]) + solve(idx1, idx2 + 1, N, M, S1, S2, cache));
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N, M;
    cin >> N >> M;
    string S1, S2;
    cin >> S1 >> S2;
    vector<vector<int>> cache(N, vector<int>(M, INF));
    cout << solve(0, 0, N, M, S1, S2, cache) << "\n";
    return 0;
}
