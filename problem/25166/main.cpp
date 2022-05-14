#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short S, M;
    cin >> S >> M;
    if (S <= 1023) {
        cout << "No thanks\n";
        return 0;
    }
    short rem = S - 1023;
    while (M > 0) {
        if (rem % 2 == 1 && M % 2 == 0) {
            cout << "Impossible\n";
            return 0;
        }
        rem /= 2;
        M /= 2;
    }
    if (rem > 0) {
        cout << "Impossible\n";
    } else {
        cout << "Thanks\n";
    }
    return 0;
}
