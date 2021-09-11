#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int A;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> A;
    for (int n = 1; n <= A; n++) {
        vector<bool> grundy(32);
        for (int i = 30; i >= 1; i--) {
            bool can_win = grundy[i];
            for (int j = 1; j <= n && i + j <= 31; j++) {
                can_win |= !grundy[i + j];
            }
            grundy[i] = can_win;
        }
        if (!grundy[1]) {
            cout << n << "\n";
        }
    }
    return 0;
}
