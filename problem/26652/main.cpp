#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    long long M;
    cin >> N >> M;
    int min_level = int(1e9);
    int max_level = 1;
    vector<int> L(N);
    for (auto& num : L) {
        cin >> num;
        min_level = min(min_level, num);
        max_level = max(max_level, num);
    }
    vector<long long> A(N);
    for (auto& num : A) {
        cin >> num;
    }
    map<long long, int> levels;
    for (int i = 0; i < N; i++) {
        long long lo = L[i];
        long long hi = (long long)2e9;
        while (lo <= hi) {
            long long mid = (lo + hi) / 2;
            long long sum = 1LL * (L[i] + mid) * (mid - L[i] + 1) / 2;
            if (A[i] >= sum) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        long long sum = 1LL * (L[i] + hi) * (hi - L[i] + 1) / 2;
        A[i] -= sum;
        L[i] = hi + 1;
        levels[L[i]]++;
    }
    long long ans = -1;
    long long level = levels.begin()->first;
    if (level >= max_level) {
        ans = level;
    }
    while (M > 0) {
        auto it = levels.begin();
        auto [level, cnt] = *it;
        if (next(it) != levels.end()) {
            long long next_level = next(it)->first;
            if (M >= 1LL * (next_level - level) * cnt) {
                M -= 1LL * (next_level - level) * cnt;
                levels.erase(levels.begin());
                levels[next_level] += cnt;
                if (next_level >= max_level) {
                    ans = next_level;
                }
            } else {
                long long res_level = level + M / cnt;
                if (res_level >= max_level) {
                    ans = res_level;
                }
                break;
            }
        } else {
            long long res_level = level + M / cnt;
            if (res_level >= max_level) {
                ans = res_level;
            }
            break;
        }
    }
    cout << ans << "\n";
    return 0;
}
