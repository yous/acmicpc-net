#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
long long M;
vector<int> primes;
long long ans = 0;

void solve(int idx, int cnt, long long mul) {
    if (mul > M) {
        return;
    }
    if (cnt == N) {
        ans += (M / mul) * (cnt % 2 == 1 ? 1 : -1);
        return;
    }
    if (idx == N) {
        if (cnt > 0) {
            ans += (M / mul) * (cnt % 2 == 1 ? 1 : -1);
        }
        return;
    }
    solve(idx + 1, cnt + 1, mul * primes[idx]);
    solve(idx + 1, cnt, mul);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    primes.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> primes[i];
    }
    solve(0, 0, 1);
    cout << ans << "\n";
    return 0;
}
