#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<short> nums;

void solve(int idx, vector<short>& ans) {
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
    ans.push_back(nums[idx]);
    solve(idx, ans);
    ans.pop_back();
    solve(idx + 1, ans);
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
    solve(0, ans);
    return 0;
}
