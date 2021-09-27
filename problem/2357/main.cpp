#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;

struct SegTree {
    int N;
    vector<pair<int, int>> t;

    SegTree(int n) : N(n), t(n * 2) {}

    void build() {
        for (int i = N - 1; i >= 1; i--) {
            t[i] = {min(t[i * 2].first, t[i * 2 + 1].first), max(t[i * 2].second, t[i * 2 + 1].second)};
        }
    }

    pair<int, int> query(int l, int r) {
        pair<int, int> min_max = t[l + N];
        for (l += N, r += N; l < r; l /= 2, r /= 2) {
            if (l & 1) {
                min_max = {min(min_max.first, t[l].first), max(min_max.second, t[l].second)};
                l++;
            }
            if (r & 1) {
                r--;
                min_max = {min(min_max.first, t[r].first), max(min_max.second, t[r].second)};
            }
        }
        return min_max;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    SegTree st(N);
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        st.t[i + N] = {num, num};
    }
    st.build();
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        auto mm = st.query(a - 1, b);
        cout << mm.first << " " << mm.second << "\n";
    }
    return 0;
}
