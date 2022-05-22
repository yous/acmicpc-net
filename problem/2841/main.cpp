#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, P;
    cin >> N >> P;
    vector<priority_queue<int>> lines(6);
    int ans = 0;
    for (int i = 0; i < N; i++) {
        short line;
        int fret;
        cin >> line >> fret;
        auto& pq = lines[line - 1];
        if (pq.empty()) {
            pq.emplace(fret);
            ans++;
        } else {
            while (!pq.empty() && pq.top() > fret) {
                pq.pop();
                ans++;
            }
            if (pq.empty()) {
                pq.emplace(fret);
                ans++;
            } else if (pq.top() < fret) {
                pq.emplace(fret);
                ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
