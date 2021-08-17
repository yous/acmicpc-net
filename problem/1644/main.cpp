#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<bool> sieve(4000001, true);

void gen_primes(int limit) {
    for (int i = 2; i * i <= limit; i++) {
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
    gen_primes(N);
    int lo = 2;
    int hi = 2;
    int sum = lo;
    int cnt = 0;
    while (lo <= hi && hi <= N) {
        if (sum < N) {
            while (sum < N) {
                hi++;
                while (hi <= N && !sieve[hi]) {
                    hi++;
                }
                if (hi > N) {
                    break;
                }
                sum += hi;
            }
        } else if (sum > N) {
            while (sum > N) {
                sum -= lo;
                lo++;
                while (lo <= hi && !sieve[lo]) {
                    lo++;
                }
                if (lo > hi) {
                    break;
                }
            }
        } else {
            cnt++;
            hi++;
            while (hi <= N && !sieve[hi]) {
                hi++;
            }
            if (hi > N) {
                break;
            }
            sum += hi;
        }
    }
    cout << cnt << "\n";
    return 0;
}
