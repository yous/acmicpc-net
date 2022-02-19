#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    priority_queue<pair<int, int>> pq;
    vector<tuple<int, int, int>> carts;
    for (int i = 0; i < K; i++) {
        pq.emplace(0, -i);
    }
    for (int i = 0; i < N; i++) {
        int id;
        short w;
        cin >> id >> w;
        auto [time, k] = pq.top();
        time = -time;
        k = -k;
        pq.pop();
        pq.emplace(-(time + w), -k);
        carts.emplace_back(time + w, -k, id);
    }
    sort(carts.begin(), carts.end());
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        auto [time, k, id] = carts[i];
        ans += 1LL * (i + 1) * id;
    }
    cout << ans << "\n";
    return 0;
}
