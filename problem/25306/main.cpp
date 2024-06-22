#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long long solve(long long n) {
    switch (n % 4) {
        case 0:
            return n;
        case 1:
            return 1;
        case 2:
            return n + 1;
        default:
            return 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long A, B;
    cin >> A >> B;
    cout << (solve(B) ^ solve(A - 1)) << "\n";
    return 0;
}
