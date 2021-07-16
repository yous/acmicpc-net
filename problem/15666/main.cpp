#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int N, M;
set<short> nums;

void solve(set<short>::iterator it, vector<short>& selected) {
    int cnt = selected.size();
    if (cnt == M) {
        cout << selected[0];
        for (int i = 1; i < M; i++) {
            cout << " " << selected[i];
        }
        cout << "\n";
        return;
    }
    if (it == nums.end()) {
        return;
    }
    auto next_it = next(it);
    short num = *it;
    for (int i = 0; i < N - cnt; i++) {
        selected.push_back(num);
    }
    solve(next_it, selected);
    for (int i = 0; i < N - cnt; i++) {
        selected.pop_back();
        solve(next_it, selected);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        short num;
        cin >> num;
        nums.insert(num);
    }
    vector<short> selected;
    solve(nums.begin(), selected);
    return 0;
}
