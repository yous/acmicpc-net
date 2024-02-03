#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int X, Y;
    cin >> X >> Y;
    while (X > 0 || Y > 0) {
        if ((X % 3 == 1 && Y % 3 == 0) || (X % 3 == 0 && Y % 3 == 1)) {
            X /= 3;
            Y /= 3;
        } else {
            cout << "0\n";
            return 0;
        }
    }
    cout << "1\n";
    return 0;
}
