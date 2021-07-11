#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<short> nums;

void solve(int idx, vector<short>& ans, vector<bool>& selected) {
    int cnt = ans.size();
    if (cnt == M) {
        cout << ans[0];
        for (int i = 1; i < M; i++) {
            cout << " " << ans[i];
        }
        cout << "\n";
        return;
    }
    if (idx == N) {
        return;
    }
    for (int i = 0; i < N; i++) {
        if (!selected[i]) {
            ans.push_back(nums[i]);
            selected[i] = true;
            solve(idx + 1, ans, selected);
            ans.pop_back();
            selected[i] = false;
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
        nums.push_back(num);
    }
    sort(nums.begin(), nums.end());
    vector<short> ans;
    vector<bool> selected(N);
    solve(0, ans, selected);
    return 0;
}
