#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> inv_seq;
vector<int> sequ;

struct SegTree {
    int N;
    vector<int> t;

    SegTree(int n) : N(n), t(n * 2) {}

    void build(void) {
        for (int i = N - 1; i >= 0; i--) {
            t[i] = t[i * 2] + t[i * 2 + 1];
        }
    }

    void update(int pos, int val) {
        pos += N;
        for (t[pos] = val; pos > 1; pos /= 2) {
            t[pos / 2] = t[pos] + t[pos ^ 1];
        }
    }

    int search(int right_cnt) {
        int pos = 1;
        while (pos < N) {
            if (t[pos * 2 + 1] < right_cnt) {
                right_cnt -= t[pos * 2 + 1];
                pos *= 2;
            } else {
                pos = pos * 2 + 1;
            }
        }
        return min(pos - N, N - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    sequ.resize(N);
    int n = 1;
    while (n < N) {
        n *= 2;
    }
    SegTree st(n);
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        inv_seq.push_back(num);
        st.t[i + n] = 1;
    }
    st.build();
    for (int i = N - 1; i >= 0; i--) {
        int idx = st.search(inv_seq[i] + 1);
        sequ[idx] = i + 1;
        st.update(idx, 0);
    }
    cout << sequ[0];
    for (int i = 1; i < N; i++) {
        cout << " " << sequ[i];
    }
    cout << "\n";
    return 0;
}
