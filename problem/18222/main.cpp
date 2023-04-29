#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

char solve(bool flipped, long long K) {
    if (K <= 1) {
        return (flipped ? "10"[K] : "01"[K]);
    }
    long long power = 1;
    while (power * 2 <= K) {
        power *= 2;
    }
    return solve(!flipped, K - power);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long K;
    cin >> K;
    K--;
    cout << solve(false, K) << "\n";
    return 0;
}
