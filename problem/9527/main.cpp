#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long long A, B;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> A >> B;
    long long ans = 0;
    for (int p = 53; p >= 0; p--) {
        long long pow = (1UL << p);
        if (B < pow) {
            continue;
        }
        if ((B >> p) == (A >> p)) {
            if (A & pow) {
                ans += B - A + 1;
            }
            continue;
        }
        if (B & pow) {
            ans += (B & (pow - 1)) + 1;
        }
        if (A & pow) {
            ans += pow - (A & (pow - 1));
        }
        long long lo = (A >> p) + 1;
        long long hi = (B >> p) - 1;
        if (lo > hi) {
            continue;
        }
        if (lo % 2 == 1) {
            ans += pow;
            lo++;
        }
        if (hi % 2 == 0) {
            hi--;
        }
        if (lo <= hi) {
            ans += (hi - lo + 1) / 2 * pow;
        }
    }
    cout << ans << "\n";
    return 0;
}
