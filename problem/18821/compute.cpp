#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int LIMIT = 1e9;
vector<int> primes;

void gen_primes(int limit) {
    for (int n = 2; n <= limit; n++) {
        bool found = true;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                found = false;
                break;
            }
        }
        if (found) {
            primes.push_back(n);
        }
    }
}

bool is_odd(int n) {
    if (n == 1) {
        return false;
    }
    int cnt = 0;
    for (int prime : primes) {
        if (prime * prime > n) {
            break;
        }
        while (n % prime == 0) {
            cnt++;
            n /= prime;
        }
    }
    if (n > 1) {
        cnt++;
    }
    return cnt % 2 == 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    gen_primes(31622);
    int odd = 0;
    int even = 0;
    int n = 1;
    int start = -1;
    while (n <= LIMIT) {
        if (is_odd(n)) {
            even++;
        } else {
            odd++;
        }
        if (n % 10000000 == 0) {
            cout << n / 10000000 << "0,000,000 ...\n";
        }
        if (even < odd) {
            if (start == -1) {
                start = n;
            }
        } else {
            if (start != -1) {
                cout << "E: {" << start << ", " << n - 1 << "}\n";
                start = -1;
            }
        }
        n++;
    }
    if (start != -1) {
        cout << "E: {" << start << ", " << LIMIT << "}\n";
    }
    return 0;
}
