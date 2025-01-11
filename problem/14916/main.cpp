#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    int ans = N / 5;
    switch (N % 5) {
        case 0:
            break;
        case 1:
            if (ans >= 1) {
                ans = ans - 1 + 3;
            } else {
                ans = -1;
            }
            break;
        case 2:
            ans++;
            break;
        case 3:
            if (ans >= 1) {
                ans = ans - 1 + 4;
            } else {
                ans = -1;
            }
            break;
        case 4:
            ans += 2;
            break;
    }
    cout << ans << "\n";
    return 0;
}
