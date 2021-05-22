#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

int N, L;
deque<pair<int, int>> dq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> L;
    int i;
    int num;
    for (i = 0; i < N; i++) {
        cin >> num;
        if (!dq.empty() && dq.front().second <= i - L) {
            dq.pop_front();
        }
        while (!dq.empty() && dq.back().first >= num) {
            dq.pop_back();
        }
        dq.push_back({num, i});
        cout << dq.front().first;
        if (i < N - 1) {
            cout << " ";
        }
    }
    cout << "\n";
    return 0;
}
