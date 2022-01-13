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
    vector<priority_queue<short>> events(365);
    for (int i = 0; i < N; i++) {
        int S, E;
        cin >> S >> E;
        events[S - 1].emplace(E - S + 1);
    }
    vector<int> heights(365);
    int day = 0;
    int cnt = 0;
    while (cnt < N) {
        if (events[day].empty()) {
            day++;
            if (day >= 365) {
                day = 0;
            }
            continue;
        }
        short len = events[day].top();
        events[day].pop();
        int h = heights[day] + 1;
        for (int i = 0; i < len; i++) {
            heights[day + i] = h;
        }
        day += len;
        if (day >= 365) {
            day = 0;
        }
        cnt++;
    }
    int st = 0;
    int ed = 0;
    int max_h = 0;
    int ans = 0;
    for (int i = 0; i < 365; i++) {
        int h = heights[i];
        if (h == 0) {
            if (max_h > 0) {
                ans += (ed - st) * max_h;
            }
            st = i + 1;
            ed = st;
            max_h = 0;
            continue;
        }
        if (max_h < h) {
            max_h = h;
        }
        ed++;
    }
    if (max_h > 0) {
        ans += (ed - st) * max_h;
    }
    cout << ans << "\n";
    return 0;
}
