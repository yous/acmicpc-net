#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct SegTree {
    int N;
    vector<int> t;

    SegTree(int n) : N(n), t(n * 2) {}

    void build(void) {
        for (int i = N - 1; i >= 1; i--) {
            t[i] = t[i * 2] + t[i * 2 + 1];
        }
    }

    void update(int pos, int val) {
        pos += N;
        for (t[pos] += val; pos > 1; pos /= 2) {
            t[pos / 2] = t[pos] + t[pos ^ 1];
        }
    }

    int query(int l, int r) {
        int ans = 0;
        for (l += N, r += N; l < r; l /= 2, r /= 2) {
            if ((l & 1) != 0) {
                ans += t[l++];
            }
            if ((r & 1) != 0) {
                ans += t[--r];
            }
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<pair<int, int>> jobs(N);
    SegTree st(N);
    for (int i = 0; i < N; i++) {
        cin >> jobs[i].first;
        st.t[N + i] = 1;
        jobs[i].second = i;
    }
    st.build();
    sort(jobs.begin(), jobs.end());
    vector<long long> ans(N);
    long long total_time = 0;
    int cur_time = 0;
    int cur_idx = 0;
    for (int i = 0; i < N; i++) {
        auto [time, idx] = jobs[i];
        if (idx < cur_idx) {
            total_time += st.query(cur_idx, N);
            cur_idx = 0;
            cur_time++;
        }
        if (cur_time < time - 1) {
            total_time += 1LL * (time - 1 - cur_time) * (N - i);
            cur_time = time - 1;
        }
        total_time += st.query(cur_idx, idx + 1);
        ans[idx] = total_time;
        st.update(idx, -1);
        cur_idx = idx;
    }
    for (long long time : ans) {
        cout << time << "\n";
    }
    return 0;
}
