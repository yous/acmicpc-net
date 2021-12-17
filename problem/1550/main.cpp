#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string hex_num;
    cin >> hex_num;
    int num = 0;
    for (char c : hex_num) {
        if (c <= '9') {
            num = num * 16 + c - '0';
        } else {
            num = num * 16 + c - 'A' + 10;
        }
    }
    cout << num << "\n";
    return 0;
}
