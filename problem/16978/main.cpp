#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct SegTree {
    SegTree* L = nullptr;
    SegTree* R = nullptr;
    int lo, hi;
    long long val;

    SegTree(const SegTree& st) {
        *this = st;
    }

    SegTree(const vector<int>& arr, int lo, int hi) : lo(lo), hi(hi) {
        build(arr, lo, hi);
    }

    SegTree* dup() {
        return new SegTree(*this);
    }

    void build(const vector<int>& arr, int l, int r) {
        if (l == r) {
            val = arr[l];
            return;
        }
        int mid = (lo + hi) / 2;
        L = new SegTree(arr, lo, mid);
        R = new SegTree(arr, mid + 1, hi);
        val = L->val + R->val;
    }

    void update(int l, int r, long long v) {
        if (l <= lo && hi <= r) {
            val = v;
            return;
        }
        if (l <= L->hi) {
            L = L->dup();
            L->update(l, r, v);
        }
        if (R->lo <= r) {
            R = R->dup();
            R->update(l, r, v);
        }
        val = L->val + R->val;
    }

    long long query(int l, int r) {
        if (r < lo || hi < l) {
            return 0;
        }
        if (l <= lo && hi <= r) {
            return val;
        }
        return L->query(l, r) + R->query(l, r);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    vector<int> nums;
    cin >> N;
    nums.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    SegTree st(nums, 0, N - 1);
    vector<SegTree*> trees(1, &st);
    cin >> M;
    for (int i = 0; i < M; i++) {
        int cmd, a, b, c;
        cin >> cmd >> a >> b;
        if (cmd == 1) {
            trees.emplace_back(trees.back()->dup());
            trees.back()->update(a - 1, a - 1, b);
        } else {
            cin >> c;
            cout << trees[a]->query(b - 1, c - 1) << "\n";
        }
    }
    return 0;
}
