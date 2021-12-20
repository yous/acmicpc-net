#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    vector<bool> xors(N + 1);
    bool prev_on = false;
    bool on;
    for (int i = 0; i < N; i++) {
        cin >> on;
        xors[i] = prev_on ^ on;
        prev_on = on;
    }
    int ans = 0;
    bool cur = false;
    for (int i = 0; i <= N - K; i++) {
        cur ^= xors[i];
        if (cur == 1) {
            ans++;
            xors[i] = !xors[i];
            xors[i + K] = !xors[i + K];
            cur = false;
        }
    }
    bool off = true;
    for (int i = N - K + 1; i < N; i++) {
        cur ^= xors[i];
        if (cur) {
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
