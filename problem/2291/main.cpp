#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M, K;
vector<int> selected;
vector<vector<int>> cache(10, vector<int>(221, -1));

int solve(int pos, int cur_rem) {
    if (cur_rem < 0) {
        return 0;
    }
    if (pos >= N) {
        if (cur_rem == 0) {
            K--;
            if (K == 0) {
                cout << selected[0];
                int sz = selected.size();
                for (int i = 1; i < sz; i++) {
                    cout << " " << selected[i];
                }
                cout << "\n";
                exit(0);
            }
            return 1;
        }
        return 0;
    }
    int& ans = cache[pos][cur_rem];
    if (ans >= 0 && ans < K) {
        K -= ans;
        return ans;
    }
    ans = 0;
    int last_num = selected.empty() ? 1 : selected.back();
    for (int i = 0; i < M; i++) {
        if (i * (N - pos) > cur_rem) {
            break;
        }
        selected.emplace_back(last_num + i);
        ans += solve(pos + 1, cur_rem - i * (N - pos));
        selected.pop_back();
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> K;
    solve(0, M - N);
    return 0;
}
