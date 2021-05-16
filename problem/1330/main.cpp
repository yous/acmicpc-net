#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int A, B;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> A >> B;
    if (A > B) {
        cout << ">\n";
    } else if (A < B) {
        cout << "<\n";
    } else {
        cout << "==\n";
    }
    return 0;
}
