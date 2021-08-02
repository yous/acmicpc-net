#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long long MIN, MAX;
vector<bool> sieve(1000001, true);

void gen_primes(vector<bool>& sieve) {
    int limit = sieve.size() - 1;
    for (int i = 2; i * i <= limit; i++) {
        if (!sieve[i]) {
            continue;
        }
        for (int j = i * i; j <= limit; j += i) {
            sieve[j] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> MIN >> MAX;
    gen_primes(sieve);
    vector<bool> ans(MAX - MIN + 1, true);
    for (long long p = 2; p * p <= MAX; p++) {
        if (!sieve[p]) {
            continue;
        }
        long long sq = p * p;
        for (long long i = (MIN + sq - 1) / sq; i <= MAX / sq; i++) {
            ans[i * sq - MIN] = false;
        }
    }
    int total = 0;
    for (long long i = 0; i < MAX - MIN + 1; i++) {
        if (ans[i]) {
            total++;
        }
    }
    cout << total << "\n";
    return 0;
}
