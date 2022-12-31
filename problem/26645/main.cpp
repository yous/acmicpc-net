#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N;
    cin >> N;
    if (N >= 229) {
        cout << "4\n";
    } else if (N >= 218) {
        cout << "3\n";
    } else if (N >= 206) {
        cout << "2\n";
    } else {
        cout << "1\n";
    }
    return 0;
}
