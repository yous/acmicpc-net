#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
deque<int> dq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    int i;
    for (i = 1; i <= N; i++) {
        dq.push_back(i);
    }
    int num;
    int total = 0;
    for (i = 0; i < M; i++) {
        cin >> num;
        int count = 0;
        int front = dq.front();
        while (front != num) {
            dq.pop_front();
            dq.push_back(front);
            front = dq.front();
            count++;
        }
        count = min(count, static_cast<int>(dq.size()) - count);
        total += count;
        dq.pop_front();
    }
    cout << total << "\n";
    return 0;
}
