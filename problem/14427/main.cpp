#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct SegTree {
    int N;
    vector<pair<int, int>> t;

    SegTree(int n) : N(n), t(n * 2) {}

    void build() {
        for (int i = N - 1; i >= 1; i--) {
            t[i] = min(t[i * 2], t[i * 2 + 1]);
        }
    }

    void update(int pos, int val) {
        pos += N;
        for (t[pos] = {val, pos - N + 1}; pos > 1; pos /= 2) {
            t[pos / 2] = min(t[pos], t[pos ^ 1]);
        }
    }

    pair<int, int> query(int l, int r) {
        pair<int, int> ans = t[l + N];
        for (l += N, r += N; l < r; l /= 2, r /= 2) {
            if (l & 1) {
                ans = min(ans, t[l++]);
            }
            if (r & 1) {
                ans = min(ans, t[--r]);
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
        int num;
        cin >> num;
        st.t[i + N] = {num, i + 1};
    }
    st.build();
    int M;
    cin >> M;
    while (M-- > 0) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int i, v;
            cin >> i >> v;
            st.update(i - 1, v);
        } else {
            cout << st.query(0, N).second << "\n";
        }
    }
    return 0;
}
