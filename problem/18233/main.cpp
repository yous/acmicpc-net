#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, P, E;
vector<pair<int, int>> ducks;

bool solve(int idx, int remain, vector<bool>& selected, int cur_min, int cur_max) {
    if (remain == 0) {
        if (E < cur_min || E > cur_max) {
            return false;
        }
        int rem = E - cur_min;
        if (selected[0]) {
            int duck = min(ducks[0].first + rem, ducks[0].second);
            cout << duck;
            rem -= duck - ducks[0].first;
        } else {
            cout << "0";
        }
        for (int i = 1; i < N; i++) {
            if (selected[i]) {
                int duck = min(ducks[i].first + rem, ducks[i].second);
                cout << " " << duck;
                rem -= duck - ducks[i].first;
            } else {
                cout << " 0";
            }
        }
        cout << "\n";
        return true;
    }
    if (idx >= N) {
        return false;
    }
    selected[idx] = true;
    if (solve(idx + 1, remain - 1, selected, cur_min + ducks[idx].first, cur_max + ducks[idx].second)) {
        return true;
    }
    selected[idx] = false;
    if (solve(idx + 1, remain, selected, cur_min, cur_max)) {
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> P >> E;
    ducks.resize(N);
    for (auto& [x, y] : ducks) {
        cin >> x >> y;
    }
    vector<bool> selected(N);
    if (!solve(0, P, selected, 0, 0)) {
        cout << "-1\n";
    }
    return 0;
}
