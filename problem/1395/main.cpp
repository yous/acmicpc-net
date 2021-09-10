#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;

struct SegTree {
    int N;
    vector<int> t;
    vector<bool> sw;
    int l, r;

    SegTree(int n) {
        int power = 1;
        while (power < n * 2) {
            power *= 2;
        }
        N = power / 2;
        t.resize(power);
        sw.resize(power);
    }

    void update(int l, int r) {
        this->l = l;
        this->r = r;
        update(1, 0, N - 1);
    }

    int query(int l, int r) {
        this->l = l;
        this->r = r;
        return query(1, 0, N - 1);
    }

  private:
    void apply(int idx, int lo, int hi) {
        if (!sw[idx]) {
            return;
        }
        int mid = (lo + hi) / 2;
        t[idx * 2] = mid - lo + 1 - t[idx * 2];
        t[idx * 2 + 1] = hi - (mid + 1) + 1 - t[idx * 2 + 1];
        sw[idx * 2] = !sw[idx * 2];
        sw[idx * 2 + 1] = !sw[idx * 2 + 1];
        sw[idx] = false;
    }

    void update(int idx, int lo, int hi) {
        if (r < lo || hi < l) {
            return;
        }
        if (l <= lo && hi <= r) {
            t[idx] = hi - lo + 1 - t[idx];
            sw[idx] = !sw[idx];
            return;
        }
        apply(idx, lo, hi);
        int mid = (lo + hi) / 2;
        update(idx * 2, lo, mid);
        update(idx * 2 + 1, mid + 1, hi);
        t[idx] = t[idx * 2] + t[idx * 2 + 1];
    }

    int query(int idx, int lo, int hi) {
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
    cin >> N >> M;
    SegTree st(N);
    for (int i = 0; i < M; i++) {
        int o, s, t;
        cin >> o >> s >> t;
        if (o == 0) {
            st.update(s - 1, t - 1);
        } else {
            cout << st.query(s - 1, t - 1) << "\n";
        }
    }
    return 0;
}
