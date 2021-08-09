#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int M, N;
vector<bool> sieve;

void gen_sieve(int limit) {
    sieve[1] = false;
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
    cin >> M >> N;
    sieve.resize(N + 1, true);
    gen_sieve(N);
    for (int i = M; i <= N; i++) {
        if (sieve[i]) {
            cout << i << "\n";
        }
    }
    return 0;
}
