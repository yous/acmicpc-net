#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M, K;
vector<int> selected;
vector<vector<vector<int>>> cache(10, vector<vector<int>>(221, vector<int>(221, -1)));

int solve(int pos, int cur_num, int cur_sum) {
    if (pos >= N) {
        if (cur_sum == M) {
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
    int& ans = cache[pos][cur_num][cur_sum];
    if (ans >= 0 && ans < K) {
        K -= ans;
        return ans;
    }
    ans = 0;
    for (int i = cur_num; i <= M; i++) {
        if (cur_sum + i * (N - pos - 1) > M) {
            break;
        }
        selected.emplace_back(i);
        ans += solve(pos + 1, i, cur_sum + i);
        selected.pop_back();
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> K;
    solve(0, 1, 0);
    return 0;
}
