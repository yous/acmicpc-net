#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, D;
vector<int> machines;

struct SegTree {
    int N;
    vector<unsigned int> t;
    vector<unsigned int> t_wo_left;
    vector<unsigned int> t_wo_right;
    vector<unsigned int> t_wo_both;

    SegTree(int n) : N(n), t(n * 2), t_wo_left(n * 2), t_wo_right(n * 2), t_wo_both(n * 2) {}

    void build(void) {
        for (int i = N - 1; i >= 0; i--) {
            t[i] = max(t[i * 2] + t_wo_left[i * 2 + 1],
                       t_wo_right[i * 2] + t[i * 2 + 1]);
            t_wo_left[i] = max(t_wo_left[i * 2] + t_wo_left[i * 2 + 1],
                               t_wo_both[i * 2] + t[i * 2 + 1]);
            t_wo_right[i] = max(t[i * 2] + t_wo_both[i * 2 + 1],
                                t_wo_right[i * 2] + t_wo_right[i * 2 + 1]);
            t_wo_both[i] = max(t_wo_left[i * 2] + t_wo_both[i * 2 + 1],
                               t_wo_both[i * 2] + t_wo_right[i * 2 + 1]);
        }
    }

    void update(int pos, int val) {
        pos += N;
        for (t[pos] = val; pos > 1; pos /= 2) {
            int lp, rp;
            if (pos % 2 == 0) {
                lp = pos;
                rp = pos + 1;
            } else {
                lp = pos - 1;
                rp = pos;
            }
            t[pos / 2] = max(t[lp] + t_wo_left[rp],
                             t_wo_right[lp] + t[rp]);
            t_wo_left[pos / 2] = max(t_wo_left[lp] + t_wo_left[rp],
                                     t_wo_both[lp] + t[rp]);
            t_wo_right[pos / 2] = max(t[lp] + t_wo_both[rp],
                                      t_wo_right[lp] + t_wo_right[rp]);
            t_wo_both[pos / 2] = max(t_wo_left[lp] + t_wo_both[rp],
                                     t_wo_both[lp] + t_wo_right[rp]);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> D;
    int order = 1;
    while (order < N) {
        order *= 2;
    }
    SegTree st(order);
    for (int i = 0; i < N; i++) {
        cin >> st.t[i + order];
    }
    st.build();
    long long ans = 0;
    for (int i = 0; i < D; i++) {
        int idx, m;
        cin >> idx >> m;
        st.update(idx - 1, m);
        ans += st.t[1];
    }
    cout << ans << "\n";
    return 0;
}
