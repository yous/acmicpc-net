#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<bool> sieve;

void gen_sieve(int limit) {
    sieve.resize(limit + 1, true);
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
    int T;
    cin >> T;
    gen_sieve(1000000);
    while (T-- > 0) {
        int N;
        cin >> N;
        int ans = 0;
        for (int i = 2; i <= N / 2; i++) {
            if (sieve[i] && sieve[N - i]) {
                ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
