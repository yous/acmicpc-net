#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> nums;

struct FenwickTree {
    int N;
    vector<long long> t;

    FenwickTree(int n) : N(n), t(n + 1) {}

    long long sum(int pos) {
        long long ans = 0;
        while (pos >= 1) {
            ans += t[pos];
            pos -= pos & -pos;
        }
        return ans;
    }

    void update(int pos, int val) {
        while (pos <= N) {
            t[pos] += val;
            pos += pos & -pos;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    nums.resize(N);
    FenwickTree ft(N);
    for (int i = 0; i < M; i++) {
        int cmd, a, b;
        cin >> cmd >> a >> b;
        if (cmd == 0) {
            if (a > b) {
                swap(a, b);
            }
            cout << ft.sum(b) - ft.sum(a - 1) << "\n";
        } else if (cmd == 1) {
            int diff = b - nums[a - 1];
            nums[a - 1] = b;
            ft.update(a, diff);
        }
    }
    return 0;
}
