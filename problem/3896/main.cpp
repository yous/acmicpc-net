#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void gen_sieve(int limit, vector<bool>& sieve, vector<int>& primes) {
    int idx = 0;
    int i;
    for (i = 2; i * i <= limit; i++) {
        if (sieve[i]) {
            primes[idx] = i;
            idx++;
            for (int j = i * i; j <= limit; j += i) {
                sieve[j] = false;
            }
        }
    }
    for (; i <= limit; i++) {
        if (sieve[i]) {
            primes[idx] = i;
            idx++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<bool> sieve(1299710, true);
    vector<int> primes(100001);
    gen_sieve(1299709, sieve, primes);
    int T;
    cin >> T;
    while (T-- > 0) {
        int K;
        cin >> K;
        auto it = lower_bound(primes.begin(), primes.end(), K);
        if (*it == K) {
            cout << "0\n";
        } else {
            cout << *it - *prev(it) << "\n";
        }
    }
    return 0;
}
