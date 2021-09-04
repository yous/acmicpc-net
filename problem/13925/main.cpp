#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = static_cast<int>(1e9) + 7;
int N, M;

struct SegTree {
    int N;
    vector<int> t;
    vector<pair<int, int>> d;
    int l, r;
    int a, b;

    SegTree(int n) {
        int power = 1;
        while (power < n * 2) {
            power *= 2;
        }
        N = power / 2;
        t.resize(power);
        d.resize(power, {1, 0});
    }

    vector<int>::iterator begin() {
        return next(t.begin(), N);
    }

    int build(int idx, int lo, int hi) {
        if (lo == hi) {
            return t[idx];
        }
        int mid = (lo + hi) / 2;
        return t[idx] = (build(idx * 2, lo, mid) + build(idx * 2 + 1, mid + 1, hi)) % MOD;
    }

    void apply(int idx, int lo, int hi) {
        auto [a1, b1] = d[idx];
        if (a1 == 1 && b1 == 0) {
            return;
        }
        if (lo != hi) {
            for (int i = 0; i < 2; i++) {
                auto& [a2, b2] = d[idx * 2 + i];
                a2 = 1LL * a2 * a1 % MOD;
                b2 = (1LL * b2 * a1 + b1) % MOD;
            }
        }
        t[idx] = (1LL * a1 * t[idx] % MOD + 1LL * b1 * (hi - lo + 1) % MOD) % MOD;
        d[idx] = {1, 0};
    }

    void update(int idx, int lo, int hi) {
        apply(idx, lo, hi);
        if (r < lo || hi < l) {
            return;
        }
        if (l <= lo && hi <= r) {
            d[idx] = {a, b};
            apply(idx, lo, hi);
            return;
        }
        int mid = (lo + hi) / 2;
        update(idx * 2, lo, mid);
        update(idx * 2 + 1, mid + 1, hi);
        t[idx] = (t[idx * 2] + t[idx * 2 + 1]) % MOD;
    }

    int query(int idx, int lo, int hi) {
        apply(idx, lo, hi);
        if (r < lo || hi < l) {
            return 0;
        }
        if (l <= lo && hi <= r) {
            return t[idx];
        }
        int mid = (lo + hi) / 2;
        return (query(idx * 2, lo, mid) + query(idx * 2 + 1, mid + 1, hi)) % MOD;
    }

    void update(int l, int r, int a, int b) {
        this->l = l;
        this->r = r;
        this->a = a;
        this->b = b;
        update(1, 0, N - 1);
    }

    int query(int l, int r) {
        this->l = l;
        this->r = r;
        return query(1, 0, N - 1);
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
    cin >> M;
    for (int i = 0; i < M; i++) {
        int cmd, x, y, v;
        cin >> cmd >> x >> y;
        if (cmd != 4) {
            cin >> v;
        }
        switch (cmd) {
            case 1:
                st.update(x - 1, y - 1, 1, v);
                break;
            case 2:
                st.update(x - 1, y - 1, v, 0);
                break;
            case 3:
                st.update(x - 1, y - 1, 0, v);
                break;
            case 4:
                cout << st.query(x - 1, y - 1) << "\n";
                break;
        }
    }
    return 0;
}
