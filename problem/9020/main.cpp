#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int T, N;
vector<bool> sieve(10001, true);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    sieve[1] = false;
    for (int i = 2; i * i <= 10000; i++) {
        if (!sieve[i]) {
            continue;
        }
        for (int j = i * i; j <= 10000; j += i) {
            sieve[j] = false;
        }
    }
    while (T-- > 0) {
        cin >> N;
        for (int i = N / 2; i >= 2; i--) {
            if (sieve[i] && sieve[N - i]) {
                cout << i << " " << N - i << "\n";
                break;
            }
        }
    }
    return 0;
}
