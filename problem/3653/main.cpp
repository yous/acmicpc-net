#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct SegTree {
    int N;
    vector<int> t;

    SegTree(int n) : N(n), t(n * 2) {}

    void build(void) {
        for (int i = N - 1; i >= 1; i--) {
            t[i] = t[i * 2] + t[i * 2 + 1];
        }
    }

    void update(int pos, int val) {
        pos += N;
        for (t[pos] += val; pos > 1; pos /= 2) {
            t[pos / 2] = t[pos] + t[pos ^ 1];
        }
    }

    int query(int l, int r) {
        int ans = 0;
        for (l += N, r += N; l < r; l /= 2, r /= 2) {
            if ((l & 1) != 0) {
                ans += t[l++];
            }
            if ((r & 1) != 0) {
                ans += t[--r];
            }
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short T;
    cin >> T;
    while (T-- > 0) {
        int N, M;
        cin >> N >> M;
        vector<int> movie_idx(N);
        SegTree st(N + M);
        for (int i = 0; i < N; i++) {
            movie_idx[i] = N - i - 1;
            st.t[N + M + i] = 1;
        }
        st.build();
        int num;
        cin >> num;
        cout << st.query(movie_idx[num - 1] + 1, N + M);
        st.update(movie_idx[num - 1], -1);
        movie_idx[num - 1] = N;
        st.update(movie_idx[num - 1], 1);
        for (int i = 1; i < M; i++) {
            cin >> num;
            cout << " " << st.query(movie_idx[num - 1] + 1, N + M);
            st.update(movie_idx[num - 1], -1);
            movie_idx[num - 1] = N + i;
            st.update(movie_idx[num - 1], 1);
        }
        cout << "\n";
    }
    return 0;
}
