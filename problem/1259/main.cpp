#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int num;
    while (cin >> num) {
        if (num == 0) {
            break;
        }
        string s = to_string(num);
        int size = s.size();
        bool end = false;
        for (int i = 0; i < size / 2; i++) {
            if (s[i] != s[size - 1 - i]) {
                cout << "no\n";
                end = true;
                break;
            }
        }
        if (!end) {
            cout << "yes\n";
        }
    }
    return 0;
}
