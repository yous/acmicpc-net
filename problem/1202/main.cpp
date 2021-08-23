#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int N, K;
vector<pair<int, int>> jewels;
map<int, int> C;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int m, v;
        cin >> m >> v;
        jewels.emplace_back(v, m);
    }
    sort(jewels.begin(), jewels.end(), greater<pair<int, int>>());
    for (int i = 0; i < K; i++) {
        int c;
        cin >> c;
        C[c]++;
    }
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        auto it = C.lower_bound(jewels[i].second);
        if (it != C.end()) {
            ans += jewels[i].first;
            if (it->second > 1) {
                it->second--;
            } else {
                C.erase(it);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
