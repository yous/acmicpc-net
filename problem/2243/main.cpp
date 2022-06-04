#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct SegTree {
    int N;
    vector<unsigned int> t;

    SegTree(int n) : N(n), t(n * 2) {}

    void update(int pos, int val) {
        pos += N;
        for (t[pos] += val; pos > 1; pos /= 2) {
            t[pos / 2] = t[pos] + t[pos ^ 1];
        }
    }

    int query(unsigned int cnt) {
        int pos = 1;
        unsigned int cur = t[pos];
        while (pos < N) {
            if (cur - t[pos * 2 + 1] >= cnt) {
                cur -= t[pos * 2 + 1];
                pos *= 2;
            } else {
                pos = pos * 2 + 1;
            }
        }
        return pos - N;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    SegTree st(1 << 20);
    for (int i = 0; i < N; i++) {
        short A;
        cin >> A;
        if (A == 1) {
            int B;
            cin >> B;
            int pos = st.query(B);
            st.update(pos, -1);
            cout << pos + 1 << "\n";
        } else {
            int B, C;
            cin >> B >> C;
            st.update(B - 1, C);
        }
    }
    return 0;
}
