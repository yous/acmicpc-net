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
    vector<vector<int>> numbers(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> numbers[j][i];
        }
    }
    priority_queue<pair<int, short>> pq;
    for (int i = 0; i < N; i++) {
        pq.emplace(numbers[i].back(), i);
        numbers[i].pop_back();
    }
    for (int i = 0; i < N - 1; i++) {
        auto [num, idx] = pq.top();
        pq.pop();
        if (!numbers[idx].empty()) {
            pq.emplace(numbers[idx].back(), idx);
            numbers[idx].pop_back();
        }
    }
    auto [num, idx] = pq.top();
    cout << num << "\n";
    return 0;
}
