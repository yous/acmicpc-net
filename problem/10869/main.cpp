#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int A, B;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> A >> B;
    cout << A + B << "\n";
    cout << A - B << "\n";
    cout << A * B << "\n";
    cout << A / B << "\n";
    cout << A % B << "\n";
    return 0;
}
