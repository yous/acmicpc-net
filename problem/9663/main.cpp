#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;

int solve(int idx, vector<bool>& sel_x, vector<bool>& sel_ypx, vector<bool>& sel_ymx) {
    if (idx == N) {
        return 1;
    }
    int ans = 0;
    for (int x = 0; x < N; x++) {
        if (sel_x[x] || sel_ypx[idx + x] || sel_ymx[idx + N - 1 - x]) {
            continue;
        }
        sel_x[x] = true;
        sel_ypx[idx + x] = true;
        sel_ymx[idx + N - 1 - x] = true;
        ans += solve(idx + 1, sel_x, sel_ypx, sel_ymx);
        sel_x[x] = false;
        sel_ypx[idx + x] = false;
        sel_ymx[idx + N - 1 - x] = false;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    vector<bool> sel_x(N);
    vector<bool> sel_ypx(N * 2 - 1);
    vector<bool> sel_ymx(N * 2 - 1);
    cout << solve(0, sel_x, sel_ypx, sel_ymx) << "\n";
    return 0;
}
