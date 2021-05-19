#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int T;
int A, B;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while (T-- > 0) {
        cin >> A >> B;
        cout << A + B << "\n";
    }
    return 0;
}
