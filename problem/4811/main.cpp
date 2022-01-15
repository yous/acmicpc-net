#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> cache(31, vector<long long>(31, -1));

long long solve(int w, int h) {
    if (h < 0) {
        return 0;
    }
    if (w == 0) {
        return 1;
    }
    long long& ans = cache[w][h];
    if (ans >= 0) {
        return ans;
    }
    ans = solve(w - 1, h + 1) + solve(w, h - 1);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (true) {
        int N;
        cin >> N;
        if (N == 0) {
            break;
        }
        cout << solve(N, 0) << "\n";
    }
    return 0;
}
