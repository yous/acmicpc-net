#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int T;
int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T-- > 0) {
        cin >> N;
        if (N == 1) {
            cout << "E\n";
        } else {
            cout << "O\n";
        }
    }
    return 0;
}
