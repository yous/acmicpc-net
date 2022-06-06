#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int A, B;
    cin >> A >> B;
    cout << (A - A * B / 100.0 >= 100 ? 0 : 1) << "\n";
    return 0;
}
