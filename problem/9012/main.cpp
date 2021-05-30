#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int T;

bool is_vps(string& s) {
    int open_cnt = 0;
    for (char ch : s) {
        switch (ch) {
            case '(':
                open_cnt++;
                break;
            case ')':
                if (open_cnt == 0) {
                    return false;
                }
                open_cnt--;
                break;
        }
    }
    return open_cnt == 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T-- > 0) {
        string s;
        cin >> s;
        if (is_vps(s)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
