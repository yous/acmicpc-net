#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    vector<bool> dolls(N);
    for (int i = 0; i < N; i++) {
        short num;
        cin >> num;
        dolls[i] = (num == 1);
    }
    int lo = 0;
    int hi = 0;
    int cnt = 0;
    while (hi < N && cnt < K) {
        if (dolls[hi]) {
            cnt++;
        }
        hi++;
    }
    if (cnt < K) {
        cout << "-1\n";
        return 0;
    }
    int ans = hi - lo;
    while (hi < N) {
        if (dolls[hi]) {
            cnt++;
        }
        hi++;
        while (lo < hi && cnt >= K) {
            if (dolls[lo]) {
                cnt--;
            }
            lo++;
        }
        ans = min(ans, hi - lo + 1);
    }
    cout << ans << "\n";
    return 0;
}
