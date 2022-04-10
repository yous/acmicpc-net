#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<tuple<int, int, int>> lectures(N);
    for (auto& [st, ed, idx] : lectures) {
        cin >> idx >> st >> ed;
    }
    sort(lectures.begin(), lectures.end());
    priority_queue<pair<int, int>> pq;
    int rooms = 0;
    vector<int> ans(N);
    for (auto [st, ed, idx] : lectures) {
        if (pq.empty()) {
            rooms++;
            pq.emplace(-ed, rooms);
            ans[idx - 1] = rooms;
        } else {
            auto [next_ed, room] = pq.top();
            next_ed = -next_ed;
            if (st >= next_ed) {
                pq.pop();
                pq.emplace(-ed, room);
                ans[idx - 1] = room;
            } else {
                rooms++;
                pq.emplace(-ed, rooms);
                ans[idx - 1] = rooms;
            }
        }
    }
    cout << rooms << "\n";
    for (int i = 0; i < N; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}
