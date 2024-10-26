#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void insert_queue(vector<short>& hps, queue<tuple<short, short, short>>& qu, vector<vector<vector<bool>>>& visited) {
    sort(hps.begin(), hps.end(), greater<short>());
    if (!visited[hps[0]][hps[1]][hps[2]]) {
        visited[hps[0]][hps[1]][hps[2]] = true;
        qu.emplace(hps[0], hps[1], hps[2]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N;
    cin >> N;
    vector<short> mutal(3);
    for (int i = 0; i < N; i++) {
        cin >> mutal[i];
    }
    sort(mutal.begin(), mutal.end(), greater<short>());
    vector<vector<vector<bool>>> visited(61, vector<vector<bool>>(61, vector<bool>(61)));
    queue<tuple<short, short, short>> qu;
    visited[mutal[0]][mutal[1]][mutal[2]] = true;
    qu.emplace(mutal[0], mutal[1], mutal[2]);
    int step = 0;
    while (!qu.empty()) {
        auto sz = qu.size();
        while (sz-- > 0) {
            auto& [hp1, hp2, hp3] = qu.front();
            qu.pop();
            if (hp1 == 0 && hp2 == 0 && hp3 == 0) {
                cout << step << "\n";
                return 0;
            }
            vector<short> hps(3);
            hps[0] = max(hp1 - 9, 0);
            hps[1] = max(hp2 - 3, 0);
            hps[2] = max(hp3 - 1, 0);
            insert_queue(hps, qu, visited);
            hps[0] = max(hp1 - 9, 0);
            hps[1] = max(hp3 - 3, 0);
            hps[2] = max(hp2 - 1, 0);
            insert_queue(hps, qu, visited);
            if (hp1 > 0) {
                hps[0] = max(hp2 - 9, 0);
                hps[1] = max(hp1 - 3, 0);
                hps[2] = max(hp3 - 1, 0);
                insert_queue(hps, qu, visited);
                hps[0] = max(hp2 - 9, 0);
                hps[1] = max(hp3 - 3, 0);
                hps[2] = max(hp1 - 1, 0);
                insert_queue(hps, qu, visited);
                if (hp2 > 0) {
                    hps[0] = max(hp3 - 9, 0);
                    hps[1] = max(hp1 - 3, 0);
                    hps[2] = max(hp2 - 1, 0);
                    insert_queue(hps, qu, visited);
                    hps[0] = max(hp3 - 9, 0);
                    hps[1] = max(hp2 - 3, 0);
                    hps[2] = max(hp1 - 1, 0);
                    insert_queue(hps, qu, visited);
                }
            }
        }
        step++;
    }
    return 0;
}
