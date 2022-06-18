#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct SegTree {
    int N;
    vector<pair<int, int>> t;

    SegTree(int n) : N(n), t(n * 2) {}

    void build(void) {
        for (int i = N - 1; i >= 1; i--) {
            t[i] = max(t[i * 2], t[i * 2 + 1]);
        }
    }

    void update(int pos, int val) {
        pos += N;
        for (t[pos].first = val; pos > 1; pos /= 2) {
            t[pos / 2] = max(t[pos], t[pos ^ 1]);
        }
    }

    pair<int, int> query(int l, int r) {
        pair<int, int> ans = {0, 0};
        for (l += N, r += N; l < r; l /= 2, r /= 2) {
            if ((l & 1) != 0) {
                ans = max(ans, t[l++]);
            }
            if ((r & 1) != 0) {
                ans = max(ans, t[--r]);
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
    SegTree st(N);
    for (int i = 0; i < N; i++) {
        cin >> st.t[N + i].first;
        st.t[N + i].second = i;
    }
    st.build();
    int M;
    cin >> M;
    while (M-- > 0) {
        short cmd;
        cin >> cmd;
        if (cmd == 1) {
            int i, v;
            cin >> i >> v;
            st.update(i - 1, v);
        } else {
            int l, r;
            cin >> l >> r;
            auto [max_val, max_idx] = st.query(l - 1, r);
            int second_max = 0;
            if (max_idx > l - 1) {
                second_max = max(second_max, st.query(l - 1, max_idx).first);
            }
            if (max_idx < r - 1) {
                second_max = max(second_max, st.query(max_idx + 1, r).first);
            }
            cout << max_val + second_max << "\n";
        }
    }
    return 0;
}
