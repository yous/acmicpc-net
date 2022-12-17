#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

struct SegTree {
    int N;
    vector<long long> t;

    SegTree(int n) : N(n), t(n * 2) {
    }

    void build() {
        for (int i = N - 1; i >= 1; i--) {
            t[i] = max(t[i * 2], t[i * 2 + 1]);
        }
    }

    void update(int pos, long long val) {
        pos += N;
        for (t[pos] = val; pos > 1; pos /= 2) {
            t[pos / 2] = max(t[pos], t[pos ^ 1]);
        }
    }

    long long query(int l, int r) {
        long long ans = 0;
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
    vector<tuple<int, int, int>> banks(N);
    vector<int> indices(N);
    for (int i = 0; i < N; i++) {
        auto& [X, T, C] = banks[i];
        cin >> X >> T >> C;
        indices[i] = X - T;
    }
    sort(indices.begin(), indices.end());
    indices.erase(unique(indices.begin(), indices.end()), indices.end());
    auto indices_idx = [&](int X_T) {
        return lower_bound(indices.begin(), indices.end(), X_T) - indices.begin();
    };
    auto indices_sz = indices.size();
    SegTree st(indices_sz);
    st.build();
    for (int i = N - 1; i >= 0; i--) {
        auto [X, T, C] = banks[i];
        int idx = indices_idx(X - T);
        st.update(idx, C + st.query(0, idx + 1));
    }
    cout << st.query(0, indices_sz) << "\n";
    return 0;
}
