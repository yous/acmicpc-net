#include <algorithm>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

short N;
vector<pair<short, short>> cows;
queue<short> deadlines[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++) {
        short g, d;
        cin >> g >> d;
        cows.emplace_back(d, -g);
    }
    sort(cows.begin(), cows.end());
    for (auto& p : cows) {
        deadlines[p.first].push(-p.second);
    }
    int sum = 0;
    for (int t = 9999; t >= 0; t--) {
        int _max = 0;
        int max_idx = -1;
        for (int i = t + 1; i <= 10000; i++) {
            if (deadlines[i].empty()) {
                continue;
            }
            short front = deadlines[i].front();
            if (front > _max) {
                _max = front;
                max_idx = i;
            }
        }
        if (max_idx >= 0) {
            deadlines[max_idx].pop();
            sum += _max;
        }
    }
    cout << sum << "\n";
    return 0;
}
