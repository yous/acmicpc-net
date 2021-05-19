#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int a, b, c;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin >> a >> b >> c) {
        if (a == 0 && b == 0 && c == 0) {
            break;
        }
        if (a >= b && a >= c) {
            int tmp = c;
            c = a;
            a = tmp;
        } else if (b >= a && b >= c) {
            int tmp = c;
            c = b;
            b = tmp;
        }
        if (a * a + b * b == c * c) {
            cout << "right\n";
        } else {
            cout << "wrong\n";
        }
    }
    return 0;
}
