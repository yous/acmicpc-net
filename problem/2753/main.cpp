#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int year;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> year;
    if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) {
        cout << "1\n";
    } else {
        cout << "0\n";
    }
    return 0;
}
