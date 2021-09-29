#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long long N;
vector<bool> sieve(1'000'001, true);
vector<long long> primes;
int sz;
long long ans;

void run_sieve(long long limit) {
    for (int i = 2; 1LL * i * i <= limit; i++) {
        if (sieve[i]) {
            for (int j = i * i; j <= limit; j += i) {
                sieve[j] = false;
            }
        }
    }
}

void combi(int idx, int remain, long long cur_num) {
    if (remain == 0) {
        ans += cur_num;
        return;
    }
    if (idx >= sz) {
        return;
    }
    combi(idx + 1, remain - 1, cur_num / primes[idx]);
    combi(idx + 1, remain, cur_num);
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
            primes.emplace_back(p);
            tmp /= p;
            while (tmp % p == 0) {
                tmp /= p;
            }
            ans -= N / p;
        }
    }
    if (tmp > 1) {
        primes.emplace_back(tmp);
        ans -= N / tmp;
    }
    sz = primes.size();
    for (int i = 2; i <= sz; i++) {
        combi(0, i, (i % 2 == 0 ? N : -N));
    }
    cout << ans << "\n";
    return 0;
}
