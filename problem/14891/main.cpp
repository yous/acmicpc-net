#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    array<bitset<8>, 4> gears;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            char ch;
            cin >> ch;
            gears[i].set(j, ch == '1');
        }
    }
    short shift[4] = {0, 0, 0, 0};
    short K;
    cin >> K;
    while (K-- > 0) {
        int idx, dir;
        cin >> idx >> dir;
        idx--;
        if (idx > 0) {
            int lo = idx;
            while (lo > 0) {
                if (gears[lo].test((shift[lo] + 6) % 8) == gears[lo - 1].test((shift[lo - 1] + 2) % 8)) {
                    break;
                }
                lo--;
            }
            for (int i = idx - 1; i >= lo; i--) {
                shift[i] = (shift[i] + dir * ((idx - i) % 2 == 1 ? 1 : -1) + 8) % 8;
            }
        }
        if (idx < 3) {
            int hi = idx;
            while (hi < 3) {
                if (gears[hi].test((shift[hi] + 2) % 8) == gears[hi + 1].test((shift[hi + 1] + 6) % 8)) {
                    break;
                }
                hi++;
            }
            for (int i = idx + 1; i <= hi; i++) {
                shift[i] = (shift[i] + dir * ((i - idx) % 2 == 1 ? 1 : -1) + 8) % 8;
            }
        }
        shift[idx] = (shift[idx] - dir + 8) % 8;
    }
    int ans = 0;
    for (int i = 0; i < 4; i++) {
        ans += gears[i][shift[i]] << i;
    }
    cout << ans << "\n";
    return 0;
}
