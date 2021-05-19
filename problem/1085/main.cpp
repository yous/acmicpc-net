#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int x, y, w, h;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> x >> y >> w >> h;
    cout << min({w - x, x, h - y, y}) << "\n";
    return 0;
}
