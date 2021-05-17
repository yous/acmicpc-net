#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int H, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> H >> M;
    M -= 45;
    if (M < 0) {
        M += 60;
        H--;
    }
    if (H < 0) {
        H += 24;
    }
    cout << H << " " << M << "\n";
    return 0;
}
