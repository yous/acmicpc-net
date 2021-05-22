#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int A, B, V;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> A >> B >> V;
    if (A >= V) {
        cout << "1\n";
    } else {
        cout << 1 + (V - B - 1) / (A - B) << "\n";
    }
    return 0;
}
