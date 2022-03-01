#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    vector<pair<int, short>> towns(N);
    for (auto& [x, a] : towns) {
        cin >> a >> x;
    }
    sort(towns.begin(), towns.end());
    vector<pair<int, int>> candidates(Q);
    for (int i = 0; i < Q; i++) {
        int num;
        cin >> num;
        candidates[i] = {num, i};
    }
    sort(candidates.begin(), candidates.end());
    vector<long long> ans(Q);
    long long cur_sum = 0;
    auto [q, idx] = candidates[0];
    int left_cnt = 0;
    int right_cnt = 0;
    int first_right = N;
    for (int i = 0; i < N; i++) {
        auto [x, a] = towns[i];
        if (x <= q) {
            left_cnt += a;
            cur_sum += 1LL * a * (q - x);
        } else {
            first_right = min(first_right, i);
            right_cnt += a;
            cur_sum += 1LL * a * (x - q);
        }
        ans[idx] = cur_sum;
    }
    int prev_q = q;
    for (int i = 1; i < Q; i++) {
        auto [q, idx] = candidates[i];
        cur_sum += 1LL * left_cnt * (q - prev_q);
        while (first_right < N && towns[first_right].first <= q) {
            auto [x, a] = towns[first_right];
            cur_sum -= 1LL * a * (x - prev_q);
            cur_sum += 1LL * a * (q - x);
            left_cnt += a;
            right_cnt -= a;
            first_right++;
        }
        cur_sum -= 1LL * right_cnt * (q - prev_q);
        ans[idx] = cur_sum;
        prev_q = q;
    }
    for (int i = 0; i < Q; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}
