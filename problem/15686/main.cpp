#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

const short INF = 30000;
int N, M;
vector<pair<short, short>> houses;
vector<short> dist;
vector<pair<short, short>> chickens;

int solve(int idx, int total, int cnt, vector<bool>& selected, vector<short>& dist) {
    if (cnt == M) {
        return accumulate(dist.begin(), dist.end(), 0);
    }
    if (idx == total) {
        return INF;
    }
    int ans = INF;
    selected[idx] = true;
    auto& chicken = chickens[idx];
    vector<short> prev_dist(dist.size());
    copy(dist.begin(), dist.end(), prev_dist.begin());
    for (int i = 0, sz = houses.size(); i < sz; i++) {
        auto& p = houses[i];
        short d = abs(chicken.first - p.first) + abs(chicken.second - p.second);
        if (d < dist[i]) {
            dist[i] = d;
        }
    }
    ans = min(ans, solve(idx + 1, total, cnt + 1, selected, dist));
    dist = prev_dist;
    selected[idx] = false;
    return min(ans, solve(idx + 1, total, cnt, selected, dist));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (short i = 0; i < N; i++) {
        for (short j = 0; j < N; j++) {
            short num;
            cin >> num;
            if (num == 1) {
                houses.emplace_back(i, j);
            } else if (num == 2) {
                chickens.emplace_back(i, j);
            }
        }
    }
    dist.resize(houses.size(), INF);
    int total = chickens.size();
    vector<bool> selected(total);
    cout << solve(0, total, 0, selected, dist) << "\n";
    return 0;
}
