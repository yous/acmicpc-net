#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1'000'000;
int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    int ans = 0;
    for (int i = 2; i <= N / 2; i++) {
        int cnt = (N / i - 1) % MOD;
        ans = (ans + cnt * i % MOD) % MOD;
    }
    cout << ans << "\n";
    return 0;
}
