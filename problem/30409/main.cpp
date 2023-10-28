#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;

long long solve(int idx, bool is_left, vector<int>& poles, vector<vector<long long>>& cache) {
    if (idx < 0 || idx >= N) {
        return 0;
    }
    auto& ans = cache[idx][is_left ? 0 : 1];
    if (ans != -1) {
        return ans;
    }
    ans = 0;
    int cur_idx = idx;
    int cur_h = poles[cur_idx];
    if (is_left) {
        for (int i = idx - 1; i >= 0; i--) {
            int h = poles[i];
            if (h >= cur_h) {
                ans = 1LL * (h - cur_h) * (h - cur_h) + 1LL * (cur_idx - i) * (cur_idx - i) + solve(i, is_left, poles, cache);
                return ans;
            }
        }
    } else {
        for (int i = idx + 1; i < N; i++) {
            int h = poles[i];
            if (h >= cur_h) {
                ans = 1LL * (h - cur_h) * (h - cur_h) + 1LL * (i - cur_idx) * (i - cur_idx) + solve(i, is_left, poles, cache);
                return ans;
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    vector<int> poles(N);
    for (auto& num : poles) {
        cin >> num;
    }
    vector<vector<long long>> cache(N, vector<long long>(2, -1));
    cache[0][0] = 0;
    for (int i = 1; i < N; i++) {
        if (poles[i] > poles[i - 1]) {
            cache[i][0] = 0;
        } else {
            break;
        }
    }
    cache[N - 1][1] = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (poles[i] > poles[i + 1]) {
            cache[i][1] = 0;
        } else {
            break;
        }
    }
    int Q;
    cin >> Q;
    for (int q = 0; q < Q; q++) {
        int P;
        cin >> P;
        P--;
        cout << solve(P, true, poles, cache) + solve(P, false, poles, cache) << "\n";
    }
    return 0;
}
