#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int M, N;
vector<int> primes;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> M >> N;
    primes.push_back(2);
    if (M <= 2 && N >= 2) {
        cout << "2\n";
    }
    if (M % 2 == 0) {
        M++;
    }
    for (int i = 3; i <= N; i += 2) {
        bool is_prime = true;
        for (int prime : primes) {
            if (prime * prime > i) {
                break;
            }
            if (i % prime == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            primes.push_back(i);
            if (i >= M) {
                cout << i << "\n";
            }
        }
    }
    return 0;
}
