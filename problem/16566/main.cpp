#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M, K;
vector<int> nums;

struct DisjointSet {
    vector<int> group;

    DisjointSet(int n) : group(n) {
        for (int i = 0; i < n; i++) {
            group[i] = i;
        }
    }

    int find(int n) {
        if (n == group[n]) {
            return n;
        }
        return group[n] = find(group[n]);
    }

    void merge(int p, int q) {
        int gp = find(p);
        int gq = find(q);
        if (gp != gq) {
            group[gp] = gq;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> K;
    DisjointSet ds(N + 1);
    nums.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    int prv = 0;
    for (int i = 0; i < M; i++) {
        int num = nums[i];
        for (int j = prv + 1; j < num; j++) {
            ds.merge(j, num);
        }
        prv = num;
    }
    for (int i = 0; i < K; i++) {
        int num;
        cin >> num;
        int ans = ds.find(num + 1);
        cout << ans << "\n";
        ds.merge(ans, ans + 1);
    }
    return 0;
}
