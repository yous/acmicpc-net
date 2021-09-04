#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct SegTree {
    int N;
    vector<long long> t;
    vector<long long> d;
    int l, r;
    long long v;

    SegTree(int n) {
        int power = 1;
        while (power < n * 2) {
            power *= 2;
        }
        N = power / 2;
        t.resize(power);
        d.resize(power);
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

    void update(int lo, int hi, long long val) {
        l = lo;
        r = hi;
        v = val;
        update(1, 0, N - 1);
    }

    long long query(int pos) {
        l = r = pos;
        return query(1, 0, N - 1);
    }

  private:
    void apply(int idx, int lo, int hi) {
        if (d[idx] == 0) {
            return;
        }
        if (lo != hi) {
            d[idx * 2] += d[idx];
            d[idx * 2 + 1] += d[idx];
        }
        t[idx] += d[idx] * (hi - lo + 1);
        d[idx] = 0;
    }

    void update(int idx, int lo, int hi) {
        apply(idx, lo, hi);
        if (r < lo || hi < l) {
            return;
        }
        if (l <= lo && hi <= r) {
            d[idx] = v;
            apply(idx, lo, hi);
            return;
        }
        int mid = (lo + hi) / 2;
        update(idx * 2, lo, mid);
        update(idx * 2 + 1, mid + 1, hi);
        t[idx] = t[idx * 2] + t[idx * 2 + 1];
    }

    long long query(int idx, int lo, int hi) {
        apply(idx, lo, hi);
        if (r < lo || hi < l) {
            return 0;
        }
        if (l <= lo && hi <= r) {
            return t[idx];
        }
        int mid = (lo + hi) / 2;
        return query(idx * 2, lo, mid) + query(idx * 2 + 1, mid + 1, hi);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N;
    SegTree st(N);
    auto it = st.begin();
    for (int i = 0; i < N; i++) {
        cin >> *it;
        ++it;
    }
    st.build(1, 0, st.N - 1);
    cin >> M;
    for (int i = 0; i < M; i++) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int a, b;
            long long c;
            cin >> a >> b >> c;
            st.update(a - 1, b - 1, c);
        } else {
            int a;
            cin >> a;
            cout << st.query(a - 1) << "\n";
        }
    }
    return 0;
}
