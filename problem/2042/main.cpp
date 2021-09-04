#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M, K;

struct SegTree {
    int N;
    vector<long long> t;
    int l, r;
    long long v;

    SegTree(int n) {
        int power = 1;
        while (power < n * 2) {
            power *= 2;
        }
        N = power / 2;
        t.resize(power);
    }

    vector<long long>::iterator begin() {
        return next(t.begin(), N);
    }

    long long build(int idx, int lo, int hi) {
        if (lo == hi) {
            return t[idx];
        }
        int mid = (lo + hi) / 2;
        return t[idx] = build(idx * 2, lo, mid) + build(idx * 2 + 1, mid + 1, hi);
    }

    void update(int idx, int lo, int hi) {
        if (r < lo || hi < l) {
            return;
        }
        if (l <= lo && hi <= r) {
            t[idx] = v;
            return;
        }
        int mid = (lo + hi) / 2;
        update(idx * 2, lo, mid);
        update(idx * 2 + 1, mid + 1, hi);
        t[idx] = t[idx * 2] + t[idx * 2 + 1];
    }

    long long query(int idx, int lo, int hi) {
        if (r < lo || hi < l) {
            return 0;
        }
        if (l <= lo && hi <= r) {
            return t[idx];
        }
        int mid = (lo + hi) / 2;
        return query(idx * 2, lo, mid) + query(idx * 2 + 1, mid + 1, hi);
    }

    void update(int pos, long long val) {
        l = r = pos;
        v = val;
        update(1, 0, N - 1);
    }

    long long query(int l, int r) {
        this->l = l;
        this->r = r;
        return query(1, 0, N - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> K;
    SegTree st(N);
    auto it = st.begin();
    for (int i = 0; i < N; i++) {
        cin >> *it;
        ++it;
    }
    st.build(1, 0, st.N - 1);
    for (int i = 0; i < M + K; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        if (a == 1) {
            st.update(b - 1, c);
        } else {
            cout << st.query(b - 1, c - 1) << "\n";
        }
    }
    return 0;
}
