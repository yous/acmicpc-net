#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int T;
int N;
int ans;

void solve(int sum) {
    if (sum > N) {
        return;
    }
    if (sum == N) {
        ans++;
        return;
    }
    solve(sum + 1);
    solve(sum + 2);
    solve(sum + 3);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T-- > 0) {
        cin >> N;
        ans = 0;
        solve(0);
        cout << ans << "\n";
    }
    return 0;
}
