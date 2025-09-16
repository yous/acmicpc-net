#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    long long K;
    cin >> N >> K;
    long long pairs = 0;
    int even_count = 0;
    for (int i = 0; i < N; i++) {
        long long num;
        cin >> num;
        if (num % 2 == 0) {
            even_count++;
        }
        pairs += (num - 1) / 2;
    }
    if (pairs + even_count < K) {
        cout << "-1\n";
        return 0;
    }
    if (K == 0) {
        cout << "0\n";
        return 0;
    }
    if (pairs >= K) {
        cout << N + 1 + (K - 1) * 2 << "\n";
    } else {
        cout << N + 1 + pairs * 2 + (K - pairs - 1) << "\n";
    }
    return 0;
}
