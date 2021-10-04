#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<bool> sieve(1'000'001, true);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    if (N <= 7) {
        cout << "-1\n";
        return 0;
    }
    sieve[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (!sieve[i]) {
            continue;
        }
        for (int j = i * i; j <= N; j += i) {
            sieve[j] = false;
        }
    }
    if (N % 2 == 0) {
        int lo = N / 2;
        if (lo % 2 == 1) {
            lo--;
        }
        int hi = N - lo;
        for (int i = lo / 2; i >= 2; i--) {
            if (sieve[i] && sieve[lo - i]) {
                cout << i << " " << lo - i << " ";
                break;
            }
        }
        for (int i = hi / 2; i >= 2; i--) {
            if (sieve[i] && sieve[hi - i]) {
                cout << i << " " << hi - i << "\n";
                break;
            }
        }
    } else {
        cout << "2 3 ";
        for (int i = (N - 5) / 2; i >= 2; i--) {
            if (sieve[i] && sieve[N - 5 - i]) {
                cout << i << " " << N - 5 - i << "\n";
                break;
            }
        }
    }
    return 0;
}
