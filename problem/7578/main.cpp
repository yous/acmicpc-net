#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> machines;

struct SegTree {
    int N;
    vector<int> t;

    SegTree(int n) : N(n), t(N * 2) {}

    void update(int pos, int val) {
        pos += N;
        for (t[pos] = val; pos > 1; pos /= 2) {
            t[pos / 2] = t[pos] + t[pos ^ 1];
        }
    }

    int query(int l, int r) {
        int total = 0;
        for (l += N, r += N; l < r; l /= 2, r /= 2) {
            if (l & 1) {
                total += t[l++];
            }
            if (r & 1) {
                total += t[--r];
            }
        }
        return total;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    SegTree st(N);
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        machines.emplace_back(num, i);
    }
    sort(machines.begin(), machines.end());
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        int idx = lower_bound(machines.begin(), machines.end(), make_pair(num, 0))->second;
        ans += st.query(idx + 1, N);
        st.update(idx, 1);
    }
    cout << ans << "\n";
    return 0;
}
