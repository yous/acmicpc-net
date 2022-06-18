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

    int kth(int k) {
        int i = 1;
        while (i < N) {
            if (t[i * 2] > k) {
                i *= 2;
            } else {
                k -= t[i * 2];
                i = i * 2 + 1;
            }
        }
        return i - N;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    int sz = 1;
    while (sz < N) {
        sz *= 2;
    }
    SegTree st(sz);
    for (int i = 0; i < N; i++) {
        st.t[sz + i] = 1;
    }
    st.build();
    cout << "<" << K;
    int cur = K - 1;
    st.update(K - 1, -1);
    int rem = N - 1;
    while (rem > 0) {
        int add = (K - 1) % rem + 1;
        int left_sum = st.query(0, cur);
        int idx;
        if (rem - left_sum >= add) {
            idx = st.kth(left_sum + add - 1);
        } else {
            idx = st.kth(add - (rem - left_sum) - 1);
        }
        cout << ", " << idx + 1;
        st.update(idx, -1);
        cur = idx;
        rem--;
    }
    cout << ">\n";
    return 0;
}
