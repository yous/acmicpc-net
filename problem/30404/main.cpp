#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    int last_time = -1;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int X;
        cin >> X;
        if (last_time < X) {
            last_time = X + K;
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
