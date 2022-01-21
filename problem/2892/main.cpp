#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string hexa;
        cin >> hexa;
        if ((stoi(hexa, NULL, 16) & 0b1000000) != 0) {
            cout << '-';
        } else {
            cout << '.';
        }
    }
    cout << "\n";
    return 0;
}
