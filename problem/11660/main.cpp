#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct SegTree {
    int N;
    vector<int> t;

    SegTree(int n) : N(n), t(n * 2) {}

    void build(void) {
        for (int i = N - 1; i >= 0; i--) {
            t[i] = t[i * 2] + t[i * 2 + 1];
        }
    }

    int query(int l, int r) {
        int ans = 0;
        for (l += N, r += N; l < r; l /= 2, r /= 2) {
            if (l & 1) {
                ans += t[l++];
            }
            if (r & 1) {
                ans += t[--r];
            }
        }
        return ans;
    }
};

int N, M;
vector<SegTree> matrix;

void build(void) {
    for (int idx = N - 1; idx >= 0; idx--) {
        SegTree& st = matrix[idx];
        SegTree& child1 = matrix[idx * 2];
        SegTree& child2 = matrix[idx * 2 + 1];
        for (int i = 0; i < N * 2; i++) {
            st.t[i] = child1.t[i] + child2.t[i];
        }
    }
}

int query(int lo, int hi, int l, int r) {
    int ans = 0;
    for (lo += N, hi += N; lo < hi; lo /= 2, hi /= 2) {
        if (lo & 1) {
            ans += matrix[lo++].query(l, r);
        }
        if (hi & 1) {
            ans += matrix[--hi].query(l, r);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    matrix.resize(N * 2, SegTree(N));
    for (int i = N; i < N * 2; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i].t[j + N];
        }
        matrix[i].build();
    }
    build();
    for (int i = 0; i < M; i++) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        cout << query(y1 - 1, y2, x1 - 1, x2) << "\n";
    }
    return 0;
}
