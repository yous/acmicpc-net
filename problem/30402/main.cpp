#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    bool found = false;
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            char ch;
            cin >> ch;
            if (!found) {
                if (ch == 'w') {
                    found = true;
                    cout << "chunbae\n";
                } else if (ch == 'b') {
                    found = true;
                    cout << "nabi\n";
                } else if (ch == 'g') {
                    found = true;
                    cout << "yeongcheol\n";
                }
            }
        }
    }
    return 0;
}
