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
    priority_queue<short> pq_lower;
    priority_queue<short> pq_upper;
    for (int i = 0; i < N; i++) {
        short num;
        cin >> num;
        if (i % 2 == 0) {
            pq_upper.emplace(-num);
            pq_lower.emplace(-pq_upper.top());
            pq_upper.pop();
        } else {
            pq_lower.emplace(num);
            pq_upper.emplace(-pq_lower.top());
            pq_lower.pop();
        }
        cout << pq_lower.top() << "\n";
    }
    return 0;
}
