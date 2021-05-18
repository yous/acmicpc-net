#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int node[8];
bool asc = true;
bool desc = true;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> node[0];
    for (int i = 1; i < 8; i++) {
        cin >> node[i];
        if (node[i] > node[i - 1]) {
            desc = false;
        } else {
            asc = false;
        }
    }
    if (asc) {
        cout << "ascending\n";
    } else if (desc) {
        cout << "descending\n";
    } else {
        cout << "mixed\n";
    }
    return 0;
}
