#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

short K, M;

bool solve(int idx, vector<short>& d_i, vector<vector<int>>& players) {
    if (idx == 3) {
        d_i[3] = -(d_i[0] + d_i[1] + d_i[2]);
        if (d_i[3] < -100 || d_i[3] > d_i[2]) {
            return false;
        }
        vector<pair<int, short>> scores(4);
        for (int i = 0; i < 4; i++) {
            scores[i].second = i;
            scores[i].first = -players[i][4];
            for (int j = 0; j < 4; j++) {
                scores[i].first -= players[i][j] * d_i[j];
            }
        }
        sort(scores.begin(), scores.end());
        if (scores[M].second == K) {
            cout << d_i[0];
            for (int i = 1; i < 4; i++) {
                cout << " " << d_i[i];
            }
            cout << "\n";
            return true;
        }
        return false;
    }
    for (int i = (idx == 0 ? 100 : d_i[idx - 1]); i >= (idx == 0 ? 0 : -100); i--) {
        d_i[idx] = i;
        if (solve(idx + 1, d_i, players)) {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N >> K >> M;
    K--;
    M--;
    vector<vector<int>> players(4, vector<int>(5));
    for (int i = 0; i < N; i++) {
        vector<short> a_i(4);
        for (auto& num : a_i) {
            cin >> num;
            num--;
        }
        vector<short> s_i(4);
        for (auto& num : s_i) {
            cin >> num;
        }
        for (int j = 0; j < 4; j++) {
            players[a_i[j]][j]++;
            players[a_i[j]][4] += s_i[j];
        }
    }
    vector<short> d_i(4);
    if (!solve(0, d_i, players)) {
        cout << "-1\n";
    }
    return 0;
}
