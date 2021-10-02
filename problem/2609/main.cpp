#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int A, B;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> A >> B;
    int g = gcd(A, B);
    cout << g << "\n";
    cout << (A / g) * (B / g) * g << "\n";
    return 0;
}
