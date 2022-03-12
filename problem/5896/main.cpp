#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    long long M;
    cin >> N >> K >> M;
    vector<pair<int, int>> cows(N);
    for (auto& [p, c] : cows) {
        cin >> p >> c;
    }
    sort(cows.begin(), cows.end(), [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
        if (lhs.second != rhs.second) {
            return lhs.second < rhs.second;
        }
        return lhs.first < rhs.first;
    });
    int cnt = 0;
    int idx = 0;
    priority_queue<pair<int, int>> pq;
    while (idx < N && K > 0) {
        if (M < cows[idx].second) {
            break;
        }
        M -= cows[idx].second;
        if (cows[idx].first > cows[idx].second) {
            K--;
            pq.emplace(-(cows[idx].first - cows[idx].second), idx);
        }
        cnt++;
        idx++;
    }
    while (idx < N) {
        if (!pq.empty()) {
            auto [diff, prev_i] = pq.top();
            if (cows[prev_i].second + cows[idx].first > cows[prev_i].first + cows[idx].second) {
                if (M >= cows[prev_i].first - cows[prev_i].second + cows[idx].second) {
                    M -= cows[prev_i].first - cows[prev_i].second + cows[idx].second;
                    pq.pop();
                    pq.emplace(-(cows[idx].first - cows[idx].second), idx);
                    cnt++;
                    idx++;
                    continue;
                }
            }
        }
        if (M < cows[idx].first) {
            idx++;
            continue;
        }
        M -= cows[idx].first;
        cnt++;
        idx++;
    }
    cout << cnt << "\n";
    return 0;
}
