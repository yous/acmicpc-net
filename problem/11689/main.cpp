#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long long N;
vector<bool> sieve(1'000'001, true);
long long ans;

void run_sieve(long long limit) {
    sieve.resize(limit + 1, true);
    for (int i = 2; 1LL * i * i <= limit; i++) {
        if (sieve[i]) {
            for (int j = i * i; j <= limit; j += i) {
                sieve[j] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    run_sieve(1'000'000);
    ans = N;
    long long tmp = N;
    for (int p = 2; 1LL * p * p <= tmp; p++) {
        if (!sieve[p]) {
            continue;
        }
        if (tmp % p == 0) {
            tmp /= p;
            while (tmp % p == 0) {
                tmp /= p;
            }
            ans = ans / p * (p - 1);
        }
    }
    if (tmp > 1) {
        ans = ans / tmp * (tmp - 1);
    }
    cout << ans << "\n";
    return 0;
}
