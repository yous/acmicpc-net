#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct SegTree {
    int N;
    vector<int> t;

    SegTree(int n) : N(n), t(n * 2) {}

    void build() {
        for (int i = N - 1; i >= 1; i--) {
            t[i] = t[i * 2] + t[i * 2 + 1];
        }
    }

    void update(int pos, int val) {
        pos += N;
        for (t[pos] = val; pos > 1; pos /= 2) {
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
    SegTree st(N);
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        st.t[i + N] = num % 2;
    }
    st.build();
    int M;
    cin >> M;
    for (int m = 0; m < M; m++) {
        short cmd;
        cin >> cmd;
        if (cmd == 1) {
            int i, x;
            cin >> i >> x;
            st.update(i - 1, x % 2);
        } else if (cmd == 2) {
            int l, r;
            cin >> l >> r;
            cout << r - l + 1 - st.query(l - 1, r) << "\n";
        } else {
            int l, r;
            cin >> l >> r;
            cout << st.query(l - 1, r) << "\n";
        }
    }
    return 0;
}
