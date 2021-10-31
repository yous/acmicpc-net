#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int X;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> X) {
        if (X == 0) {
            break;
        }
        bool found = false;
        while (!found) {
            int digit = 0;
            int tmp = X;
            while (tmp > 0) {
                digit += (1UL << (tmp % 10 * 3));
                tmp /= 10;
            }
            for (int n = 2; n * n <= X; n++) {
                if (X % n != 0) {
                    continue;
                }
                int new_digit = 0;
                tmp = n;
                while (tmp > 0) {
                    new_digit += (1UL << (tmp % 10 * 3));
                    tmp /= 10;
                }
                tmp = X / n;
                while (tmp > 0) {
                    new_digit += (1UL << (tmp % 10 * 3));
                    tmp /= 10;
                }
                if (digit == new_digit) {
                    found = true;
                    cout << X << "\n";
                    break;
                }
            }
            X++;
        }
    }
    return 0;
}
