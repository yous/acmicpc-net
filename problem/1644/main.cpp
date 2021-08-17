#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<bool> sieve(4000001, true);
vector<int> primes;

void gen_primes(int limit) {
    for (int i = 2; i * i <= limit; i++) {
        if (sieve[i]) {
            for (int j = i * i; j <= limit; j += i) {
                sieve[j] = false;
            }
        }
    }
    for (int i = 2; i <= limit; i++) {
        if (sieve[i]) {
            primes.push_back(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    gen_primes(N);
    int sz = primes.size();
    if (sz == 0) {
        cout << "0\n";
        return 0;
    }
    int lo = 0;
    int hi = 0;
    int sum = primes[lo];
    int cnt = 0;
    while (lo <= hi) {
        while (sum < N) {
            hi++;
            if (hi >= sz) {
                break;
            }
            sum += primes[hi];
        }
        if (hi >= sz) {
            break;
        }
        while (sum > N) {
            sum -= primes[lo];
            lo++;
            if (lo > hi) {
                break;
            }
        }
        if (lo > hi) {
            break;
        }
        if (sum == N) {
            cnt++;
            hi++;
            if (hi >= sz) {
                break;
            }
            sum += primes[hi];
        }
        if (hi >= sz) {
            break;
        }
    }
    cout << cnt << "\n";
    return 0;
}
