#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct SegTree {
    int N;
    vector<int> t;

    SegTree(int n) : N(n), t(n * 2) {}

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
    vector<int> num_idx(N);
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        num_idx[num - 1] = i;
    }
    SegTree st(N);
    int lo = 0;
    int hi = N - 1;
    while (lo <= hi) {
        cout << num_idx[lo] - st.query(0, num_idx[lo]) << "\n";
        st.update(num_idx[lo], 1);
        if (lo != hi) {
            cout << N - 1 - num_idx[hi] - st.query(num_idx[hi] + 1, N) << "\n";
            st.update(num_idx[hi], 1);
        }
        lo++;
        hi--;
    }
    return 0;
}
