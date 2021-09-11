#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int A;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> A;
    for (int n = 1; n <= A; n++) {
        if (30 % (n + 1) == 0) {
            cout << n << "\n";
        }
    }
    return 0;
}
