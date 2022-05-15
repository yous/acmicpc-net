#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, K;
    cin >> N >> M >> K;
    if (K - 3 < 0) {
        K += (abs(K - 3) + N - 1) / N * N;
    }
    cout << (M - 1 + K - 3) % N + 1 << "\n";
    return 0;
}
