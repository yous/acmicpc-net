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

int solve(int idx, int total, int cnt, vector<short>& dist) {
    if (cnt == M) {
        return accumulate(dist.begin(), dist.end(), 0);
    }
    if (idx == total) {
        return INF;
    }
    int ans = INF;
    auto& chicken = chickens[idx];
    vector<pair<short, short>> prev_dist;
    for (int i = 0, sz = houses.size(); i < sz; i++) {
        auto& p = houses[i];
        short d = abs(chicken.first - p.first) + abs(chicken.second - p.second);
        if (d < dist[i]) {
            prev_dist.emplace_back(i, dist[i]);
            dist[i] = d;
        }
    }
    ans = min(ans, solve(idx + 1, total, cnt + 1, dist));
    for (auto& p : prev_dist) {
        dist[p.first] = p.second;
    }
    return min(ans, solve(idx + 1, total, cnt, dist));
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
    cout << solve(0, total, 0, dist) << "\n";
    return 0;
}
