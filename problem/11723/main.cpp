#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int M;
set<short> S;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> M;
    string cmd;
    short x;
    while (M-- > 0) {
        cin >> cmd;
        if (cmd == "add") {
            cin >> x;
            S.insert(x);
        } else if (cmd == "remove") {
            cin >> x;
            S.erase(x);
        } else if (cmd == "check") {
            cin >> x;
            cout << (S.find(x) != S.end() ? "1" : "0") << "\n";
        } else if (cmd == "toggle") {
            cin >> x;
            if (S.erase(x) == 0) {
                S.insert(x);
            }
        } else if (cmd == "all") {
            for (int i = 1; i <= 20; i++) {
                S.insert(i);
            }
        } else if (cmd == "empty") {
            S.clear();
        }
    }
    return 0;
}
