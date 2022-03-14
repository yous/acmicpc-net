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
        int sum = 0;
        char str[4097];
        cin.ignore(1);
        while (true) {
            cin.getline(str, sizeof(str));
            for (char ch : str) {
                if (ch == '\0') {
                    break;
                }
                sum += ch - '0';
            }
            if (cin.fail()) {
                cin.clear();
            } else {
                break;
            }
        }
        cout << sum % (B - 1) << "\n";
    }
    return 0;
}
