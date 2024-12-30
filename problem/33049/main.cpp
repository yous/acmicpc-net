#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int P3, P4, P0;
    cin >> P3 >> P4 >> P0;
    int P3_rem = (3 - P3 % 3) % 3;
    int P4_rem = (4 - P4 % 4) % 4;
    if (P3_rem + P4_rem > P0) {
        cout << "-1\n";
        return 0;
    }
    P0 -= P3_rem + P4_rem;
    int T3 = (P3 + P3_rem) / 3;
    int T4 = (P4 + P4_rem) / 4;
    if (P0 == 0) {
        cout << T3 << " " << T4 << "\n";
        return 0;
    }
    if (P0 < 3 || P0 == 5) {
        cout << "-1\n";
        return 0;
    }
    switch (P0 % 4) {
        case 0:
            T4 += P0 / 4;
            break;
        case 1:
            T3 += 3;
            T4 += P0 / 4 - 2;
            break;
        case 2:
            T3 += 2;
            T4 += P0 / 4 - 1;
            break;
        case 3:
            T3 += 1;
            T4 += P0 / 4;
            break;
    }
    cout << T3 << " " << T4 << "\n";
    return 0;
}
