#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int N;
set<int> primes;

void gen_prime(int limit) {
    primes.insert(2);
    for (int n = 3; n <= limit; n += 2) {
        bool found = true;
        for (auto prime : primes) {
            if (prime * prime > n) {
                break;
            }
            if (n % prime == 0) {
                found = false;
                break;
            }
        }
        if (found) {
            primes.insert(n);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    gen_prime(1000);
    int count = 0;
    while (N-- > 0) {
        int num;
        cin >> num;
        if (primes.find(num) != primes.end()) {
            count++;
        }
    }
    cout << count << "\n";
    return 0;
}
