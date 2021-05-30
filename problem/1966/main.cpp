#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int T;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T-- > 0) {
        int N, M;
        queue<int> qu;
        priority_queue<int> pq;
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
            int num;
            cin >> num;
            if (i == M) {
                qu.push(-num);
            } else {
                qu.push(num);
            }
            pq.push(num);
        }
        int ans = 1;
        while (!qu.empty()) {
            int front = qu.front();
            int prio = front < 0 ? -front : front;
            if (front < 0 && prio == pq.top()) {
                cout << ans << "\n";
                break;
            }
            if (prio == pq.top()) {
                qu.pop();
                pq.pop();
                ans++;
            } else {
                qu.pop();
                qu.push(front);
            }
        }
    }
    return 0;
}
