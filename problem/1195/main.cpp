#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string gear_one, gear_two;
    cin >> gear_one >> gear_two;
    int sz_one = gear_one.size();
    int sz_two = gear_two.size();
    int ans = sz_one + sz_two;
    for (int st = -sz_two + 1; st <= sz_one - 1; st++) {
        bool found = true;
        for (int i = 0; i < sz_two; i++) {
            if (st + i < 0) {
                continue;
            }
            if (st + i >= sz_one) {
                break;
            }
            if (gear_one[st + i] == '2' && gear_two[i] == '2') {
                found = false;
                break;
            }
        }
        if (found) {
            ans = min(ans, max(st + sz_two, sz_one) - min(st, 0));
        }
    }
    cout << ans << "\n";
    return 0;
}
