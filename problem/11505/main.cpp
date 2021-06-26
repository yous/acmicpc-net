#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = static_cast<int>(1e9) + 7;
int N, M, K;

struct SegTree {
    int N;
    vector<int> t;

    SegTree(int n) : N(n), t(n * 2) {}

    void build(void) {
        for (int i = N - 1; i >= 0; i--) {
            t[i] = 1LL * t[i * 2] * t[i * 2 + 1] % MOD;
        }
    }

    void update(int pos, int val) {
        pos += N;
        for (t[pos] = val; pos > 1; pos /= 2) {
            t[pos / 2] = 1LL * t[pos] * t[pos ^ 1] % MOD;
        }
    }

    int query(int l, int r) {
        int ans = 1;
        for (l += N, r += N; l < r; l /= 2, r /= 2) {
            if (l & 1) {
                ans = 1LL * ans * t[l++] % MOD;
            }
            if (r & 1) {
                ans = 1LL * ans * t[--r] % MOD;
            }
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> K;
    SegTree st(N);
    for (int i = 0; i < N; i++) {
        cin >> st.t[i + N];
    }
    st.build();
    for (int i = 0; i < M + K; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            st.update(b - 1, c);
        } else if (a == 2) {
            cout << st.query(b - 1, c) << "\n";;
        }
    }
    return 0;
}
