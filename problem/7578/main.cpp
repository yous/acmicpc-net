#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
int machines[1000001];

struct FenwickTree {
    int N;
    vector<int> t;

    FenwickTree(int n) : N(n), t(n + 1) {}

    int sum(int pos) {
        int ans = 0;
        while (pos >= 1) {
            ans += t[pos];
            pos -= (pos & -pos);
        }
        return ans;
    }

    void update(int pos, int val) {
        while (pos <= N) {
            t[pos] += val;
            pos += (pos & -pos);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    FenwickTree ft(N);
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        machines[num] = i;
    }
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        int idx = machines[num];
        ans += ft.sum(N - (idx + 1));
        ft.update(N - idx, 1);
    }
    cout << ans << "\n";
    return 0;
}
