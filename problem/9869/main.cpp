#include <algorithm>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

short N;
vector<pair<short, short>> cows;
priority_queue<short> deadlines;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++) {
        short g, d;
        cin >> g >> d;
        cows.emplace_back(d, g);
    }
    sort(cows.begin(), cows.end());
    int sum = 0;
    int idx = N - 1;
    for (int t = 9999; t >= 0; t--) {
        while (idx >= 0) {
            int d = cows[idx].first,
                g = cows[idx].second;
            if (d < t + 1) {
                break;
            }
            deadlines.push(g);
            idx--;
        }
        if (!deadlines.empty()) {
            sum += deadlines.top();
            deadlines.pop();
        }
    }
    cout << sum << "\n";
    return 0;
}
