#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> lines;
vector<pair<int, int>> cur_seq;
vector<int> seq_indices;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    seq_indices.resize(N);
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        lines.emplace_back(a, b);
    }
    sort(lines.begin(), lines.end());
    for (int i = 0; i < N; i++) {
        int b = lines[i].second;
        auto it = lower_bound(cur_seq.begin(), cur_seq.end(), make_pair(b, 0));
        if (it == cur_seq.end()) {
            if (cur_seq.empty()) {
                seq_indices[i] = -1;
            } else {
                seq_indices[i] = prev(it)->second;
            }
            cur_seq.emplace(it, b, i);
        } else {
            if (it == cur_seq.begin()) {
                seq_indices[i] = -1;
            } else {
                seq_indices[i] = prev(it)->second;
            }
            it->first = b;
            it->second = i;
        }
    }
    int sz = cur_seq.size();
    cout << N - sz << "\n";
    int idx = cur_seq.back().second;
    int seq_idx = sz - 1;
    while (idx != -1) {
        int a = lines[idx].first;
        cur_seq[seq_idx].first = a;
        idx = seq_indices[idx];
        seq_idx--;
    }
    seq_idx = 0;
    for (auto& p : lines) {
        int a = p.first;
        while (seq_idx < sz && cur_seq[seq_idx].first < a) {
            seq_idx++;
        }
        if (seq_idx >= sz || cur_seq[seq_idx].first > a) {
            cout << a << "\n";
        }
    }
    return 0;
}
