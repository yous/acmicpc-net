#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;
vector<char> STEPS;
int SZ;
vector<int> cache[5][5];
const int dist[5][4] = {
    {2, 2, 2, 2},
    {1, 3, 4, 3},
    {3, 1, 3, 4},
    {4, 3, 1, 3},
    {3, 4, 3, 1}
};

int solve(int idx, int l, int r) {
    if (idx >= SZ) {
        return 0;
    }
    int& ans = cache[l][r][idx];
    if (ans < INF) {
        return ans;
    }
    int step = STEPS[idx];
    if (l == step) {
        ans = 1 + solve(idx + 1, l, r);
        return ans;
    } else if (r == step) {
        ans = 1 + solve(idx + 1, l, r);
        return ans;
    }
    ans = min({ans, dist[l][step - 1] + solve(idx + 1, step, r), dist[r][step - 1] + solve(idx + 1, l, step)});
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    char ch;
    while (cin >> ch) {
        if (ch == '0') {
            break;
        }
        STEPS.push_back(ch - '0');
    }
    SZ = STEPS.size();
    for (int l = 0; l < 5; l++) {
        for (int r = 0; r < 5; r++) {
            cache[l][r].resize(SZ, INF);
        }
    }
    cout << solve(0, 0, 0) << "\n";
    return 0;
}
