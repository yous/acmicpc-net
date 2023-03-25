#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

short N;

short solve(int idx, vector<short>& A, vector<short>& cache) {
    if (idx >= N) {
        return 0;
    }
    auto& ans = cache[idx];
    if (ans >= 0) {
        return ans;
    }
    ans = 1;
    for (int i = idx + 1; i < N; i++) {
        if (A[idx] > A[i]) {
            ans = max(ans, short(1 + solve(i, A, cache)));
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    vector<short> A(N);
    for (auto& num : A) {
        cin >> num;
    }
    vector<short> cache(N, -1);
    short ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, solve(i, A, cache));
    }
    cout << ans << "\n";
    return 0;
}
