#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, L;
vector<int> nums;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> L;
    int i;
    int num;
    for (i = 0; i < N; i++) {
        cin >> num;
        nums.push_back(num);
        pq.push({num, i});
        while (pq.top().second <= i - L) {
            pq.pop();
        }
        cout << pq.top().first;
        if (i < N - 1) {
            cout << " ";
        }
    }
    cout << "\n";
    return 0;
}
