#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<bool> sieve(31623, true);
    for (int i = 2; i * i <= 31622; i++) {
        if (sieve[i]) {
            for (int j = i; j <= 31622; j += i) {
                sieve[j] = false;
            }
        }
    }
    int N;
    cin >> N;
    long long ans = 0;
    int i;
    for (i = 1; i * i <= N; i++) {
        ans += N / i;
    }
    ans = ans * 2 - (i - 1) * (i - 1);
    int divisor_cnt = 1;
    int num = N;
    for (int i = 2; i <= 31622; i++) {
        if (num % i == 0) {
            int cnt = 1;
            num /= i;
            while (num % i == 0) {
                cnt++;
                num /= i;
            }
            divisor_cnt *= cnt + 1;
        }
    }
    if (num > 1) {
        divisor_cnt *= 2;
    }
    ans += N - divisor_cnt;
    cout << ans << "\n";
    return 0;
}
