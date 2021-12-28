#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int a, b;
        cin >> a >> b;
        cout << "Case " << t << ": " << a + b << "\n";
    }
    return 0;
}
