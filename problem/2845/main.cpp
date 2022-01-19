#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short L, P;
    cin >> L >> P;
    short people = L * P;
    int num;
    cin >> num;
    cout << num - people;
    for (int i = 1; i < 5; i++) {
        cin >> num;
        cout << " " << num - people;
    }
    cout << "\n";
    return 0;
}
