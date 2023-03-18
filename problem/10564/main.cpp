#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const short INF = 30000;

short solve(short N, short cur_score, vector<short>& scores, vector<vector<short>>& cache) {
    if (N == 0) {
        return cur_score;
    }
    auto& ans = cache[N][cur_score];
    if (ans != -1) {
        return ans;
    }
    ans = -INF;
    for (auto score : scores) {
        if (N >= cur_score + score) {
            short ret = solve(N - cur_score - score, cur_score + score, scores, cache);
            if (ret < 0) {
                continue;
            }
            ans = max(ans, ret);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short T;
    cin >> T;
    while (T-- > 0) {
        short N, M;
        cin >> N >> M;
        vector<short> scores(M);
        for (auto& num : scores) {
            cin >> num;
        }
        sort(scores.begin(), scores.end());
        vector<vector<short>> cache(N + 1, vector<short>(441, -1));
        short ans = solve(N, 0, scores, cache);
        if (ans < 0) {
            cout << "-1\n";
        } else {
            cout << ans << "\n";
        }
    }
    return 0;
}
