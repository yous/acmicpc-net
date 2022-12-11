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
    priority_queue<short> pq;
    for (int i = 0; i < N; i++) {
        short num;
        cin >> num;
        pq.emplace(num);
    }
    short ans = 0;
    while (!pq.empty() && ans <= 1440) {
        short num1 = pq.top();
        pq.pop();
        num1--;
        if (pq.empty()) {
            if (num1 > 0) {
                pq.emplace(num1);
            }
            ans++;
            continue;
        }
        short num2 = pq.top();
        pq.pop();
        num2--;
        if (num1 > 0) {
            pq.emplace(num1);
        }
        if (num2 > 0) {
            pq.emplace(num2);
        }
        ans++;
    }
    if (ans > 1440) {
        cout << "-1\n";
    } else {
        cout << ans << "\n";
    }
    return 0;
}
