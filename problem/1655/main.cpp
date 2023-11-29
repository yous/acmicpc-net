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
    int lower_cnt = 0;
    int upper_cnt = 0;
    for (int i = 0; i < N; i++) {
        short num;
        cin >> num;
        if (lower_cnt == 0) {
            pq_lower.emplace(num);
            lower_cnt++;
        } else if (upper_cnt == 0) {
            short lower = pq_lower.top();
            if (num >= lower) {
                pq_upper.emplace(-num);
            } else {
                pq_lower.pop();
                pq_upper.emplace(-lower);
                pq_lower.emplace(num);
            }
            upper_cnt++;
        } else {
            short lower = pq_lower.top();
            short upper = -pq_upper.top();
            if (lower_cnt == upper_cnt) {
                if (num <= upper) {
                    pq_lower.emplace(num);
                } else {
                    pq_upper.pop();
                    pq_lower.emplace(upper);
                    pq_upper.emplace(-num);
                }
                lower_cnt++;
            } else {
                if (num >= lower) {
                    pq_upper.emplace(-num);
                } else {
                    pq_lower.pop();
                    pq_upper.emplace(-lower);
                    pq_lower.emplace(num);
                }
                upper_cnt++;
            }
        }
        cout << pq_lower.top() << "\n";
    }
    return 0;
}
