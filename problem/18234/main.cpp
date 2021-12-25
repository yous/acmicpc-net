#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, T;
    cin >> N >> T;
    long long ans = 0;
    vector<int> supplements(N);
    for (int i = 0; i < N; i++) {
        int w, p;
        cin >> w >> p;
        ans += w;
        supplements[i] = p;
    }
    sort(supplements.begin(), supplements.end());
    for (int i = N - 1; i >= 0; i--) {
        ans += 1LL * supplements[i] * (T - (N - i));
    }
    cout << ans << "\n";
    return 0;
}
