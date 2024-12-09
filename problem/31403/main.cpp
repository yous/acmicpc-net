#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short A, B, C;
    cin >> A >> B >> C;
    cout << A + B - C << "\n";
    cout << stoi(to_string(A) + to_string(B)) - C << "\n";
    return 0;
}
