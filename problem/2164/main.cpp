#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

int N;
deque<int> dq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        dq.push_back(i);
    }
    int front = dq.front();
    while (!dq.empty()) {
        dq.pop_front();
        if (dq.empty()) {
            break;
        }
        front = dq.front();
        dq.pop_front();
        dq.push_back(front);
        front = dq.front();
    }
    cout << front << "\n";
    return 0;
}
