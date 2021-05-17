#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int T;
int R;
string S;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while (T-- > 0) {
        cin >> R >> S;
        for (char c : S) {
            for (int i = 0; i < R; i++) {
                cout << c;
            }
        }
        cout << "\n";
    }
    return 0;
}
