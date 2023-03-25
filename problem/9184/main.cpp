#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

int solve(short A, short B, short C, vector<vector<vector<int>>>& cache) {
    if (A <= 0 || B <= 0 || C <= 0) {
        return 1;
    }
    if (A > 20 || B > 20 || C > 20) {
        return solve(20, 20, 20, cache);
    }
    auto& ans = cache[A][B][C];
    if (ans != INF) {
        return ans;
    }
    if (A < B && B < C) {
        ans = solve(A, B, C - 1, cache) + solve(A, B - 1, C - 1, cache) - solve(A, B - 1, C, cache);
    } else {
        ans = solve(A - 1, B, C, cache) + solve(A - 1, B - 1, C, cache) + solve(A - 1, B, C - 1, cache) - solve(A - 1, B - 1, C - 1, cache);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short A, B, C;
    vector<vector<vector<int>>> cache(21, vector<vector<int>>(21, vector<int>(21, INF)));
    while (cin >> A >> B >> C) {
        if (A == -1 && B == -1 && C == -1) {
            break;
        }
        cout << "w(" << A << ", " << B << ", " << C << ") = " << solve(A, B, C, cache) << "\n";
    }
    return 0;
}
