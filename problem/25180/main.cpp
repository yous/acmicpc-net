#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    int ans = (N + 8) / 9;
    if (ans % 2 == 0) {
        if (N % 2 == 1) {
            cout << ans + 1 << "\n";
        } else {
            cout << ans << "\n";
        }
    } else {
        cout << ans << "\n";
    }
    return 0;
}
