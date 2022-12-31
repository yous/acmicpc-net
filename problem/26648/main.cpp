#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<vector<int>> scores(N, vector<int>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < N; j++) {
            cin >> scores[j][i];
        }
    }
    vector<pair<int, int>> minmax(N);
    for (int i = 0; i < N; i++) {
        sort(scores[i].begin(), scores[i].end());
        minmax[i] = {scores[i][0], scores[i][2]};
    }
    int cur_score = minmax[0].first;
    for (int i = 1; i < N; i++) {
        if (cur_score >= minmax[i].second) {
            cout << "NO\n";
            return 0;
        }
        cur_score = max(cur_score + 1, minmax[i].first);
    }
    cout << "YES\n";
    return 0;
}
