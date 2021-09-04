#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

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

    void build() {
        build(1, 0, N - 1);
    }

    void update(int pos, long long val) {
        l = r = pos;
        v = val;
        update(1, 0, N - 1);
    }

    long long query(int lo, int hi) {
        l = lo;
        r = hi;
        return query(1, 0, N - 1);
    }

  private:
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
            t[idx] += v;
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
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N;
    SegTree st(N + 1);
    auto it = st.begin();
    int prev_num = 0;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        *it = num - prev_num;
        prev_num = num;
        ++it;
    }
    *it = 0;
    st.build();
    cin >> M;
    for (int i = 0; i < M; i++) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int a, b;
            long long c;
            cin >> a >> b >> c;
            st.update(a - 1, c);
            st.update(b, -c);
        } else {
            int a;
            cin >> a;
            cout << st.query(0, a - 1) << "\n";
        }
    }
    return 0;
}
