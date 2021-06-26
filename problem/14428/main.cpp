#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
int M;

struct SegTree {
    int N;
    vector<pair<int, int>> t;

    SegTree(int n) : N(n), t(n * 2) {}

    void build(void) {
        for (int i = N - 1; i >= 0; i--) {
            t[i] = min(t[i * 2], t[i * 2 + 1]);
        }
    }

    void update(int pos, int val) {
        pos += N;
        for (t[pos] = {val, pos - N}; pos > 1; pos /= 2) {
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
    cin >> N;
    SegTree st(N);
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        st.t[i + N] = {num, i};
    }
    st.build();
    cin >> M;
    for (int i = 0; i < M; i++) {
        int cmd, a, b;
        cin >> cmd >> a >> b;
        if (cmd == 1) {
            st.update(a - 1, b);
        } else if (cmd == 2) {
            cout << st.query(a - 1, b).second + 1 << "\n";
        }
    }
    return 0;
}
