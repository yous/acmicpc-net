#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    unsigned int X, K;
    cin >> X >> K;
    long long Y = 0;
    long long cur_bit = 1;
    while (K > 0) {
        if ((X & 1) == 0) {
            if ((K & 1) == 1) {
                Y += cur_bit;
            }
            K /= 2;
        }
        X /= 2;
        cur_bit *= 2;
    }
    cout << Y << "\n";
    return 0;
}
