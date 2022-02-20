#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<vector<int>>> cache(4, vector<vector<int>>(182, vector<int>((1 << 15) + 1, -1)));

int solve(int cnt, int min_num, int num) {
    if (cnt == -1) {
        return (num == 0);
    }
    if (num == 0) {
        return 1;
    }
    int& ans = cache[cnt][min_num][num];
    if (ans >= 0) {
        return ans;
    }
    ans = 0;
    for (int i = min_num; i * i <= num; i++) {
        ans += solve(cnt - 1, i, num - i * i);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int num;
    while (cin >> num) {
        if (num == 0) {
            break;
        }
        cout << solve(3, 1, num) << "\n";
    }
    return 0;
}
