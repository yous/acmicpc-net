#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int P, A;
vector<bool> sieve(31624, true);

void gen_sieve(int limit) {
    sieve[1] = false;
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
    gen_sieve(31623);
    while (cin >> P >> A) {
        if (P == 0 && A == 0) {
            break;
        }
        bool is_prime = true;
        for (int i = 2; i * i <= P; i++) {
            if (sieve[i] && P % i == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            cout << "no\n";
        } else {
            int res = 1;
            int mul = A;
            int cnt = P;
            while (cnt > 0) {
                if (cnt % 2 == 1) {
                    res = 1LL * res * mul % P;
                    cnt--;
                } else {
                    mul = 1LL * mul * mul % P;
                    cnt /= 2;
                }
            }
            if (res == A) {
                cout << "yes\n";
            } else {
                cout << "no\n";
            }
        }
    }
    return 0;
}
