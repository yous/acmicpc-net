#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short A, B, C, D;
    cin >> A >> B;
    cin >> C >> D;
    cout << (A + B - 1 + C + D - 1) % 4 + 1 << "\n";
    return 0;
}
