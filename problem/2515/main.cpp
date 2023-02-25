#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, S;
    cin >> N >> S;
    vector<pair<int, short>> paintings(N);
    for (auto& [H, C] : paintings) {
        cin >> H >> C;
    }
    sort(paintings.begin(), paintings.end());
    vector<int> cache(N, -1);
    cache[0] = paintings[0].second;
    int lo = 0;
    for (int i = 1; i < N; i++) {
        auto [H, C] = paintings[i];
        auto& ans = cache[i];
        ans = max(int(C), cache[i - 1]);
        if (paintings[lo].first <= H - S) {
            while (lo + 1 < N && paintings[lo + 1].first <= H - S) {
                lo++;
            }
            ans = max(ans, C + cache[lo]);
        }
    }
    cout << cache[N - 1] << "\n";
    return 0;
}
