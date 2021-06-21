#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> meetings;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int st, ed;
        cin >> st >> ed;
        meetings.emplace_back(ed, st);
    }
    sort(meetings.begin(), meetings.end());
    int cur_end = 0;
    int cnt = 0;
    for (auto& p : meetings) {
        int ed = p.first,
            st = p.second;
        if (st >= cur_end) {
            cnt++;
            cur_end = ed;
        }
    }
    cout << cnt << "\n";
    return 0;
}
