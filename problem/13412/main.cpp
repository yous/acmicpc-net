#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int T, N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T-- > 0) {
        cin >> N;
        int ans = 0;
        for (int i = 1; i * i <= N; i++) {
            if (N % i == 0 && gcd(i, N / i) == 1) {
                ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
