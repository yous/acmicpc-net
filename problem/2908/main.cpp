#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int A, B;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> A >> B;
    A = (A % 10) * 100 + (A / 10) % 10 * 10 + A / 100;
    B = (B % 10) * 100 + (B / 10) % 10 * 10 + B / 100;
    if (A > B) {
        cout << A << "\n";
    } else {
        cout << B << "\n";
    }
    return 0;
}
