#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const long long MOD = (1LL << 32);
int N;
vector<bool> sieve;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    sieve.resize(N + 1, true);
    sieve[1] = false;
    long long ans = 1;
    for (int i = 2; i * i <= N; i++) {
        if (!sieve[i]) {
            continue;
        }
        for (int j = i * i; j <= N; j += i) {
            sieve[j] = false;
        }
    }
    for (int i = 2; i <= N; i++) {
        if (sieve[i]) {
            long long cur = i;
            while (cur * i <= N) {
                cur *= i;
            }
            ans = ans * cur % MOD;
        }
    }
    cout << ans << "\n";
    return 0;
}
