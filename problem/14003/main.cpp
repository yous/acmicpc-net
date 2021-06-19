#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> cur_seq;
vector<vector<pair<int, int>>> num_list;
vector<int> ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        if (cur_seq.empty() || cur_seq.back() < num) {
            cur_seq.push_back(num);
            num_list.emplace_back();
            num_list.back().emplace_back(num, i);
        } else {
            auto it = lower_bound(cur_seq.begin(), cur_seq.end(), num);
            *it = num;
            num_list[it - cur_seq.begin()].emplace_back(num, i);
        }
    }
    int sz = cur_seq.size();
    cout << sz << "\n";
    auto p = num_list[sz - 1].back();
    ans.push_back(p.first);
    int num_idx = p.second;
    for (int i = sz - 2; i >= 0; i--) {
        auto& nums = num_list[i];
        for (auto it = nums.rbegin(); it != nums.rend(); ++it) {
            if (it->second < num_idx) {
                num_idx = it->second;
                ans.push_back(it->first);
                break;
            }
        }
    }
    for (int i = sz - 1; i >= 0; i--) {
        cout << ans[i];
        if (i > 0) {
            cout << " ";
        } else {
            cout << "\n";
        }
    }
    return 0;
}
