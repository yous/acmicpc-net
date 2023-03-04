#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solve(string& A, string& B, int A_sz, int B_sz, int A_idx, int B_idx, vector<vector<int>>& cache) {
    if (A_idx >= A_sz) {
        return B_sz - B_idx;
    }
    if (B_idx >= B_sz) {
        return A_sz - A_idx;
    }
    auto& ans = cache[A_idx][B_idx];
    if (ans >= 0) {
        return ans;
    }
    ans = A_sz - A_idx + B_sz - B_idx;
    if (A[A_idx] == B[B_idx]) {
        ans = min(ans, solve(A, B, A_sz, B_sz, A_idx + 1, B_idx + 1, cache));
    } else {
        ans = min(ans, 1 + solve(A, B, A_sz, B_sz, A_idx + 1, B_idx + 1, cache));
    }
    ans = min(ans, 1 + solve(A, B, A_sz, B_sz, A_idx, B_idx + 1, cache));
    ans = min(ans, 1 + solve(A, B, A_sz, B_sz, A_idx + 1, B_idx, cache));
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string A, B;
    cin >> A >> B;
    auto A_sz = A.size();
    auto B_sz = B.size();
    int A_idx = 0;
    int B_idx = 0;
    vector<vector<int>> cache(A_sz, vector<int>(B_sz, -1));
    cout << solve(A, B, A_sz, B_sz, A_idx, B_idx, cache) << "\n";
    return 0;
}
