#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    priority_queue<pair<int, bool>> pq;
    while (N-- > 0) {
        int num;
        cin >> num;
        if (num == 0) {
            if (pq.empty()) {
                cout << "0\n";
            } else {
                auto& p = pq.top();
                if (p.second) {
                    cout << p.first << "\n";
                } else {
                    cout << -p.first << "\n";
                }
                pq.pop();
            }
        } else {
            if (num > 0) {
                pq.emplace(-num, false);
            } else {
                pq.emplace(num, true);
            }
        }
    }
    return 0;
}
