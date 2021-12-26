#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string S;
    while (cin >> S) {
        if (S[0] == '#') {
            break;
        }
        bool mirror = true;
        string ans;
        int sz = S.size();
        ans.resize(sz);
        for (int i = sz - 1; i >= 0; i--) {
            char ch = S[i];
            switch (ch) {
                case 'b':
                    ans[sz - i - 1] = 'd';
                    break;
                case 'd':
                    ans[sz - i - 1] = 'b';
                    break;
                case 'p':
                    ans[sz - i - 1] = 'q';
                    break;
                case 'q':
                    ans[sz - i - 1] = 'p';
                    break;
                case 'i':
                case 'o':
                case 'v':
                case 'w':
                case 'x':
                    ans[sz - i - 1] = ch;
                    break;
                default:
                    mirror = false;
                    break;
            }
            if (!mirror) {
                break;
            }
        }
        if (mirror) {
            cout << ans << "\n";
        } else {
            cout << "INVALID\n";
        }
    }
    return 0;
}
