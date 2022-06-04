#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct SegTree {
    int N;
    vector<short> t;

    SegTree(int n) : N(n), t(n * 2) {
    }

    void build() {
        for (int i = N - 1; i >= 1; i--) {
            t[i] = t[i * 2] * t[i * 2 + 1];
        }
    }

    void update(int pos, short val) {
        pos += N;
        for (t[pos] = val; pos > 1; pos /= 2) {
            t[pos / 2] = t[pos] * t[pos ^ 1];
        }
    }

    char query(int l, int r) {
        short ans = 1;
        for (l += N, r += N; l < r; l /= 2, r /= 2) {
            if ((l & 1) != 0) {
                ans *= t[l++];
            }
            if ((r & 1) != 0) {
                ans *= t[--r];
            }
        }
        return "-0+"[ans + 1];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    SegTree st(100000);
    int N, K;
    while (cin >> N >> K) {
        st.N = N;
        for (int i = 0; i < N; i++) {
            short num;
            cin >> num;
            st.t[i + N] = (num > 0 ? 1 : (num < 0 ? -1 : 0));
        }
        st.build();
        for (int k = 0; k < K; k++) {
            char cmd;
            cin >> cmd;
            if (cmd == 'C') {
                int i;
                short num;
                cin >> i >> num;
                st.update(i - 1, num > 0 ? 1 : (num < 0 ? -1 : 0));
            } else {
                int i, j;
                cin >> i >> j;
                cout << st.query(i - 1, j);
            }
        }
        cout << "\n";
    }
    return 0;
}
