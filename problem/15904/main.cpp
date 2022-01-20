#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string S;
    getline(cin, S);
    char ucpc[] = "UCPC";
    int idx = 0;
    for (char ch : S) {
        if (ch == ucpc[idx]) {
            idx++;
            if (idx == 4) {
                break;
            }
        }
    }
    if (idx == 4) {
        cout << "I love UCPC\n";
    } else {
        cout << "I hate UCPC\n";
    }
    return 0;
}
