#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    vector<short> bulbs(N);
    for (short& on : bulbs) {
        cin >> on;
    }
    vector<short> xors(N + 1);
    xors[0] = bulbs[0];
    for (int i = 1; i < N; i++) {
        xors[i] = bulbs[i] ^ bulbs[i - 1];
    }
    int ans = 0;
    short cur = 0;
    for (int i = 0; i <= N - K; i++) {
        cur ^= xors[i];
        if (cur == 1) {
            ans++;
            xors[i] ^= 1;
            xors[i + K] ^= 1;
            cur = 0;
        }
    }
    bool off = true;
    for (int i = N - K + 1; i < N; i++) {
        cur ^= xors[i];
        if (cur == 1) {
            off = false;
            break;
        }
    }
    if (off) {
        cout << ans << "\n";
    } else {
        cout << "Insomnia\n";
    }
    return 0;
}
