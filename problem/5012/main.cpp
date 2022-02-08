#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
struct SegTree {
    int N;
    vector<T> t;

    SegTree<T>(int n) : N(n), t(n * 2) {}

    void build(void) {
        for (int pos = N - 1; pos >= 1; pos--) {
            t[pos] = t[pos * 2] + t[pos * 2 + 1];
        }
    }

    void update(int pos, T val) {
        pos += N;
        for (t[pos] += val; pos > 1; pos /= 2) {
            t[pos / 2] = t[pos] + t[pos ^ 1];
        }
    }

    T query(int l, int r) {
        T ans = 0;
        for (l += N, r += N; l < r; l /= 2, r /= 2) {
            if (l & 1) {
                ans += t[l++];
            }
            if (r & 1) {
                ans += t[--r];
            }
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> nums(N);
    for (int& num : nums) {
        cin >> num;
    }
    vector<int> smaller(N);
    SegTree<int> st(N);
    SegTree<long long> ans_st(N);
    long long ans = 0;
    for (int i = N - 1; i >= 0; i--) {
        ans += ans_st.query(0, nums[i] - 1);
        smaller[i] = st.query(0, nums[i] - 1);
        ans_st.update(nums[i] - 1, smaller[i]);
        st.update(nums[i] - 1, 1);
    }
    cout << ans << "\n";
    return 0;
}
