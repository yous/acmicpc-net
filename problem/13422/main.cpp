#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T-- > 0) {
        int N, M, K;
        cin >> N >> M >> K;
        vector<int> houses(N);
        for (auto& num : houses) {
            cin >> num;
        }
        int ans = 0;
        int sum = 0;
        for (int i = 0; i < M; i++) {
            sum += houses[i];
        }
        if (sum < K) {
            ans++;
        }
        if (N == M) {
            cout << ans << "\n";
            continue;
        }
        for (int i = M; i < N; i++) {
            sum = sum - houses[i - M] + houses[i];
            if (sum < K) {
                ans++;
            }
        }
        for (int i = 0; i < M - 1; i++) {
            sum = sum - houses[N - (M - i)] + houses[i];
            if (sum < K) {
                ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
