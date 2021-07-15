#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int N, M;
map<short, short> nums;

void solve(vector<short>& selected) {
    int cnt = selected.size();
    if (cnt == M) {
        cout << selected[0];
        for (int i = 1; i < M; i++) {
            cout << " " << selected[i];
        }
        cout << "\n";
        return;
    }
    for (auto it = nums.begin(); it != nums.end(); ++it) {
        if (it->second > 0) {
            it->second--;
            selected.push_back(it->first);
            solve(selected);
            selected.pop_back();
            it->second++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        short num;
        cin >> num;
        nums[num]++;
    }
    vector<short> selected;
    solve(selected);
    return 0;
}
