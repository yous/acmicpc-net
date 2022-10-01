#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (auto& num : A) {
        cin >> num;
    }
    sort(A.begin(), A.end());
    int lo = 0;
    int hi = 0;
    while (hi < N - 1 && A[hi] - A[lo] < M) {
        hi++;
    }
    int ans = A[hi] - A[lo];
    while (hi < N) {
        while (lo <= hi && A[hi] - A[lo] >= M) {
            lo++;
        }
        ans = min(ans, A[hi] - A[lo - 1]);
        hi++;
    }
    cout << ans << "\n";
    return 0;
}
