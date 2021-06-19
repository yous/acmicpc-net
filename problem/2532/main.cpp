#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> animals;
vector<pair<int, int>> cur_seq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int num, l, r;
        cin >> num >> l >> r;
        animals.emplace_back(l, -r);
    }
    sort(animals.begin(), animals.end());
    for (auto& lr : animals) {
        if (cur_seq.empty() ||
                (-cur_seq.back().first >= -lr.second && cur_seq.back().second < lr.first) ||
                (-cur_seq.back().first > -lr.second && cur_seq.back().second <= lr.first)) {
            cur_seq.emplace_back(lr.second, lr.first);
        } else {
            auto it = lower_bound(cur_seq.begin(), cur_seq.end(), make_pair(lr.second, lr.first));
            it->first = lr.second;
            it->second = lr.first;
        }
    }
    cout << cur_seq.size() << "\n";
    return 0;
}
