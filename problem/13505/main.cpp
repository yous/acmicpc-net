#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> nums;

struct Trie {
    vector<vector<int>> t;
    int current_idx = 1;

    Trie(int N) : t(N * 30, vector<int>(2)) {}

    void insert(int n) {
        int idx = 0;
        for (int p = 29; p >= 0; p--) {
            int pos = (n & (1 << p)) >> p;
            int new_idx = t[idx][pos];
            if (new_idx == 0) {
                t[idx][pos] = current_idx++;
                new_idx = t[idx][pos];
            }
            idx = new_idx;
        }
    }

    int find(int n) {
        int ans = 0;
        int idx = 0;
        for (int p = 29; p >= 0; p--) {
            int pos = (n & (1 << p)) >> p;
            int new_idx = t[idx][pos];
            if (new_idx == 0) {
                pos ^= 1;
                new_idx = t[idx][pos];
            }
            ans += (pos << p);
            idx = new_idx;
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    Trie trie(N);
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
        trie.insert(num);
    }
    int ans = 0;
    for (auto num : nums) {
        ans = max(ans, num ^ trie.find(~num));
    }
    cout << ans << "\n";
    return 0;
}
