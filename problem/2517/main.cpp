#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> skills;
vector<int> ranks;

struct FenwickTree {
    int N;
    vector<int> t;

    FenwickTree(int n) : N(n), t(n + 1) {}

    int sum(int pos) {
        int ans = 0;
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
    cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        skills.emplace_back(num, i);
    }
    sort(skills.begin(), skills.end());
    ranks.resize(N);
    FenwickTree ft(N);
    for (int i = 0; i < N; i++) {
        ranks[skills[i].second] = i;
    }
    for (int i = 0; i < N; i++) {
        ft.update(ranks[i] + 1, 1);
        cout << i + 1 - ft.sum(ranks[i]) << "\n";
    }
    return 0;
}
