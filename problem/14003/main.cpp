#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> nums;
vector<pair<int, int>> cur_seq;
vector<int> seq_indices;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    int max_idx = -1;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
        if (cur_seq.empty() || cur_seq.back().first < num) {
            if (cur_seq.empty()) {
                seq_indices.push_back(-1);
            } else {
                seq_indices.push_back(cur_seq.back().second);
            }
            cur_seq.emplace_back(num, i);
            max_idx = i;
        } else {
            auto it = lower_bound(cur_seq.begin(), cur_seq.end(), make_pair(num, 0));
            if (it == cur_seq.begin()) {
                seq_indices.push_back(-1);
            } else {
                seq_indices.push_back(prev(it)->second);
            }
            it->first = num;
            it->second = i;
        }
    }
    int sz = cur_seq.size();
    cout << sz << "\n";
    int idx = max_idx;
    int num = nums[idx];
    int seq_idx = sz - 1;
    while (idx != -1) {
        cur_seq[seq_idx].first = num;
        idx = seq_indices[idx];
        num = nums[idx];
        seq_idx--;
    }
    for (int i = 0; i < sz; i++) {
        cout << cur_seq[i].first;
        if (i < sz - 1) {
            cout << " ";
        } else {
            cout << "\n";
        }
    }
    return 0;
}
