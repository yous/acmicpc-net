#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, T;
    cin >> N >> T;
    vector<pair<int, int>> times(1000000);
    int total_cnt = 0;
    for (int i = 0; i < N; i++) {
        int K;
        cin >> K;
        for (int j = total_cnt; j < total_cnt + K * 2; j += 2) {
            int S, E;
            cin >> S >> E;
            times[j] = {S, 1};
            times[j + 1] = {E, -1};
        }
        total_cnt += K * 2;
    }
    sort(times.begin(), times.begin() + total_cnt);
    vector<int> people(100000);
    int idx = 0;
    int cur_point = 0;
    for (int t = 0; t < 100000; t++) {
        while (idx < total_cnt && times[idx].first <= t) {
            cur_point += times[idx].second;
            idx++;
        }
        people[t] = cur_point;
    }
    vector<long long> prefix_sum(100001);
    long long cur_sum = 0;
    for (int i = 1; i <= 100000; i++) {
        cur_sum += people[i - 1];
        prefix_sum[i] = cur_sum;
    }
    long long max_point = 0;
    int ans = 0;
    for (int i = 0; i < 100000; i++) {
        if (i + T > 100000) {
            break;
        }
        long long point = prefix_sum[i + T] - prefix_sum[i];
        if (max_point < point) {
            max_point = point;
            ans = i;
        }
    }
    cout << ans << " " << ans + T << "\n";
    return 0;
}
