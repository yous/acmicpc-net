#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N;
    cin >> N;
    vector<pair<int, short>> stations(N);
    for (auto& [a, b] : stations) {
        cin >> a >> b;
    }
    sort(stations.begin(), stations.end());
    int L, P;
    cin >> L >> P;
    priority_queue<short> pq;
    int idx = 0;
    int fuel = P;
    short ans = 0;
    while (idx < N) {
        if (fuel >= L) {
            break;
        }
        while (idx < N) {
            auto [a, b] = stations[idx];
            if (a <= fuel) {
                pq.emplace(b);
            } else {
                break;
            }
            idx++;
        }
        if (pq.empty()) {
            break;
        }
        fuel += pq.top();
        pq.pop();
        ans++;
    }
    if (fuel >= L) {
        cout << ans << "\n";
    } else {
        cout << "-1\n";
    }
    return 0;
}
