#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string prefix;
    cin >> prefix;
    string var;
    while (cin >> var) {
        var.pop_back();
        string res = prefix;
        while (true) {
            char ch = var.back();
            if (ch == '*' || ch == '&') {
                var.pop_back();
                res += ch;
            } else if (ch == ']') {
                var.pop_back();
                var.pop_back();
                res += "[]";
            } else {
                break;
            }
        }
        cout << res << " " << var << ";\n";
    }
    return 0;
}
