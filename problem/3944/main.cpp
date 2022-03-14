#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short T;
    cin >> T;
    while (T-- > 0) {
        short B;
        cin >> B;
        string D;
        cin >> D;
        int sum = 0;
        for (char ch : D) {
            sum += ch - '0';
        }
        cout << sum % (B - 1) << "\n";
    }
    return 0;
}
