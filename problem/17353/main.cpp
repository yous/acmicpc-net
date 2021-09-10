#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, Q;

struct SegTree {
    int N;
    vector<long long> t;
    vector<pair<long long, int>> d;
    int l, r;

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

    void update(int l, int r) {
        this->l = l;
        this->r = r;
        update(1, 0, N - 1);
    }

    long long query(int l, int r) {
        this->l = l;
        this->r = r;
        return query(1, 0, N - 1);
    }

  private:
    void apply(int idx, int lo, int hi) {
        auto& [init, step] = d[idx];
        if (init == 0 && step == 0) {
            return;
        }
        int mid = (lo + hi) / 2;
        t[idx * 2] += 1LL * (init * 2 + 1LL * step * (mid - lo)) * (mid - lo + 1) / 2;
        t[idx * 2 + 1] += 1LL * (init * 2 + 1LL * step * (mid + 1 - lo + hi - lo)) * (hi - (mid + 1) + 1) / 2;
        auto& [i1, s1] = d[idx * 2];
        i1 += init;
        s1 += step;
        auto& [i2, s2] = d[idx * 2 + 1];
        i2 += init + 1LL * step * (mid + 1 - lo);
        s2 += step;
        init = 0;
        step = 0;
    }

    void update(int idx, int lo, int hi) {
        if (r < lo || hi < l) {
            return;
        }
        if (l <= lo && hi <= r) {
            int init = lo - l + 1;
            t[idx] += 1LL * (init * 2 + hi - lo) * (hi - lo + 1) / 2;
            d[idx].first += init;
            d[idx].second++;
            return;
        }
        apply(idx, lo, hi);
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
        apply(idx, lo, hi);
        int mid = (lo + hi) / 2;
        return query(idx * 2, lo, mid) + query(idx * 2 + 1, mid + 1, hi);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    SegTree st(N);
    auto it = st.begin();
    for (int i = 0; i < N; i++) {
        cin >> *it;
        ++it;
    }
    st.build(1, 0, st.N - 1);
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int cmd, l, r;
        cin >> cmd >> l;
        if (cmd == 1) {
            cin >> r;
            st.update(l - 1, r - 1);
        } else {
            cout << st.query(l - 1, l - 1) << "\n";
        }
    }
    return 0;
}
