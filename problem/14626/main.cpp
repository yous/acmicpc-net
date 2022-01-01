#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string ISBN;
    cin >> ISBN;
    int val = 0;
    int rem_mul = 1;
    for (int i = 0; i < 13; i++) {
        if (ISBN[i] == '*') {
            rem_mul = (i % 2 == 0 ? 1 : 3);
        } else {
            val += (ISBN[i] - '0') * (i % 2 == 0 ? 1 : 3);
        }
    }
    for (int i = 0; i < 10; i++) {
        if ((val + i * rem_mul) % 10 == 0) {
            cout << i << "\n";
            break;
        }
    }
    return 0;
}
